#ifndef TEMPLETE_FOLE_H
#define TEMPLETE_FOLE_H

#include<iostream>
using namespace std;
#include<TROOT.h>
#include<stdio.h>
#include<string.h>
#include<fstream>
#include<sys/stat.h>
#include<sys/types.h>

class templeteFlow{
public:
  templeteFlow(string InputDatFileName,string InputDatDirPath,string InputOutDirPath);
  templeteFlow();
  ~templeteFlow();

  string DatFileName = "tutorial";
  string DatDirPath = "../data";
  string OutDirPath = "../out";
  
  void MakeOutDir(string DatFileName,Bool_t DirNameMode = false);
  void MakeDataLogFile();
  void MakeFitResultFile(int row, int column, Double_t *value, char *ResultFileName);
};

templeteFlow::templeteFlow(string InputDatFileName,string InputDatDirPath,string InputOutDirPath){
  DatFileName = InputDatFileName;
  DatDirPath = InputDatDirPath;
  OutDirPath = InputOutDirPath;
}
templeteFlow::templeteFlow(){}
templeteFlow::~templeteFlow(){}

void templeteFlow::MakeOutDir(string InputDatFileName,Bool_t DirNameMode){
  if(DirNameMode || InputDatFileName == ""){
    cout << " + Set directory name" << endl;
    cin >> InputDatFileName;
    DatFileName = InputDatFileName;
  }
  OutDirPath += "/";
  OutDirPath += DatFileName;
  cout << "> Make Directory ";
  cout << OutDirPath << endl;
  mkdir(OutDirPath.c_str(),0775);
}

void templeteFlow::MakeDataLogFile(){
  FILE *LOGFILE;
  const char* logfile = Form("%s/LOGFILE.txt",OutDirPath.c_str());
  if((LOGFILE=fopen(logfile,"w"))==NULL){
    cout << "> LogFile open Error" << endl;
    return;
  }
  char date[256];
  time_t t = time(NULL);
  strftime(date, sizeof(date), "%Y/%m/%d/ %a %H:%M:%S", localtime(&t));
  //=======================================================================
  //Contents of log file
  fprintf(LOGFILE, "#%s\n",date);
  fprintf(LOGFILE, "#Analysised Data File Name and Directory\n");
  fprintf(LOGFILE, "%s\n",DatFileName.c_str());
  fprintf(LOGFILE, "#End of File");
  //=======================================================================
  fclose(LOGFILE);
}

#endif //TEMPLETE_FOLE_H
