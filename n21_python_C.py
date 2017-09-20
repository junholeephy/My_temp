import commands
import os
main = "root -l n21_python_C.C"
#if os.path.exists(main):
#	rc, out = commands.getstatusoutput(main)
#	print 'rc = %d, \n out = %s' %(rc, out)

print '*'*10
f = os.popen(main)
data = f.readlines()
f.close()
print data

print "*"*10


os.system(main)  # real excutable line
