



void draw () {

  TRandom3 *r3 = new TRandom3();
  
  
  TCanvas* cc1 = new TCanvas ("cc1", "", 800, 600);
  
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
  
  



  TCanvas* cc2 = new TCanvas ("cc2", "", 800, 600);

  TH1F* histo = new TH1F("histo", "", 100, 50 , 300);
  for (int i = 0; i < 1000; ++i) histo->Fill(r3->Gaus(150.,10.));
  for (int i = 0; i < 3000; ++i) histo->Fill(r3->Exp(100));
  
  histo->Draw();
  
  TF1 *f2 = new TF1("f2", "gaus", 100, 200);  
  f2->SetParameter(1, 150);
  f2->SetParameter(2, 10);
  
  histo->Fit("f2", "RMQ");
  
  
  
  
  
  
  
  
  TCanvas* cc3 = new TCanvas ("cc3", "", 800, 600);
  
  for (int i=0;i<n;i++) {
    x[i] = (i+1)*0.1;
    y[i] = 10*x[i] + r3->Gaus(0,1);
    ex[i] = 0.2;
    ey[i] = 0.9;
  }
  TGraphErrors* gr2 = new TGraphErrors(n,x,y, ex, ey);
  gr2->SetTitle("Titolo");
  gr2->SetMarkerSize(2);
  gr2->SetMarkerStyle(20);
  
  gr2->GetXaxis()->SetTitle("position [cm]");
  gr2->GetYaxis()->SetTitle("measured position [cm]");
  
  gr2->Draw("AP");
  
  
  gr2->Fit("f1");
  
  
  
  
  
  
  
  
  TCanvas* cc4 = new TCanvas ("cc4", "", 800, 600);
  
  int numexp = 5000;
  TH1F* histo2 = new TH1F("histo2", "", 100, 50 , 300);
  for (int i = 0; i < 1000; ++i) histo2->Fill(r3->Gaus(150.,10.));
  for (int i = 0; i < numexp; ++i) histo2->Fill(r3->Exp(100));
  for (int i = 0; i < 1500; ++i) histo2->Fill(r3->Gaus(90.,50.));
    
  
  histo2->Draw();
  
  TF1 *f3 = new TF1("f3", "gaus(0)+expo(3)", 50, 300);  
  //
  // gaus(0) is a substitute for [0]*exp(-0.5*((x-[1])/[2])**2) and (0) means start numbering parameters at 0. expo(3) is a substitute for exp([3]+[4]*x).
  //
  f3->SetParameter(0, 1000);
  f3->SetParameter(1, 150);
  f3->SetParameter(2, 10);
  f3->SetParameter(3, log(numexp));
//   f3->SetParameter(4, 100);
  
  histo2->Fit("f3", "RMQ");
  
  std::cout << " f3:: normalizzazione [0]       = " << fabs(f3->GetParameter(0)) << " +/- " << f3->GetParError(0) << std::endl;
//   std::cout << " f3:: normalizzazione gaussiana = " << fabs(f3->GetParameter(0)*sqrt(2*3.14159265)*f3->GetParameter(2)) << " +/- " << f3->GetParError(0)*sqrt(2*3.14159265)*f3->GetParameter(2) << std::endl;
  std::cout << " f3:: normalizzazione gaussiana = " << fabs(f3->GetParameter(0)*f3->GetParameter(2)) << " +/- " << f3->GetParError(0)*f3->GetParameter(2) << std::endl;
  std::cout << " f3:: mean gaussiana            = " << f3->GetParameter(1) << " +/- " << f3->GetParError(1) << std::endl;
  std::cout << " f3:: sigma gaussiana           = " << f3->GetParameter(2) << " +/- " << f3->GetParError(2) << std::endl;
  
  
  
  
  
}


