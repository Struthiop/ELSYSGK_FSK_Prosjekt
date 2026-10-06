import numpy as np

bits = [0,0,0,1,0,0,1,0, 1,0,1,0,0,0,1,0, 0,0,1,1,0,0,1,0]


for i in np.arange(0, len(bits), 8):
    byte = bits[i:i+8]
    byte.reverse()
    byte = (''.join(str(b) for b in byte))
    print(byte)
    print(int(byte, 2))
    print(chr(int(byte, 2)))
