voti = input("dammi i voti che hai preso")
listavoti = voti.split()
print(len(listavoti))#la funzione len vi dice quanti elementi ha un vettore
somma =0
for a in listavoti:
    somma = somma + float(a)
print("la mia media vale = ", somma/len(listavoti))

