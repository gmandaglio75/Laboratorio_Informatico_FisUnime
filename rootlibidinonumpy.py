import numpy as np
import ROOT
pino = np.loadtxt("./dati/dati_new.dat", dtype='float',  delimiter=None)
h = ROOT.TH1F("h","",100,0,0)
for a in pino[:,0]:   #per cambiare la colonna è sufficiente cambiare il secondo indice
    h.Fill(a)
h.Draw()
h.Fit("gaus")
