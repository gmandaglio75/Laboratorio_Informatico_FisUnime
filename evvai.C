//creare un istogramma utilizzando i dati contenuti in dati2.dat della cartella dati2
{
  //                TH1F("come tichiami","titolo",numero di bin, estremo inferiore, estremo superiore);
   TH1F *histo[12]; //prenoto 12 contenutori di indirizzi (a questo livello sono vuoti solo prenotati)
   TCanvas *box[12];
  for(int j=0; j<12;j++){
    histo[j] = new TH1F(Form("histo%i",j),"",100,0,0);//mi genera 12 istogrammi
    box[j] = new TCanvas(Form("box%i",j),"",600,500);//mi genera 12 scatole
  }

    ifstream leggimi("./dati/dati_new.dat");
  if(leggimi.is_open()){
    cout<<"ho letto il file"<<endl;
  }
  else{
    cout<<"non trovo il file, percorso o nome sbagliato!!!"<<endl;
  }
  float pino;
  int contami =0;
  while(leggimi>>pino){//ciclo a ciascuono il suo!!!
            histo[contami]->Fill(pino); //il ciclo leggera i dati, che vengono passati uno a uno all'oggetto della classe attraverso il metodo Fill
         if(contami==11) contami =-1;
          contami++;
  }
  for(int j=0; j<12;j++){
    box[j]->cd(); //cambio scatola
    histo[j]->Draw();
  }

}
