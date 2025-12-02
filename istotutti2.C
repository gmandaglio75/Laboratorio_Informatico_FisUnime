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
   TCanvas *box = new TCanvas("box","",1200,800);
   box->Divide(4,3); //dividiamo lo scatolone in 12 4 x 3
   for(int i=0; i<12; i++){
      box->cd(i+1); //mi sposto nei sottosettori
      histo[i]->Draw();

   }

   TH1F *histozoom[12];
   nome ="histozoom_";
   for(int i=0; i<12; i++){

     histozoom[i]= new TH1F((nome+to_string(i)).c_str(),"",100,histo[i]->GetMean()-3*histo[i]->GetRMS(),histo[i]->GetMean()+3*histo[i]->GetRMS());
   }


   leggo.close();
   leggo.open("dati_new.dat");
   k=0;
   while(leggo>>a){
    histozoom[k]->Fill(a); //carico i dati dalla colonna k
     k++;
     if(k==12) k=0;
   }
   TCanvas *box2 = new TCanvas("box2","",1200,800);
   box2->Divide(4,3); //dividiamo lo scatolone in 12 4 x 3
   for(int i=0; i<12; i++){
      box2->cd(i+1); //mi sposto nei sottosettori
      histozoom[i]->Draw();

   }


   TH1F *histozoom2[12];
   nome ="histozoom2_";
   for(int i=0; i<12; i++){

     histozoom2[i]= new TH1F((nome+to_string(i)).c_str(),"",100,histozoom[i]->GetMean()-3*histozoom[i]->GetRMS(),histozoom[i]->GetMean()+3*histozoom[i]->GetRMS());
   }


   leggo.close();
   leggo.open("dati_new.dat");
   k=0;
   while(leggo>>a){
    histozoom2[k]->Fill(a); //carico i dati dalla colonna k
     k++;
     if(k==12) k=0;
   }
   TCanvas *box3 = new TCanvas("box3","",1200,800);
   box3->Divide(4,3); //dividiamo lo scatolone in 12 4 x 3
   for(int i=0; i<12; i++){
      box3->cd(i+1); //mi sposto nei sottosettori
      histozoom2[i]->Draw();

   }





}
