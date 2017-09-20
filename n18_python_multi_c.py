import ctypes
ll = ctypes.cdll.LoadLibrary
lib = ll("./libn18.so")
lib.add(4,2)
lib.add(1,3)
lib.minus(4,2)
lib.minus(1,3)
print "finished"
