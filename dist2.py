import numpy as np
import ROOT
from itertools import combinations
y = np.loadtxt("daterelli.dat")
a=list(combinations(y[:,], 2))
dist =[]
for pino in a:
    dist.append(np.linalg.norm(pino[0]-pino[1]))
dist.sort()
print("la distanza minima vale ",dist[0])
print("la distanza massima vale ",dist[len(dist)-1])
gigi = ROOT.TH1D("gigi","",100, 0,0)
for distanza in dist:
    gigi.Fill(distanza)
gigi.Draw()
