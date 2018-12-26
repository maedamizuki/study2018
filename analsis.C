/* 
  analysis.C
*/
#include <iostream>
#include <fstream>
#include <string>
#include "TTree.h"
#include "TChain.h"
#include "クラス.h"
#include "TH1.h"

TChain* buildChain(const std::string& filelist){
  std::ifstream fin(filelist.c_str());
  TChain* t = new TChain("t","");
  std::string fname="";

  while( !fin.eof()){ 
    fin >> fname;
    if(fname.length() > 0){
      t->Add(fname.c_str());
    }
  }
  return t; 
}
