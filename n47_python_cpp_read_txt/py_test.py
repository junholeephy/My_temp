
import os

test_root = "root -l -q test.C" 
os.system(test_root)
test_root = "root -l -q test2.C"
os.system(test_root)

Input_txt = "/Users/leejunho/Desktop/git/python3Env/group_study/project_pre/data_txt/BEIJING_Aqi/Aqi_Beijing_Holi.txt"
#test_root = "root -l -q n4_ITEM_NUM_of_ROW.C\("+"'"+'"'+Input_txt+'"'+"'"+"\)"
test_root = "root -l -q c6_test.C\("+"'"+'"'+Input_txt+'"'+"'"+"\)"
#os.system(test_root)
T_root = os.popen(test_root)
Run_root = T_root.readlines()
#print(Run_root)
T_root.close()

Input_root = "/Users/leejunho/Desktop/git/python3Env/group_study/project_pre/data_txt/BEIJING_Aqi/Aqi_Beijing_day_re_tree_cut_hist2D.root"
twoD_plot_save = "root -l -q /Users/leejunho/Desktop/git/python3Env/group_study/fruit_team/ROOT/Project/functions/2Dplots_Saver/TwoD_Plot_Saver_default.C\("+"'"+'"'+Input_root+'"'+"'"+"\)"
os.system(twoD_plot_save)
os.system("mkdir 2D_defalut")
os.system("mv *defalut_2D.pdf 2D_defalut")


#os.system("ls *.C")
tt = os.popen("ls")
#print(tt)
#print(tt.read())
ls_out = tt.readlines()
print(ls_out)
tt.close()
#print(os.getcwd())

LONG_LS_OUT = []
for i in range(len(ls_out)):
    ls_out[i] = ls_out[i].replace(ls_out[i][-1],"")
    LONG_LS_OUT.append(os.getcwd() +"/"+ ls_out[i])

print(LONG_LS_OUT)
    

