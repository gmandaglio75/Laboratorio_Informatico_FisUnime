#integriamo con il metodo dei trapezzi
#usando la potenza di NumPy
import numpy as np
x = np.linspace(0,np.pi,1000)
y = np.sin(x)
Inl = np.trapz(y,x)
print("il risultato dell'integrale vale = ",Inl)
#vale lo stresso

print("il risultato dell'integrale vale = ",np.trapz(np.sin(x),x))
