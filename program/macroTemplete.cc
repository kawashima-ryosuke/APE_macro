/*******************************************************************
This program is a templete macro for analysys.
Auther:APE members
*******************************************************************/

//My header
#include "include/templeteFlow.h"
#include "src/tutorialAnalysis.cpp"

#ifdef __CINT__
int temp_root_macro()
#else
int main(int argc, char** argv)
#endif
{
  cout << " ====================================" << endl;
  cout << "           PROGRAM START!!           " << endl;
  cout << " ====================================" << endl;
  string DatFileName;
  string DatDirPath = "../data";
  string OutDirPath = "../out";
  if(argv[1] == NULL) DatFileName = "";
  else DatFileName = argv[1];
  
  cout << "Make Outout Directory and Data Log File" << endl;
  templeteFlow *tempFlow = new templeteFlow(DatFileName,DatDirPath,OutDirPath);
  tempFlow -> MakeOutDir(DatDirPath);
  tempFlow -> MakeDataLogFile();
  delete tempFlow;

  //Analysys part
  DatFileName = tempFlow -> DatFileName;
  DatDirPath  = tempFlow -> DatDirPath;
  OutDirPath  = tempFlow -> OutDirPath;
  tutorialAnalysis(DatFileName,DatDirPath,OutDirPath);
  
  cout << " ====================================" << endl;
  cout << "           PROGRAM FINISHED!!        " << endl;
  cout << " ====================================" << endl;
  return 0;
}
