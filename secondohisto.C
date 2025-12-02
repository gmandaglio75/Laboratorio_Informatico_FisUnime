//creare un istogramma utilizzando i dati contenuti in dati2.dat della cartella dati2
{
  //                TH1F("come tichiami","titolo",numero di bin, estremo inferiore, estremo superiore);
  TH1F *histo = new TH1F("histo","",100,0,0);
  ifstream leggimi("./dati/dati_new.dat");
  if(leggimi.is_open()){
    cout<<"ho letto il file"<<endl;
  }
  else{
    cout<<"non trovo il file, percorso o nome sbagliato!!!"<<endl;
  }
  float pino;
  int contami =0;
  while(leggimi>>pino){
     if(contami ==4 ){
       histo->Fill(pino); //il ciclo leggera i dati, che vengono passati uno a uno all'oggetto della classe attraverso il metodo Fill
        cout<<pino<<endl;
     }

     if(contami==11) contami =-1;
    contami++;
  }
  histo->Draw(); //il metodo Draw consente di visualizzare il risultato della computazione dell'istogramma
}
