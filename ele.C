//2) Realizzare un grafico dei dati contenuti nel file bgo.dat. 
//Rappresentare il grafico, scrivere sull’asse delle x la label “canali”, sull’asse delle y la label “conteggi”, 
//salvare la figura in formato pdf.
//Profare a fittare localmente I due picchi presenti nei dati.

{ 
	/*TH1D *bongo = new TH1D("bongo","",15,0,0); 
 
  ifstream leggo("bgo.dat");
  
  if(!leggo.is_open()){
	  
	  cout<<"big fail"<<endl;//controlliamo se aggancia il file
	  
	  }
  //a variabile d'appoggio  
  double a;	  
 
  //utilizzo il metodo .eof() della classe ifstream. Ci dice se siamo arrivati alla fine
  while(!leggo.eof()){ 
	  
	  leggo>>a;//fin quando non siamo arrivati alla fine, carico i dati in a
	
	  if(!leggo.eof()){
		  
		  bongo ->Fill(a);
		  
		  }
	
	}
  bongo -> Draw();
  
  */
  
  //metodo più snello
  
  TGraph *bongo = new TGraph ("bgo.dat"); 
  
  //creiamo una scatoletta
  TCanvas *ciccia = new TCanvas("ciccia", "ciccia",1100,700);
  
  //fase di make-up
  
  bongo->SetTitle("");
  
  bongo->GetXaxis()->SetTitle("Canali");   //label asse x
  
  bongo->GetYaxis()->SetTitle("Conteggi"); //label asse y
  
  bongo->GetXaxis()->CenterTitle();
                                           //centriamo il nome degli assi
  bongo->GetYaxis()->CenterTitle();
  
  bongo->GetXaxis()->SetTitleSize(0.05);
  
  bongo->GetYaxis()->SetTitleSize(0.05);
  
  
  
 
  
  //Fittiamo i brufolini ai lati, notamo che il brufolone si trova tra 0 e 500 circa 
  //il brufolo medio invace tra 1500 e 2000
  
  TF1 *brufolazzo = new TF1("brufolazzo","gaus",0,350); //brufolone
  
  
  
  brufolazzo->SetLineColor(4);
  
  bongo->Fit("brufolazzo","R");
  
  TF1 *brufolino = new TF1("brufolino","gaus",1700,2300);//brufolino
  
 
  
  brufolino->SetLineColor(6);
  
  bongo->Fit("brufolino","R+");
 
  
 
  
  
   bongo->Draw();
  ciccia->SaveAs("SimEsa2_HISTO");
  
	
}
