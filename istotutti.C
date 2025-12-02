{
  ifstream leggo("dati_new.dat"); //creo un oggetto capace di leggere
  if(leggo.is_open()){
    cout<<"sono capace di leggere il file"<<endl;
  }
   TH1F *histo[12];
   string nome ="histo_";
   for(int i=0; i<12; i++){

     histo[i]= new TH1F((nome+to_string(i)).c_str(),"",100,0,0);
   }
   double a;
   int k=0;
   while(leggo>>a){
    histo[k]->Fill(a); //carico i dati dalla colonna k
     k++;
     if(k==12) k=0;
   }
            for(int i =0; i<12; i++){
	    double temp = 0;
	    while(fabs(histo[i]->GetRMS()-temp)>5){
		    temp =histo[i]->GetRMS();
      histo[i]->GetXaxis()->SetRangeUser(histo[i]->GetMean()-histo[i]->GetRMS(),histo[i]->GetMean()+histo[i]->GetRMS());
             cout<<i<<"  "<<fabs(histo[i]->GetRMS()-temp)<<"  "<<histo[i]->GetRMS() <<endl;
	    }

	    }
   TH1F *histozoom[12];
   nome ="histoz_";
   for(int i=0; i<12; i++){
     double RMS = histo[i]->GetRMS();
     if(RMS==0) RMS = 1;
     histozoom[i]= new TH1F((nome+to_string(i)).c_str(),"",100,histo[i]->GetMean()-3*RMS,histo[i]->GetMean()+3*RMS);
   }


	    leggo.close();
	    leggo.open("dati_new.dat");

    k=0;
   while(leggo>>a){
    histozoom[k]->Fill(a); //carico i dati dalla colonna k
     k++;
     if(k==12) k=0;
   }
  // }

   TCanvas *box = new TCanvas("box","",1200,800);
   box->Divide(4,3); //dividiamo lo scatolone in 12 4 x 3
   for(int i=0; i<12; i++){
      box->cd(i+1); //mi sposto nei sottosettori
      histozoom[i]->Draw();

   }




}
