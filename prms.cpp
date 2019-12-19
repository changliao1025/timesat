///==============================================================
/*!
  \file   prms.cpp
  \brief

  <long description>

  \author Chang Liao
  \date   2016-10-06
*/
///==============================================================
#include "prms.h"

prms::prms()
{
}
prms::~prms()
{
}

///==============================================================
/*!
  <long-description>
  This function transfer prms discharge data into "qualified" timesat file format.
  Essentially, the leap year effect is removed.
  \param sFilename_in
  \param sFilename_out
  \return <ReturnValue>
*/
///==============================================================
int prms::prepare_timesat_prms_daily_file(
                                          int iDay_end,
                                          int iDay_start,
                                          int iMonth_end,
                                          int iMonth_start,
                                          int iYear_end,
                                          int iYear_start,
                                          std::string sFilename_in,
                                          std::string sFilename_out)
{
  int error_code = 1;
  int nyear = iYear_end - iYear_start + 1;
  int nptperyear = 365; ///the the leap year must be compromised here
  long nts = 1; ///currently we only support one time series
  long lJulday_base, lJulday_start, lJulday_day;
  long index_day;
  double dummy;
  std::ifstream ifs;
  std::ofstream ofs;
  std::vector<double> data;
  std::vector<double>::iterator max_data;

  lJulday_base = date::YmdToJd(iYear_start, iMonth_start, iDay_start);

  std::cout << lJulday_base << std::endl;
  if (file_test(sFilename_in) != 1)
    {
      error_code = 0;
    }
  else
    {
      ifs.open(sFilename_in.c_str(), ios::in);
      if (ifs.good())
        {
          ///read all the data
          while (ifs.eof() == false)
            {
              ifs >> dummy;
              data.push_back(dummy);
            }
          ///get max value
          max_data = std::max_element(data.begin(), data.end());
          dummy = *max_data;
          ///=================================================
          ///convert original data to 0-1 scale using the max value
          ///=================================================
          for (std::vector<double>::iterator iter = data.begin(); iter != data.end(); iter++)
            {
              *iter = *iter / dummy;
            }
          std::cout << "Read finished" << std::endl;
          ///===================================================
          ///write the file out
          ///=================================================
          ofs.open(sFilename_out.c_str(), ios::out);
          if (ofs.good())
            {
              long index = 0;
              ofs << nyear << " " << nptperyear << " " << nts << std::endl;
              for (int iYear = iYear_start; iYear <= iYear_end; iYear++)
                {
                  lJulday_start = date::YmdToJd(iYear, 1, 1);
                  for (int iDay = 1; iDay <= nptperyear; iDay++)
                    {
                      ///get index based
                      lJulday_day = lJulday_start + iDay - 1;
                      index_day = lJulday_day - lJulday_base;
                      if (data[index_day] > 1.0)
                        {
                          std::cout << "error" << std::endl;
                        }
                      else
                        {
                          ofs << data[index_day] << " ";
                        }

                      index++;
                    }
                  std::cout << iYear << " finished" << std::endl;
                }
              ofs << std::endl;
            }
          else
            {
              std::cout << "cannot write" << std::endl;
            }
          ofs.close();
          std::cout << "write finished" << std::endl;
        }
      else
        {
          std::cout << "cannote Read " << std::endl;
        }
      ifs.close();
    }
  return error_code;
}

///==============================================================
/*!
  <long-description>

  \param sFilename_in
  \return <ReturnValue>
*/
///==============================================================

int prms::analyze_timesat_prms_seasonality(
                                   int iDay_end,
                                   int iDay_start,
                                   int iMonth_end,
                                   int iMonth_start,
                                   int iYear_end,
                                   int iYear_start,
                                   std::string sFilename_in,
                                   std::string sFilename_out)
{
  int error_code = 1;
  int dummy, dummy_day;
  std::string line;
  std::ifstream ifs;
  std::ofstream ofs;


  std::vector<int> vSeason_start;
  long lJulday_base = date::YmdToJd(iYear_start, iMonth_start, iDay_start);
  long lJulday_day;
  if (file_test(sFilename_in) != 1)
    {
      error_code = 0;
      std::cout << "file does not exist!";
    }
  else
    {
      ifs.open(sFilename_in.c_str(), ios::in);

      if (ifs.good())
        {
          std::getline(ifs, line);
          std::getline(ifs, line);

          for (int iYear = iYear_start; iYear < iYear_end; iYear++)
            {
              std::getline(ifs, line);

              std::vector<std::string> tokens = split_string_by_space(line);
              dummy_day = std::atof(tokens[1].c_str());

              lJulday_day = date::YmdToJd(iYear, 1, 1);
              dummy = dummy_day - 1 - (lJulday_day - lJulday_base);
              vSeason_start.push_back(dummy);
              std::cout << dummy << std::endl;
            }

          ofs.open(sFilename_out.c_str(), ios::out);
          if (ofs.good())
            {
              std::cout << sFilename_out << std::endl;
              for (std::vector<int>::iterator iter = vSeason_start.begin(); iter != vSeason_start.end(); iter++)
                {
                  ofs << *iter << std::endl;
                }
            }
          else
            {
              std::cout << "cannot write result" << std::endl;
            }
          ofs.close();
        }
    }
  std::cout << "Seasonality analysis is finished!" << std::endl;
  return error_code;
}
