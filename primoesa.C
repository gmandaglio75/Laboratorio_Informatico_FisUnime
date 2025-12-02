//Scrivere un programma capace di leggere i dati nel file dati20210124_1.dat 
//e di calcolare la deviazione standard del campione. 
//Stampare a schermo il risultato del calcolo.
{
ifstream leggo("dati20210124_1.dat");
if(!leggo.is_open()){
cout<<"non trovo il file \n"<<endl;
return 1;
}
TH1F pino("pino","",100,0,0);//0,0 perchè non conosco gli estremi dell'istogramma
float a;//mi serve una variabile per effettuare la lettura
while(leggo>>a){
pino.Fill(a); //molto simile a push_back.....il metodo Fill passa il valore appena letto a pino
}
cout<<"ecco la media = " <<pino.GetMean() <<endl;

cout<<"ecco la deviazione standard = "<<pino.GetRMS()<<endl;


}

