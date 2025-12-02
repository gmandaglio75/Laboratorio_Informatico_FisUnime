#una serie di esempi di ciclo for
# funzione range range(start, stop, step)
for a in range(10):
    print(a)
print("**********************")
for a in range(0,10,2):
    print(a)

#quante volte vi chiedo di produrre una sequenza numerica
print("**********************")

#for a in range(0,10,0.01):#non va vuole gli interi
#    print(a)

#per i numeri ci vuole numpy
import numpy as np


for a in np.arange(0,10,0.01):
    print(a)


print("**********************")
pino = "non è bello ciò che bello ma che bello che bello che bello"

for pina in pino:
    print(pina)

print("**********************")
pinosplittato = pino.split()


for pina in pinosplittato:
    print(pina)
