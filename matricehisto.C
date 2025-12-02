{
	ifstream leggo("daterellicutted.dat");
	if(!leggo.is_open()){
		cout<<"non trovo il file"<<endl;
		return 1;
	}
	//prima dobbiamo creare la tabella per farlo dobbiamo sapere quante righe ci sono
	float a;
	int contami=0;
	while(leggo>>a) contami++; //maleducatamente non metto le graffe...pace

	int righe = contami/3;
	float **tabella = new float*[3];
	for(int i =0; i<3; i++){
		//notiamo che la definizione di chi è riga chi colonna è convenzionale...
		tabella[i] = new float[righe]; //in questo modo il primo indice indica le colonne il secondo le righe
	}
        leggo.close();
	leggo.open("daterellicutted.dat");
	for(int i=0; i<righe; i++){
		for(int j=0; j<3;j++){
		leggo>>tabella[j][i]; //j colonna i riga
		}
	}
//vogliamo calcolare l'istogramma della seconda colonna
       TH1F *histos[3]; //prenoto 3 puntatori a istogramma...histos è un puntatore doppio a TH1F
       for(int i=0; i<3; i++){
       	histos[i] = new TH1F(Form("histo%d",i),"",10,0,0);
	//histos[i] = new TH1F("histos","",10,0,0);
       }


       //filliamo gli istogrammi
        for(int i=0; i<righe; i++){
                for(int j=0; j<3;j++){
                histos[j]->Fill(tabella[j][i]);
                }
        }
	TCanvas pino;
	histos[0]->Draw();
	TCanvas pina;
	histos[1]->Draw();
	TCanvas pini;
	histos[2]->Draw();
	TFile peppino("istogrammi.root","recreate");
	for(int i =0; i<3; i++){
	histos[i]->Write();
	}
}
