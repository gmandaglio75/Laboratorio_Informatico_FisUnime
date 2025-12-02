import numpy as np
data = np.loadtxt("dati2.dat")
import ROOT
pino = ROOT.TH1F("pino","",100,0,0)
#for a in data:
#    print(a)
#for (int i =0; i<data.size(); i++){
#       cout<<data[i]<<endl;
#}
#for b in 'banana':
#    print(b)
for a in data:
    pino.Fill(a)

pino.Draw()


