#lo script utilizzate un qualunque editor di testo non strutturato (no word)
#estensione dello script .py  
#uso il cancelletto per fare i commenti
#uso print per stampare a schermo...è come il cout ma lavora come una funzione
# al posto dei << abbiamo delle virgole
a = "mi pythonizzo"#nota non sto dichiarando il tipo di variabile
print(a)#stampo a schermo
#equivalente del cin è input
b = input("messaggio...dammi un numero ")# input restiuisce ciò che scrivi a schermo
print(b)
#per fare un cin a input multiplo, ma nel quale gli diciamo che variabile deve prendere
#per default senza map, usando solo input e split lui carica parole (stringhe" non numeri
#li sovrascrive
#nota che stiamo implicitamente ridefinendo le variabili, c++ si sarebbe incazzato a bestia...massima elasticita'
a,b = map(float,input("inserisci due numeri separati da uno spazio").split())
print("il risultato della somma vale", a+b)

a,b = input("inserisci due numeri separati da uno spazio").split()
print("il risultato della somma vale", a+b)

