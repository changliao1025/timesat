#pragma once
//the global variables for all other modules
//c library
#include <limits.h>
#include <stdio.h>
#include <cstring>
//c++ library

#include <fstream>
#include <iostream>

#include <string>
///========================================================================================
//cros-platform header
#ifdef __linux__
#include <sys/stat.h>
#include <sys/types.h>
#elif _WIN32
#include <direct.h>
#include <windows.h>
#else
#endif
///========================================================================================
#include "global.h"

///========================================================================================
using namespace std;
//=========================================================================================
///functions
//=============================================================================================


///=============================================================================================
///test whether a file exists or not
///=============================================================================================
int file_test(std::string sFilename);

///=============================================================================================
///make directory ()
////=============================================================================================
int make_directory(std::string sDirectory);

//=============================================================================================
//check whether a directory exists or not
//=============================================================================================
int path_test(std::string sPath);


int run_command(std::string sCommand);


long get_file_size(std::string sFilename);
