import ROOT
generello = ROOT.TRandom3(0)#generello è l'oggetto della classe TRandom3 e abbiamo utilizzato il costruttore che prende come input il seme randomico
dataFile = open("dati.dat","w")
for a in range(0,1000):
    dataFile.write("%s  %s  %s \n" % (generello.Gaus(5,4),generello.Gaus(5,2),generello.Gaus(4,1)))
