#pragma once

#include <string>
#include <fstream>
#include "conversion.h"
#include "system.h"

using namespace std;
class timesat
{
 public:
  timesat(void);
  ~timesat(void);
  int prepare_timesat_filelist(
                               int iCount,
                               int iInterval,
                               int iYear_end,
                               int iYear_start,
                               std::string sFilename_out,
                               std::string sPrefix,
                               std::string sWorkpace_data_in
                               );

  int prepare_timesat_setting(
			      int iByte_ordee,
                              int iColumn_end,
                              int iColumn_start,
                              int iFlag_image,
                              int iImage_type,
                              int iRow_end,
                              int iRow_start,

                              int iSpike_method,
                              int iSpike_value,
                              int ncolumn,
                              int npoint,
                              int nrow,
                              int nyear,
                              long  max_value,
                              long min_value,

                              std::string sFilename_list,
                              std::string sFilename_setting,
                              std::string sJob_name
                              );

};
