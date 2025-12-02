import numpy as np
def funz(x):
    return  np.exp(x+np.log(1+x))
low = 0.
high = 1.
interval = high - low
ndiv = 100.
delta = interval/ndiv
centers = np.array(list(range(int(ndiv))))
centers = (low + delta/2)+centers*delta
addend = []
for a in centers:
    addend.append(funz(a))
    print(addend)
print("integrale vale ", sum(addend)*delta)
    
