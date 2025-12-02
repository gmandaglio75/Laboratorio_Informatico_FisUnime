domanda = "si"
while domanda == "si" :
    print("ciao sono un programma che calcola somma e sottrazione")
    a=input("vuoi fare una somma o una sottrazione?")
    while a != "sottrazione" and a !="somma" :
        print("che cavolo hai detto non ho capito!")
        a = input("ti ho detto vuoi fare una somma o una sottrazione?")
    pino = input("dammi un numero ")
    pina = input("dammene un'altro")
    if a == "somma":
        print("sono entrato dentro l'if della somma")
        print("stampo cavolate per vedere se funziona")
        print("gigi non mi crede proprio mai")
        print("la somma dei numeri che mi hai dato vale ",float(pino)+float(pina))
    print("sono uscito dall'if...mi stamperà in ogni caso")

    if a == "sottrazione":
        print("la differenza dei numeri che mi hai dato vale ",float(pino)-float(pina))
    domanda = input("vuoi fare un altro calcolo?")
print("ciao è stato un piacere")    
