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


####################################### SELF SETTING !!!!! 

#data = TFile.Open('/Users/leejunho/Desktop/tensorflow/input_TTZ_DelphesEvalGen_5275k.root')
#data = TFile.Open("/Users/leejunho/Desktop/git/python3Env/group_study/project_pre/data_txt/BEIJING_Aqi/Aqi_Beijing_day_tree_cut.root")
#data = TFile.Open("/Users/leejunho/Desktop/git/python3Env/group_study/project_pre/data_txt/BEIJING_Aqi/Aqi_Beijing_day_re_tree_cut.root")
data = TFile.Open("../output_file/Outfile_delphes.root")
tree = data.Get('tree')


upper_limit = 7000   # 1000


EPOCHS = 400
#NODENUM = 128
NODENUM = 100
BATCH_SIZE_train = 10  # 500
BATCH_SIZE_test = 1  # 1
OPTIMIZER = 'adam'  #'adam', 'Adamax', 'adagrad', 'sgd', 'adadelta', 'RMSprop', 'Nadam', 'TFOptimizer'
KERNAL_INIT = 'he_uniform'  #truncated_normal, glorot_uniform, random_uniform, he_uniform, he_normal
L2 = 1e-5  #1e-5
DROP_RATE = 0.0  # 0.2
MAXNORM = 10000000 #5
ACTIVATION = "relu"

LOAD_WEIGHTS = False   #True #False

###############################################################################################################



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

data_train = ARRAY[0:upper_limit]
target_train = b_TARGET[0:upper_limit]
data_test = ARRAY[(upper_limit+1):ARRAY.shape[0]]
target_test = b_TARGET[(upper_limit+1):ARRAY.shape[0]]


ijkl = 0
modelRegress = Sequential()
#modelRegress.add(Dropout(DROP_RATE, input_shape=(ndim,)))
#modelRegress.add(Dense(NODENUM, kernel_initializer=KERNAL_INIT, activation=ACTIVATION, W_regularizer=l2(L2), kernel_constraint=maxnorm(3))) 
modelRegress.add(Dense(NODENUM, kernel_initializer=KERNAL_INIT, activation=ACTIVATION, W_regularizer=l2(L2), input_dim=ndim, kernel_constraint=maxnorm(MAXNORM)))
#modelRegress.add(BatchNormalization())
#modelRegress.add(Activation(ACTIVATION))
modelRegress.add(Dropout(DROP_RATE))
ijkl = ijkl + 1


modelRegress.add(Dense(NODENUM, kernel_initializer=KERNAL_INIT, activation=ACTIVATION, W_regularizer=l2(L2),kernel_constraint=maxnorm(MAXNORM)))
modelRegress.add(Dropout(DROP_RATE))
ijkl = ijkl + 1



modelRegress.add(Dense(NODENUM, kernel_initializer=KERNAL_INIT, activation=ACTIVATION, W_regularizer=l2(L2)))  #additional layer
modelRegress.add(Dropout(DROP_RATE))
ijkl = ijkl + 1

modelRegress.add(Dense(NODENUM, kernel_initializer=KERNAL_INIT, activation=ACTIVATION, W_regularizer=l2(L2)))  #additional layer
modelRegress.add(Dropout(DROP_RATE))
ijkl = ijkl + 1

modelRegress.add(Dense(NODENUM, kernel_initializer=KERNAL_INIT, activation=ACTIVATION, W_regularizer=l2(L2)))  #additional layer
modelRegress.add(Dropout(DROP_RATE))
ijkl = ijkl + 1



modelRegress.add(Dense(1, kernel_initializer=KERNAL_INIT,  activation='linear')) #sigmoid
modelRegress.compile(loss='mean_squared_error', optimizer=OPTIMIZER)
if(LOAD_WEIGHTS == True):  modelRegress.load_weights(LOAD_MODEL_WEIGHTS,by_name=True)
modelRegress.summary()
history_callback = modelRegress.fit(data_train, target_train, validation_data=(data_test, target_test), epochs=EPOCHS, batch_size=BATCH_SIZE_train)


predict_train = modelRegress.predict(data_train, batch_size=BATCH_SIZE_test)
predict_test = modelRegress.predict(data_test, batch_size=BATCH_SIZE_test)

f = TFile("self_tree_EN"+str(upper_limit)+"_LN"+str(ijkl)+"_E"+str(EPOCHS)+"_NN"+str(NODENUM)+"_B"+str(BATCH_SIZE_train)+"_"+str(OPTIMIZER)+"_L"+str(L2)+"_DR"+str(DROP_RATE)+".root", "recreate")


hist_target_train = TH1F('TrainData','TrainData',100,-3.5,3.5)
hist_target_test = TH1F('TestData','TestData',100,-3.5,3.5)
hist_output_train = TH1F('OutputDataTrain','OutputDataTrain',100,-3.5,3.5)
hist_output_test = TH1F('OutputDataTest','OutputDataTest',100,-3.5,3.5)

tree_train = TTree('tree_train','tree_train')
Ttrain = np.zeros(1, dtype=float)
Otrain = np.zeros(1, dtype=float)
tree_train.Branch('target_train',Ttrain,'target_train/D')
tree_train.Branch('output_train',Otrain,'output_train/D')
for ij1 in range(upper_limit):
	Ttrain[0] = target_train[ij1] 
	Otrain[0] = predict_train[ij1]		
	tree_train.Fill()

tree_test = TTree('tree_test','tree_test')
Ttest = np.zeros(1, dtype=float)
Otest = np.zeros(1, dtype=float)
tree_test.Branch('target_test',Ttest,'target_test/D')
tree_test.Branch('output_test',Otest,'output_test/D')
for ij2 in range(ARRAY.shape[0]-upper_limit-1):
	Ttest[0] = target_test[ij2]
	Otest[0] = predict_test[ij2]
	tree_test.Fill()


#Plots: projection selon l'axe X (premiere variable)
fill_hist(hist_target_train, target_train)
fill_hist(hist_target_test, target_test)
fill_hist(hist_output_train, predict_train[:,0])
fill_hist(hist_output_test, predict_test[:,0])

f.Write()
f.Close()

