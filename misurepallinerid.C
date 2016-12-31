//macro root per analizzare dati raccolti nell'esperimento
//misura diametro palline corso di Laboratorio 1
//tutti i dati
{
   TH1F *pippo = new TH1F("pippo"," ",10,3.6,4);
   ifstream leggimi("Misure.dat");
   double a;
   while(!leggimi.eof()){
   leggimi>>a;
   if(!leggimi.eof()){
     pippo->Fill(a);
    }
    }

    pippo->Draw();
c1->SaveAs("grezzo.pdf");

}
