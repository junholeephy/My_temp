##!/usr/bin/env python
import os, sys
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import tensorflow as tf
import keras.backend as K
import math

from ROOT import TFile, TTree, TCut, TH1F
from subprocess import call
from os.path import isfile
from array import array

from root_numpy import fill_hist
from root_numpy import root2array, tree2array, array2root
from root_numpy import testdata

from keras import callbacks
from keras.models import Sequential
from keras.layers import Input
from keras.layers.core import Dense, Activation, Dropout
from keras.layers import BatchNormalization
from keras.regularizers import l1, l2
from keras import initializers
from keras import layers
from keras.optimizers import SGD, Adam
from keras.constraints import maxnorm



def DNN_RUN(filename,Epochs=100, ROTATION=4, LAYER_NUM=2, Node_num=100, Train_Batch=50):
    ####################################### SELF SETTING !!!!! 
    if(filename[0]=="/"):
        filename = filename
    elif(filename[0] == '~'):
        filename = filename.replace("~",os.environ['HOME'])
    elif((filename[0]=="C")&(filename[1]==":")):
        filename = filename
    else:
        filename = os.getcwd() + "/" + filename   # get the path included filename
    loca=len(filename)
    for i in range (1,len(filename)+1):       # find the "/" location
        if(filename[-i] == "/"):
            loca = i-1
            break

    FILENAME = filename.replace(filename[:-loca],"")   # this is the shorten filename
    filename_No_Txt = FILENAME.replace(".txt","")
    infile = filename

    data = TFile.Open(infile)
    dirlist = data.GetListOfKeys()
    ITER = dirlist.MakeIterator()
    key = ITER.Next()
    TREE_NAME = (key.ReadObj()).GetName(); #print(TREE_NAME)
    tree = data.Get(TREE_NAME)
    TOT_ENTRY = tree.GetEntries()
    UPPER_LIMIT = int(TOT_ENTRY*float(ROTATION-1)/float(ROTATION))
    upper_limit = UPPER_LIMIT   # 1000

    EPOCHS = Epochs
    #NODENUM = 128
    NODENUM = Node_num
    BATCH_SIZE_train = Train_Batch  # 500
    BATCH_SIZE_test = 1  # 1
    OPTIMIZER = 'adam'  #'adam', 'Adamax', 'adagrad', 'sgd', 'adadelta', 'RMSprop', 'Nadam', 'TFOptimizer'
    KERNAL_INIT = 'he_uniform'  #truncated_normal, glorot_uniform, random_uniform, he_uniform, he_normal
    L2 = 1e-5  #1e-5
    DROP_RATE = 0.0  # 0.2
    MAXNORM = 10000000 #5
    ACTIVATION = "relu"



    ####################################### Input DATA Sets !!!!! 
    b_reco_lep1Pt_   = tree2array(tree,branches="reco_lep1Pt")
    b_reco_lep1Eta_  = tree2array(tree,branches="reco_lep1Eta")
    b_reco_lep1Phi_  = tree2array(tree,branches="reco_lep1Phi")
    b_reco_lep2Pt_   = tree2array(tree,branches="reco_lep2Pt")
    b_reco_lep2Eta_  = tree2array(tree,branches="reco_lep2Eta")
    b_reco_lep2Phi_  = tree2array(tree,branches="reco_lep2Phi")
    b_reco_MET_et_   = tree2array(tree,branches="reco_MET_et")
    b_reco_MET_phi_  = tree2array(tree,branches="reco_MET_phi")

    ###############################################################################################################
    ##################################### Target DATA !!!!!
    b_TARGET_   = tree2array(tree,branches="gen_Nu_phi1")
    ###############################################################################################################


    ##################################### Pick valid Input/Target DATA  (TARGET is output data) !!!!!
    b_reco_lep1Pt   = np.zeros(b_reco_lep1Pt_.size)
    b_reco_lep1Eta  = np.zeros(b_reco_lep1Eta_.size)
    b_reco_lep1Phi  = np.zeros(b_reco_lep1Phi_.size)
    b_reco_lep2Pt   = np.zeros(b_reco_lep2Pt_.size)
    b_reco_lep2Eta  = np.zeros(b_reco_lep2Eta_.size)
    b_reco_lep2Phi  = np.zeros(b_reco_lep2Phi_.size)
    b_reco_MET_et   = np.zeros(b_reco_MET_et_.size)
    b_reco_MET_phi  = np.zeros(b_reco_MET_phi_.size)
    b_TARGET     = np.zeros(b_TARGET_.size)

    for i in range(b_TARGET.size):
        b_reco_lep1Pt[i]  = b_reco_lep1Pt_[i]
        b_reco_lep1Eta[i] = b_reco_lep1Eta_[i]
        b_reco_lep1Phi[i] = b_reco_lep1Phi_[i]
        b_reco_lep2Pt[i]  = b_reco_lep2Pt_[i]
        b_reco_lep2Eta[i] = b_reco_lep2Eta_[i]
        b_reco_lep2Phi[i] = b_reco_lep2Phi_[i]
        b_reco_MET_et[i]  = b_reco_MET_et_[i]
        b_reco_MET_phi[i] = b_reco_MET_phi_[i]
        b_TARGET[i] = b_TARGET_[i]

    ###############################################################################################################



    ##################################### ARRAY is input DATA !!!!!
    ARRAY = np.stack((b_reco_lep1Pt, b_reco_lep1Eta, b_reco_lep1Phi, b_reco_lep2Pt, b_reco_lep2Eta, b_reco_lep2Phi, b_reco_MET_et, b_reco_MET_phi))

    print(ARRAY.shape)
    ARRAY = ARRAY.T
    print(ARRAY.shape)
    print(ARRAY[:2])
    print(b_TARGET[:2])
    ###############################################################################################################


    ndim = ARRAY.shape[1]  
    nEvents = ARRAY.shape[0]

    rotation = 0
    for i in range(ROTATION):
