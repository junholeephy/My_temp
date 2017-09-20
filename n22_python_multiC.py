import commands 
import os
main1 = "root -l n22_python_multiC_1.C\(3\) n22_python_multiC_2.C"
main2 = "root n22_python_multiC_2.C"
main3 = ".q"
#i=0

#if os.path.exists(main1):
#	rc1, out1 = commands.getstatusoutput(main1)
#	i = i+1

#if os.path.exists(main2):
#	rc2, out2 = commands.getstatusoutput(main2)

os.system(main1)
#os.system(main3)
os.system(main2)
