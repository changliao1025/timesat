#pragma once

///========================================================
///=========================================
///C header
///========================================================
///C++ header
#include <array>  ///<the small sized array
#include <fstream> ///<file stream
#include <iterator> ///<for vector and stream
#include <string> ///<c++ string
#include <vector> ///<vector
///========================================================
using namespace std;
///========================================================

class data
{
 public:
  data(void);
  ~data(void);
  ///========================================================================
  ///Traditional data IO
  ///========================================================================
  static float * read_binary(std::string sFilename);
  static float ** read_binary(std::string sFilename,  long lCol, long lRow);
  static std::vector<double> read_binary_vector(std::string sFilename);
  static int write_binary_vector(std::string sFilename, vector <double> vData);
  ///==========================================================================
  ///advanced data io using MPI
  ///dataIO using PETSc
  ///========================================================================
  ///Mat Read_Binary(string filErtame,int m,int n);
  ///========================================================================
};