#        print("This is ",i+1,"th rotation, Of total", ROTATION)
        rotation = rotation+1
        if(rotation == 1):
            LOAD_WEIGHTS = False
        if(rotation != 1):
            LOAD_WEIGHTS = True

        if(rotation == 1):
            data_Temp_train = ARRAY[0:upper_limit]
            target_Temp_train = b_TARGET[0:upper_limit]
            data_Temp_test = ARRAY[(upper_limit+1):ARRAY.shape[0]]
            target_Temp_test = b_TARGET[(upper_limit+1):ARRAY.shape[0]]
        elif(rotation == ROTATION):
            data_Temp_train = ARRAY[int(TOT_ENTRY/float(ROTATION))+1:TOT_ENTRY]
            target_Temp_train = b_TARGET[int(TOT_ENTRY/float(ROTATION))+1:TOT_ENTRY]
            data_Temp_test = ARRAY[0:int(TOT_ENTRY/float(ROTATION))]
            target_Temp_test = b_TARGET[0:int(TOT_ENTRY/float(ROTATION))]
        else:
            INIT1 = 0;  END1 = TOT_ENTRY - int(TOT_ENTRY/float(ROTATION))*(rotation)
            INIT2 = TOT_ENTRY - int(TOT_ENTRY/float(ROTATION))*(rotation-1); END2 = TOT_ENTRY
            data_Temp_train1 = ARRAY[INIT1:END1];   target_Temp_train1 = b_TARGET[INIT1:END1]
            data_Temp_train2 = ARRAY[INIT2+1:END2];   target_Temp_train2 = b_TARGET[INIT2+1:END2]
            data_Temp_test = ARRAY[END1+1:INIT2]
            target_Temp_test = b_TARGET[END1+1:INIT2]

            data_Temp_train = np.concatenate((data_Temp_train1,data_Temp_train2),axis=0)
            target_Temp_train = np.concatenate((target_Temp_train1,target_Temp_train2),axis=0)

        data_train = data_Temp_train
        target_train = target_Temp_train
        data_test = data_Temp_test
        target_test = target_Temp_test

        ijkl = 0
        modelRegress = Sequential()
        #modelRegress.add(Dropout(DROP_RATE, input_shape=(ndim,)))
        #modelRegress.add(Dense(NODENUM, kernel_initializer=KERNAL_INIT, activation=ACTIVATION, W_regularizer=l2(L2), kernel_constraint=maxnorm(3))) 
        modelRegress.add(Dense(NODENUM, kernel_initializer=KERNAL_INIT, activation=ACTIVATION, W_regularizer=l2(L2), input_dim=ndim, kernel_constraint=maxnorm(MAXNORM)))
        #modelRegress.add(BatchNormalization())
        #modelRegress.add(Activation(ACTIVATION))
        modelRegress.add(Dropout(DROP_RATE))
        ijkl = ijkl + 1


        if(LAYER_NUM>=2):
            modelRegress.add(Dense(NODENUM, kernel_initializer=KERNAL_INIT, activation=ACTIVATION, W_regularizer=l2(L2),kernel_constraint=maxnorm(MAXNORM)))
            modelRegress.add(Dropout(DROP_RATE))
            ijkl = ijkl + 1
        if(LAYER_NUM>=3):
            modelRegress.add(Dense(NODENUM, kernel_initializer=KERNAL_INIT, activation=ACTIVATION, W_regularizer=l2(L2)))  #additional layer
            modelRegress.add(Dropout(DROP_RATE))
            ijkl = ijkl + 1
        if(LAYER_NUM>=4):
            modelRegress.add(Dense(NODENUM, kernel_initializer=KERNAL_INIT, activation=ACTIVATION, W_regularizer=l2(L2)))  #additional layer
            modelRegress.add(Dropout(DROP_RATE))
            ijkl = ijkl + 1
        if(LAYER_NUM>=5):
            modelRegress.add(Dense(NODENUM, kernel_initializer=KERNAL_INIT, activation=ACTIVATION, W_regularizer=l2(L2)))  #additional layer
            modelRegress.add(Dropout(DROP_RATE))
            ijkl = ijkl + 1


        modelRegress.add(Dense(1, kernel_initializer=KERNAL_INIT,  activation='linear')) #sigmoid
        modelRegress.compile(loss='mean_squared_error', optimizer=OPTIMIZER)
        if(LOAD_WEIGHTS == True):
            LOAD_MODEL_WEIGHTS = "MODELs/Model_EN"+str(upper_limit)+"_LN"+str(ijkl)+"_E"+str(EPOCHS)+"_M"+str(rotation-1)+".h5"
            modelRegress.load_weights(LOAD_MODEL_WEIGHTS,by_name=True)
            print("************************************ MODEL LOADED ************************************")
        modelRegress.summary()
        print("************************************ This is ",i+1,"th rotation, Of total", ROTATION,"************************************")
        history_callback = modelRegress.fit(data_train, target_train, validation_data=(data_test, target_test), epochs=EPOCHS, batch_size=BATCH_SIZE_train)

        predict_train = modelRegress.predict(data_train, batch_size=BATCH_SIZE_test)
        predict_test = modelRegress.predict(data_test, batch_size=BATCH_SIZE_test)

        modelRegress.save_weights("MODELs/Model_EN"+str(upper_limit)+"_LN"+str(ijkl)+"_E"+str(EPOCHS)+"_M"+str(rotation)+".h5")



        if(rotation == ROTATION):
            f = TFile("Rotation_tree_EN"+str(upper_limit)+"_LN"+str(ijkl)+"_E"+str(EPOCHS)+"_NN"+str(NODENUM)+"_B"+str(BATCH_SIZE_train)+"_"+str(OPTIMIZER)+"_L"+str(L2)+"_DR"+str(DROP_RATE)+".root", "recreate")
            hist_target_train = TH1F('TrainData','TrainData',20,-3.5,3.5)
            hist_target_test = TH1F('TestData','TestData',20,-3.5,3.5)
            hist_output_train = TH1F('OutputDataTrain','OutputDataTrain',20,-3.5,3.5)
            hist_output_test = TH1F('OutputDataTest','OutputDataTest',20,-3.5,3.5)

            tree_train = TTree('tree_train','tree_train')
            Ttrain = np.zeros(1, dtype=float)
            Otrain = np.zeros(1, dtype=float)
            tree_train.Branch('target_train',Ttrain,'target_train/D')
            tree_train.Branch('output_train',Otrain,'output_train/D')
            for ij1 in range(upper_limit-2):
                Ttrain[0] = target_train[ij1]
                Otrain[0] = predict_train[ij1]
                tree_train.Fill()

            tree_test = TTree('tree_test','tree_test')
            Ttest = np.zeros(1, dtype=float)
            Otest = np.zeros(1, dtype=float)
            tree_test.Branch('target_test',Ttest,'target_test/D')
            tree_test.Branch('output_test',Otest,'output_test/D')
            for ij2 in range(ARRAY.shape[0]-upper_limit-3):
                Ttest[0] = target_test[ij2]
                Otest[0] = predict_test[ij2]
                tree_test.Fill()

            fill_hist(hist_target_train, target_train)
            fill_hist(hist_target_test, target_test)
            fill_hist(hist_output_train, predict_train[:,0])
            fill_hist(hist_output_test, predict_test[:,0])
            f.Write()
            f.Close()


    CP_FNAME = "MODELs/Model_EN"+str(upper_limit)+"_LN"+str(ijkl)+"_E"+str(EPOCHS)+"_M"+str(ROTATION)+".h5"
    CP_TNAME = "MODELs/FINAL_EN"+str(upper_limit)+"_LN"+str(ijkl)+"_EP"+str(EPOCHS)+"_M"+str(ROTATION)+".h5"
    CP_FINAL_MODEL = "cp "+CP_FNAME +" " + CP_TNAME

    RM_COMMAND = "rm "
    RM_NAMES = "MODELs/Model_EN"+str(upper_limit)+"_LN"+str(ijkl)+"_E"+str(EPOCHS)+"_M"+"*"+".h5"
    RM_COMMAND = RM_COMMAND + RM_NAMES
    os.system(CP_FINAL_MODEL)
    os.system(RM_COMMAND)


def main():
    infilename = "../output_file/Outfile_delphes.root"
    DNN_RUN(filename=infilename,Epochs=100, ROTATION=3, LAYER_NUM=3, Node_num=100, Train_Batch=50 )


if __name__=="__main__":
    main()



