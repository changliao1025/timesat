#pragma once
//the global variables for all other modules
//====================================================================================
//c library
#include <cmath>
//====================================================================================
//c++ library
#include <vector>
//====================================================================================
#include "global.h"
//====================================================================================
using namespace std;
//====================================================================================

//====================================================================================
///simple math
double calculate_mean(std::vector<double> data, double missing_value );
double calculate_mean(std::vector<double> data, double max_value, double min_value);
///matrux solution
void tridia(int n,
            vector<double>& a,
            vector<double>& b,
            vector<double>& c,
            vector<double>& r,
            vector<double>& u);
