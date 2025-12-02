import numpy as np
pino = np.loadtxt("./dati/dati_new.dat", dtype='float',  delimiter=None)
print(pino) #stampo tutta la tabella
print(pino[0,:])#tecnica dello slicing affettamento, affetto prima riga
print(pino[:,0])#affetto prima colonna
import ROOT
pino = ROOT.TH1F("pino","",100,0,10)
for a in pino[:,0]:
    pino.Fill(a)
pino.Draw()
