



void draw () {

  TRandom3 *r3 = new TRandom3();
  
  
  int n = 20;
  double x[n], y[n], ex[n], ey[n];
  for (int i=0;i<n;i++) {
    x[i] = (i+1)*0.1;
    y[i] = 10*x[i] + r3->Gaus(0,1);
    ex[i] = 0;
    ey[i] = 3;
  }
  TGraphErrors* gr = new TGraphErrors(n,x,y, ex, ey);
  gr->SetTitle("Titolo");
  gr->SetMarkerSize(2);
  gr->SetMarkerStyle(20);
  
  gr->GetXaxis()->SetTitle("position [cm]");
  gr->GetYaxis()->SetTitle("measured position [cm]");
  
  gr->Draw("AP");
  

  TF1 *f1 = new TF1("f1", "[0]+[1]*x", 0, 3);  
  gr->Fit("f1");
  
  
  
}


