#programma per la lettura multipla dei dati e la memorizzazione dentro un vettore

#la funzione input carica dati solo sotto forma di stringhe
x = input("dammi una sequenza di numeri ")
#stampo
print(x)
#per dimostrare che x è una stringa usiamo la funzione embedded type che ci dice che tipo di variabile è
print(type(x))# come possiamo notare questo dimostra quanto detto

# il metodo split della classe str consente di spezzare la stringa in enne parti...per default il delimitatore è lo spazio
#il metodo consente anche di scegliere il delimitare, per esempio la virgola, quindi puoi "leggere i csv"

x = x.split()
print(x)#per vedere l'effetto chefa
#per renderlo un vettore di numeri usiamo le funzioni map e list e float
y = list(map(float,x))
print(y)
print(type(y))
for a in y:
    print(a*3)

#giusto per completezza testiamo la lettura di un file csv comma-separator-value
#usiamo la funzione open per aprire il file
documento = open("pino.csv")
dati = documento.read() #leggo tutto quello che c'è nel file e diventa una stringa
dati = dati.split(",")#specifichiamo il tipo di separatore, in questo caso la virgola
#come sopre
listadati = list(map(float, dati))
print(listadati)
for a in listadati:
    print (a)
