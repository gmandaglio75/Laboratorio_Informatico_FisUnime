def Average(lst):
    return sum(lst) / len(lst)


nome = input("scrivimi il percorso dove posso trovare il file  ")
print (nome)
f = open(nome,"r")
stringami = f.read()
strippami = stringami.split()
datami = list(map(float,strippami))
print("il valore medio vale ", Average(datami))


