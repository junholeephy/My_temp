import ctypes
ll = ctypes.cdll.LoadLibrary
lib = ll("./libn17_python_c.so")
tt = lib.adding(1, 3)
#print tt
print lib.adding(2,4)
print "finished"
