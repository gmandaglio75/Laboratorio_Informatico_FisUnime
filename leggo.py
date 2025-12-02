import ROOT
pino = ROOT.TH1F("pino","",100,0,0)
f =open("/home/gmandaglio75/MeD2223/dati/gaus.dat","r")
stringami = f.read()
strippami = stringami.split()
datami = list(map(float,strippami))
for a in datami:
    pino.Fill(a)
pino.Draw()
import numpy as np
dataminp = np.array(datami)
dataminp.sort(kind ='quicksort')
print("il minimo assoluto è = ", dataminp[0])
print("il massimo assoluto è = ", dataminp[dataminp.size -1])
