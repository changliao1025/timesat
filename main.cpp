///==============================================================
/*!
  \file main.cpp
  \brief
  <long description>
  \author Chang Liao
  \date 2016-10-05
*/
///==============================================================
#include <string>
///================================
#include "conversion.h"
#include "prms.h"
#include "timesat.h"
using namespace std;
int main(int argc, char *argv[])
{
  int error_code = 1;
  std::string sConfiguration_file;

  if (argc < 2)
    {
      std::cout << "No arguments are provided!" << endl;
      std::cout << "Please input the data workspace:" << endl;
      std::cin >> sConfiguration_file;
    }
  else
    {
      std::cout << "The following arguments are provided:" << endl;
      for (int i = 0; i < argc; i++)
        {
          std::cout << argv[i] << endl;
        }
    }
  sConfiguration_file = argv[1];
  ///=====================================================================
  int iModel = 0;
  int iFlag_image = 0;
  int iDay_end;
  int iDay_start;
  int iMonth_end;
  int iMonth_start;
  int iYear_start;
  int iYear_end;
  int iInterval;
  int iCount;
  int iByte_order = 0;
  int iColumn_end;
  int iColumn_start;
  int iImage_type;
  int iRow_end;
  int iRow_start;
  int iSpike_method = 2;
  int iSpike_value = 2;
  int ncolumn;
  int nrow;
  int npoint;
  int nyear ;
  int max_value;
  int min_value;
  std::string sCommand;
  std::string sFilename_list;
  std::string sFilename_setting = "";
  std::string sJob_name = "test";
  std::string sFilename_in;
  std::string sFilename_out;
  std::string sWorkspace_data_in;
  std::string sWorkspace_out;
  std::string sPrefix;
  std::string line;
  std::string  sFilename_timesat = "/home/liao46/tool/timesat32/timesat_fortran/main/TSF_process.x64";
  std::string sFilename_seasonality;
  std::string sFilename_fit;
  if(file_test(sFilename_timesat) != 1)
    {
      std::cout<<"The timesat program does not exist!"<<std::endl;
      error_code =0;
      return error_code;
    }
  else
    {

    }
  std::vector<std::string> vDummy;
  prms cPrms;
  ///=====================================================
  char cDelimiter = ',';
  ///=====================================================
  std::ifstream ifs;
  ifs.open(sConfiguration_file.c_str(), ios::in);
  if (ifs.good())
    {
      //keep going
      ///==============================================
      timesat pTimesat;
      std::getline(ifs, line);
      vDummy = split_string_by_delimiter(line, cDelimiter);
      iModel = std::stoi(vDummy[0]);
      std::getline(ifs, line);
      vDummy = split_string_by_delimiter(line, cDelimiter);
      iFlag_image = std::stoi(vDummy[0]);
      ///======================================================
      ///prepare timesat file
      switch (iModel)
        {
        case 1:                 ///<dataset mode
          if (iFlag_image == 0) ///single file
            {
              std::getline(ifs, line);
              vDummy = split_string_by_delimiter(line, cDelimiter);
              sFilename_in = vDummy[0];
              std::getline(ifs, line);
              vDummy = split_string_by_delimiter(line, cDelimiter);
              sFilename_out = vDummy[0];
            }
          else ///list of image
            {
              std::getline(ifs, line);
              vDummy = split_string_by_delimiter(line, cDelimiter);
              sFilename_in = vDummy[0];
              std::getline(ifs, line);
              vDummy = split_string_by_delimiter(line, cDelimiter);
              sFilename_out = vDummy[0];
              error_code = pTimesat.prepare_timesat_filelist(
                                                             iCount,
                                                             iInterval,
                                                             iYear_end,
                                                             iYear_start,
                                                             sFilename_out,
                                                             sPrefix,
                                                             sWorkspace_data_in);
            }
          break;
        case 2:                 ///prms
          if (iFlag_image == 0) ///single file
            {
              std::getline(ifs, line);
              vDummy = split_string_by_delimiter(line, cDelimiter);
              sFilename_in = vDummy[0];
              std::getline(ifs, line);
              vDummy = split_string_by_delimiter(line, cDelimiter);
              sFilename_out = vDummy[0];
              std::getline(ifs, line);
              vDummy = split_string_by_delimiter(line, cDelimiter);
              iDay_end = std::stoi(vDummy[0]);
              std::getline(ifs, line);
              vDummy = split_string_by_delimiter(line, cDelimiter);
              iDay_start = std::stoi(vDummy[0]);
              std::getline(ifs, line);
              vDummy = split_string_by_delimiter(line, cDelimiter);
              iMonth_end = std::stoi(vDummy[0]);
              std::getline(ifs, line);
              vDummy = split_string_by_delimiter(line, cDelimiter);
              iMonth_start = std::stoi(vDummy[0]);
              std::getline(ifs, line);
              vDummy = split_string_by_delimiter(line, cDelimiter);
              iYear_end = std::stoi(vDummy[0]);
              std::getline(ifs, line);
              vDummy = split_string_by_delimiter(line, cDelimiter);
              iYear_start = std::stoi(vDummy[0]);
              cPrms.prepare_timesat_prms_daily_file(
                                                    iDay_end,
                                                    iDay_start,
                                                    iMonth_end,
                                                    iMonth_start,
                                                    iYear_end,
                                                    iYear_start,
                                                    sFilename_in,
                                                    sFilename_out);
            }
          else ///list of image
            {
              std::getline(ifs, line);
              vDummy = split_string_by_delimiter(line, cDelimiter);
              sFilename_in = vDummy[0];
              std::getline(ifs, line);
              vDummy = split_string_by_delimiter(line, cDelimiter);
              sFilename_out = vDummy[0];
              error_code = pTimesat.prepare_timesat_filelist(
                                                             iCount,
                                                             iInterval,
                                                             iYear_end,
                                                             iYear_start,
                                                             sFilename_out,
                                                             sPrefix,
                                                             sWorkspace_data_in);
            }
          break;
        case 3: ///modflow
          break;
        default: ///<dataset mode
          break;
        }
      ///=====================================================
      ///start to prepare setting files
      ///prepare  setting file
      ///=====================================================
      ///we need to prepare the timesat file anyway
      ///=====================================================
      std::getline(ifs, line);
      vDummy = split_string_by_delimiter(line, cDelimiter);
      iByte_order = std::stoi(vDummy[0]);
      std::getline(ifs, line);
      vDummy = split_string_by_delimiter(line, cDelimiter);
      iColumn_end = std::stoi(vDummy[0]);
      std::getline(ifs, line);
      vDummy = split_string_by_delimiter(line, cDelimiter);
      iColumn_start = std::stoi(vDummy[0]);
      ///=====================================================
      if (iFlag_image != 1)
        {
          iColumn_end =1;
          iColumn_start =1;
        }
      ///=====================================================
      std::getline(ifs, line);
      vDummy = split_string_by_delimiter(line, cDelimiter);
      iImage_type = std::stoi(vDummy[0]);
      std::getline(ifs, line);
      vDummy = split_string_by_delimiter(line, cDelimiter);
      iRow_end = std::stoi(vDummy[0]);
      std::getline(ifs, line);
      vDummy = split_string_by_delimiter(line, cDelimiter);
      iRow_start = std::stoi(vDummy[0]);
      ///=====================================================
      if (iFlag_image != 1)
        {
          iRow_end =1;
          iRow_start =1;
        }
      ///=====================================================
      std::getline(ifs, line);
      vDummy = split_string_by_delimiter(line, cDelimiter);
      iSpike_method = std::stoi(vDummy[0]);
      std::getline(ifs, line);
      vDummy = split_string_by_delimiter(line, cDelimiter);
      iSpike_value = std::stoi(vDummy[0]);
      std::getline(ifs, line);
      vDummy = split_string_by_delimiter(line, cDelimiter);
      ncolumn = std::stoi(vDummy[0]);
      std::getline(ifs, line);
      vDummy = split_string_by_delimiter(line, cDelimiter);
      npoint = std::stoi(vDummy[0]);
      std::getline(ifs, line);
      vDummy = split_string_by_delimiter(line, cDelimiter);
      nrow = std::stoi(vDummy[0]);
      if (iFlag_image != 1)
        {
          ncolumn =1;
          nrow =1;
        }

      ///=====================================================
      ///get year based on input
      ///=====================================================
      nyear = iYear_end - iYear_start + 1;
      std::getline(ifs, line);
      vDummy = split_string_by_delimiter(line, cDelimiter);
      max_value = std::stof(vDummy[0]);
      std::getline(ifs, line);
      vDummy = split_string_by_delimiter(line, cDelimiter);
      min_value = std::stoi(vDummy[0]);
      std::getline(ifs, line);
      vDummy = split_string_by_delimiter(line, cDelimiter);
      sFilename_list = vDummy[0];
      std::getline(ifs, line);
      vDummy = split_string_by_delimiter(line, cDelimiter);
      sFilename_setting = vDummy[0];
      std::getline(ifs, line);
      vDummy = split_string_by_delimiter(line, cDelimiter);
      sJob_name = vDummy[0];
      std::getline(ifs, line);
      vDummy = split_string_by_delimiter(line, cDelimiter);
      sWorkspace_out = vDummy[0];
      ///=====================================================
      if (iFlag_image != 1)
        {
          sFilename_list = sFilename_out;
        }
      else
        {

        }
      ///======================================================
      error_code = pTimesat.prepare_timesat_setting(
                                                    iByte_order,
                                                    iColumn_end,
                                                    iColumn_start,
                                                    iFlag_image,
                                                    iImage_type,
                                                    iRow_end,
                                                    iRow_start,
                                                    iSpike_method,
                                                    iSpike_value,
                                                    ncolumn,
                                                    npoint,
                                                    nrow,
                                                    nyear,
                                                    max_value,
                                                    min_value,
                                                    sFilename_list,
                                                    sFilename_setting,
                                                    sJob_name);
      ///==========================================================
      ///run timesat
      ///==========================================================
      ///change workspace first
      chdir(sWorkspace_out.c_str());
      ///currently we only use 1 core to run the program
      sCommand = sFilename_timesat + " " + sFilename_setting + " " + "1";
      run_command(sCommand);
      std::cout << "The program is excuated successfulyy!" << std::endl;
      ///==========================================================
      ///post-process
      ///==========================================================
      usleep(5.0 * 1000000.0);

      ///check seasonality file

      sFilename_seasonality = sWorkspace_out + slash + sJob_name + "_TS.tpa";
      if (file_test (sFilename_seasonality) ==1)
        {

          std::cout << "The seasonality file is ready!" << std::endl;
        }

      else
        {
          std::cout << "The seasonality file is not ready!" << std::endl;
        }




      ///==========================================================
      ///==========================================================
      return error_code;
    }
  else
    {
      return error_code;
    }
}
