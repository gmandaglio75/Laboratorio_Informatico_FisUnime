//12 scatole usando la classe TCanvas e mettere in ogni scatola l'istogramma relativo a ognuno di quelle colonne
/*
 * Tcanvas *pino= new TCanvas("pino","",600,500);
 * da questo momento in poi regna pino, appena ne crei un altro, ad esempio
 * TCanvas *gina= new TCanvas("gina","",600,500);
 * da questo momento in poi regna gina
 * per ripassare a pino->cd();
 *
 * for(int K=0; K<12; K++) pippo[K]=new TCanvas(Form("pino%i",K),"",300,600); */
{
TH1F *ciccio[12];//12 contenitori vuoti
for(int i=0; i<12; i++){
ciccio[i]= new TH1F(Form("ciccio%i",i),"",100, 0,0 );//ciccio non pino e poi non usavi il costruttore giusto!!!!!!
}// mi genera 12 contenitori di indirizzi
TCanvas *box[12]; //ti sei scordata di prenotare il vettore di scatole
 for(int i=0; i<12; i++){
box[i]= new TCanvas(Form("box%i",i),"",800,500);
} //mi genera 12 scatole
//ifstream leggimi("/home/studente/Downloads/dati_new.dat");
ifstream leggimi("./dati/dati_new.dat");//perchè funzioni sul mio pc
  if(leggimi.is_open()){
	cout<<"noice, ho letto il file"<<endl;
 } else{
   cout<<"non lo trovo"<<endl;
	 return ;//nella macro basta return non è una funzione
	 }
  float pino;
  int cambiocolonna = 0;
   while(leggimi>>pino) {
     //ciccio->Fill(pino); //AAAAAAAAAAAAhhhhh cicco è un vettore!!!!!;P
     ciccio[cambiocolonna]->Fill(pino);
     if(cambiocolonna==11)cambiocolonna=-1;//finita la riga riazzero il contatore
     cambiocolonna++; //mi consente di passare da un istogramma all'altro
   }

  for(int i=0; i<12; i++){
	   box[i]->cd(); //cambio scatola
	   //histo[i]->Draw();Li hai chiamati ciccio non histo
     ciccio[i]->Draw();
   }


  }
