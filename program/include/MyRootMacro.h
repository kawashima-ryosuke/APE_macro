#ifndef TUTORIAL_FOLE_H
#define TUTORIAL_FOLE_H

#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
#include <TCanvas.h>
#include <TFile.h>
#include <TTree.h>
#include <TChain.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TMath.h>
#include <TF1.h>
#include <TGraph.h>
#include <TGraphErrors.h>
#include <TMultiGraph.h>
#include <TStyle.h>

Int_t    c1_mw =  2; // wdth margin
Int_t    c1_mh = 28; // height margin
Double_t pad_margin_top    = 0.130;
Double_t pad_margin_bottom = 0.150;
Double_t pad_margin_left   = 0.150;
Double_t pad_margin_right  = 0.08;
//canvas potision
const Int_t right_top = 0;
const Int_t left_top = 1;
const Int_t right_bottom = 2;
const Int_t left_bottom = 3;


void SetAllFigureStyle(Int_t position){
  gStyle->SetPadTopMargin(     pad_margin_top     );
  gStyle->SetPadBottomMargin(  pad_margin_bottom  );
  gStyle->SetPadLeftMargin(    pad_margin_left    );
  gStyle->SetPadRightMargin(   pad_margin_right   );
  gStyle->SetOptStat(110); // print entries & mean
  gStyle->SetOptFit (111); // print parameter & error & Chi^2

  if(position == right_top){
    //right top
    gStyle->SetStatX(1.0 -pad_margin_right +0.03);
    gStyle->SetStatY(1.0 -pad_margin_top   +0.03);
  }
  else if(position == left_top){
    //left top
    gStyle->SetStatX(     pad_margin_right +0.3);
    gStyle->SetStatY(1.0 -pad_margin_top   +0.03);
  }
  else if(position == right_bottom){
    //right bottom
    gStyle->SetStatX(1.0 -pad_margin_right +0.03);
    gStyle->SetStatY(     pad_margin_top   +0.25);
  }
  else if(position == left_bottom){
    //left bottom
    gStyle->SetStatX(     pad_margin_right +0.3);
    gStyle->SetStatY(     pad_margin_top   +0.25);
  }
}

TGraphErrors* MyGraphErr(string title,string x_label,string y_label){
  TGraphErrors* gr = new TGraphErrors();
  Float_t size = 0.05;
  title += ";" + x_label + ";" + y_label;
  gr->SetTitle(title.c_str());
  gr->SetMarkerColor(kBlack);
  gr->SetMarkerSize(1);
  gr->SetMarkerStyle(20);
  gStyle->SetTitleXSize(size);
  gStyle->SetTitleYSize(size);
  gStyle->SetLabelSize(size,"XY");
  return gr;
}

void MakeFitResultFile(int row, int column, Double_t *value,string OutDirPath ,string ResultFileName = "output.dat"){
  FILE *FitResultFile;
  const char* fitresultfile = Form("%s/%s",OutDirPath.c_str(),ResultFileName.c_str());
  if((FitResultFile=fopen(fitresultfile,"w"))==NULL){
    cout << "  + FitResultFile open Error" << endl;
  }
  //=======================================================================
  //Contents of fitresult file
  fprintf(FitResultFile, "#temp_root_macro.cc Fitresult file\n");
  for(int i=0;i<row;i++){
    for(int j=0;j<column;j++){
      fprintf(FitResultFile, "%f ",value[i+j]);
    }
    fprintf(FitResultFile, "\n");
  }
   //=======================================================================
  fclose(FitResultFile);
}

#endif //TUTORIAL_FOLE_H
