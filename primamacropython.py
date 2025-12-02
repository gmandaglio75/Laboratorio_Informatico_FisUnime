marco = 12
print("marco = ",marco)
import ROOT
funzione = ROOT.TF1("funzione","sin(x)/x",-10,10)
funzione.Draw()
#salvami = ROOT.TFile("contenitore.root","recreate")
salvami = ROOT.TFile("contenitore.root","create")
funzione.Write()
salvami.Close()
