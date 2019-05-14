/*******************************************************************
This program is a templete macro for analysys.
Auther:APE members
*******************************************************************/

//My header
#include "../include/FitFunction.h"
#include "../include/MyRootMacro.h"

void tutorialAnalysis(string DatFileName,string DatDirPath,string OutDirPath){
  cout << "> Start tutorialAnalysis" <<endl;
  //Default figure setttinnng
  SetAllFigureStyle(right_top);

  //canvas
  string canvasName = "c1",canvasTitle = "c_title";
  const Int_t form = 5;
  TCanvas *c1 = new TCanvas(canvasName.c_str(),canvasTitle.c_str(),form);
  c1->SetGrid();

  //histgram and graph
  Double_t xlow = 100.,xup = 150.;
  Int_t nbins = 500;
  TH1D *hist = new TH1D("hist","title;Xtitle;Ytitle",nbins,xlow,xup);
  TGraphErrors *gr = MyGraphErr("title","x_label","y_label");
 
  //TTREE SET ADRESS
  Char_t *branch_name[] = {"f_gaus"};
  Float_t f_gaus;
  cout << "> rootfile PATH" << endl;
  cout << " + "<< DatDirPath + "/" +DatFileName + ".root" << endl;
  TFile *rootfile = new TFile(Form("%s/%s.root",DatDirPath.c_str(),DatFileName.c_str()), "READ");
  if (rootfile -> IsZombie()){
    cout << "  + Error Open File" << endl;
    exit(1);
  }
  TTree *tree = (TTree*)rootfile->Get("tree");
  tree -> SetBranchAddress(branch_name[0], &f_gaus);

  //variables of analysis part
  cout << "> Start main part" <<endl;
  Int_t loop = 0;
  Int_t entry = tree->GetEntries();
  Double_t f_min=100,f_max=150;

  //MAIN ANARYLYS
  while(loop < entry){
    tree->GetEntry(loop);
    hist->Fill(f_gaus);
    if(loop < 10){
      gr->SetPoint(loop,loop,f_gaus);
    }
    loop++;
  }

  //Fitting and Get parameter
  cout << "> Fitting" << endl;
  TF1 *func = _gaus(xlow,xup);
  const Int_t par_num = 5;
  Double_t fit_par[par_num]={},fit_par_err[par_num]={};
  const Int_t row = 2,column = 3;
  vector<Double_t> value[row][column];
  
  func->SetParameter("Mean",125.);
  func->SetParameter("Sigma",30.);
  hist->Fit(func,"hist","S",f_min,f_max);
  for(int i=0;i<row;i++){
    fit_par[i] = func -> GetParameter(i);
    fit_par_err[i] = func -> GetParError(i);
    value[i][0] = fit_par[i];
    value[i][1] = fit_par_err[i];
  }
  
  //Print
  cout << "> Print hist and graph" << endl;
  c1->Clear();
  hist->Draw();
  c1->Print(Form("%s/hist.pdf",OutDirPath.c_str()));
  gr->Draw("AP");
  c1->Print(Form("%s/graph.pdf",OutDirPath.c_str()));

  MakeFitResultFile(row,column,value,OutDirPath,"output.dat");

  //Result Rootfile
  TFile *ResultFile = new TFile( Form("%s/result.root",OutDirPath.c_str() ), "recreate");
  hist -> Write();
  gr -> Write();
  ResultFile -> Close();
  cout << "> End of tutorialAnalysis" <<endl;

  delete rootfile;
}

