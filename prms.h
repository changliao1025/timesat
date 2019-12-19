#pragma once


///===================================
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>

///==========================
#include "system.h"
#include "date.h"
#include "conversion.h"


using namespace std;

class prms
{
 public:
  prms(void);
  ~prms(void);
  int prepare_timesat_prms_daily_file(
                                      int iDay_end,
                                      int iDay_start,
                                      int iMonth_end,
                                      int iMonth_start,
                                      int iYear_end,
                                      int iYear_start,

                                      std::string sFilename_in,
                                      std::string sFilename_out
                                      );

  int analyze_timesat_prms_seasonality(
                                       int iDay_end,
                                       int iDay_start,
                                       int iMonth_end,
                                       int iMonth_start,
                                       int iYear_end,
                                       int iYear_start,

                                       std::string sFilename_in,
                                       std::string sFilename_out
                                       );



};
