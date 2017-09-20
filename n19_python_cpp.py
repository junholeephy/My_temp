import ctypes
so = ctypes.cdll.LoadLibrary
lib = so("./libn19.so")
lib.display1()
lib.display2(100) # at the cpp code, "2" was input so 100 is not used.
print "finished"
