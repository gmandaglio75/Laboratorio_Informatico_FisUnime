import ROOT
import numpy as np


generatore = ROOT.TRandom3(0)

scatola =[] 

for x in range(1000):
    scatola.append([generatore.Gaus(3,1),generatore.Gaus(2.4,0.7),generatore.Gaus(4,1)])
#tabella = np.array(scatola) non è necessario a meno che non vuoi usare metodi di numpy per manipolare la tabella
np.savetxt("daterelli.dat",scatola, fmt='%6.4f', delimiter='  ', newline='\n', header='', footer=' ', comments=' ', encoding=None)
            
            
#In questo esempio, la funzione genera_scatola_gaussiana utilizza la classe TRandom3 per generare numeri casuali secondo una distribuzione gaussiana.
