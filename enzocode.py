import numpy as np
dati = np.loadtxt("dati_new.dat",dtype='float')
import ROOT
box =ROOT.TCanvas("box","",800,600)
box.Divide(4,3)
hist = [] #creo una lista...come se fosse un vector super flessibile
label = "hist"
for enzo in range(12):
    hist.append(ROOT.TH1F(label+str(enzo),"",100,0,0))
for enzo in range(12):
#    print("stampo la colonna ",enzo)
    for roby in dati[:,enzo]:
        hist[enzo].Fill(roby)

faile = ROOT.TFile("istogrammelli.root","recreate")
for enzo in range(12):
    box.cd(enzo+1)#scorre tra le sotto-scatole partendo da 1 e non da zero
    hist[enzo].Draw()
#per spiegare il ruolo di label
    print(hist[enzo].GetName())
    hist[enzo].Write()
faile.Close()

