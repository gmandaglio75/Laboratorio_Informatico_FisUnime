#Opzionale: Scrivere uno script python capace di leggere
#la seconda colonna del file bgo.dat, e di stampare a schermo
#il suo contenuto moltiplicato per 100.
import numpy as np
pino = np.loadtxt("bgo.dat", dtype='float',  delimiter=None)
print(pino) #stampo tutta la tabella
#print(pino[:,1])#tecnica dello slicing affettamento, affetto la seconda riga
gino = pino[:,1]
for a in gino:
    print(a*100)
