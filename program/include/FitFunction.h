#ifndef FIT_FUNCTION_H
#define FIT_FUNCTION_H

#include<TROOT.h>
#include <stdio.h>
#include <time.h>
#include <cmath>
#include <TF1.h>
#include <TROOT.h>

TF1* _linear(Double_t x_min,Double_t x_max){
  TF1*func = new TF1("f1_liner", "pol1(0)",x_min, x_max);
  func->SetParNames("Intercept", "Slope");
  func->SetLineStyle(1);
  func->SetLineWidth(2);
  return func;
}
TF1* _exp(Double_t x_min,Double_t x_max){
  TF1*func = new TF1("f1_exp", "[0]*exp(-x/[1])",x_min,x_max);
  func->SetParNames("Initial", "Half_time");
  func->SetLineStyle(1);
  func->SetLineWidth(2);
  return func;
}
TF1* _gaus(Double_t x_min,Double_t x_max){
  TF1*func = new TF1("f1_gaus", "gaus(0)",x_min, x_max);
  func->SetParNames("Height", "Mean", "Sigma");
  func->SetLineStyle(1);
  func->SetLineWidth(2);
  return func;
}
TF1* _landau(Double_t x_min,Double_t x_max){
  TF1*func = new TF1("f1_landau", "landau(0)/0.18");
  func->SetParNames("Height", "Mu", "Sigma");
  func->SetLineStyle(1);
  func->SetLineWidth(2);
  return func;
}

#endif //FIT_FUNCTION_H
