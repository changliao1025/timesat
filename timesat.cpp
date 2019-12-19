#include "timesat.h"



timesat::timesat()
{
}
timesat::~timesat()
{
}


int timesat::prepare_timesat_filelist(
                                      int iCount,
                                      int iInterval,
                                      int iYear_end,
                                      int iYear_start,
                                      std::string sFilename_out,
                                      std::string sPrefix,
                                      std::string sWorkpace_data_in
                                      )
{
  int error_code =1;

  if(path_test(sWorkpace_data_in) !=1)
    {
      error_code=0;
    }
  else
    {
      std::ofstream ofs;
      ofs.open(sFilename_out.c_str(),ios::out);

      if (ofs.good())
        {
          long lCount = iCount * (iYear_end - iYear_start + 1);
          ofs<<lCount<<std::endl;

          for (int iYear=iYear_start; iYear <= iYear_end; iYear++)
            {

              std::string sYear = convert_integer_to_string(iYear,4);
              std::string sYear_in = sWorkpace_data_in + slash + sYear;
              if(path_test(sYear_in) ==1)
                {
                  for (int i=1; i<=iCount ; i++   )
                    {
                      int iDay = (i-1) *   iInterval +1;

                      std::string sDay=convert_integer_to_string(iDay,3);
                      std::string sFilename= sYear_in + slash + sPrefix + sYear + sDay + ".dat";
                      if(file_test (sFilename) ==1)
                        {
                          ///     std::cout<<sFilename<<std::endl;
                          ofs<<sFilename<<std::endl;
                        }
                      else
                        {
                          std::cout<<sFilename<<" does not exist"<<std::endl;
                          error_code =0;
                          return error_code;
                        }

                    } ///day loop
                }
              else
                {
                }

            }///finished year loop
          ofs.close();
        }
      else
        {
          std::cout<<"Cannot write to result"<<std::endl;
          error_code =0;
        }
    }
  return error_code;
}


int timesat::prepare_timesat_setting(
                                     int iByte_order,
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
                                     long max_value,
                                     long min_value,
                                     std::string sFilename_list,
                                     std::string sFilename_setting,
                                     std::string sJob_name
                                     )
{
  int error_code =1;

  std::ofstream ofs;
  ofs.open(sFilename_setting.c_str(), ios::out);
  if (ofs.good())
    {

      ofs<<"Version: 3.2"<<std::endl;
      ofs<<sJob_name<<std::endl; ///name of the job
      ofs<<iFlag_image<<std::endl; ///single data or image list
      ofs<<"0"<<std::endl; ///trend is currently not in use
      ofs<<"0"<<std::endl; //mask/quality control file
      ofs<<sFilename_list<<" %"<<std::endl; ///filename of the data
      ofs<<"dummy %"<<std::endl; ///filename of the mask
      ///image type 1 = 8-bit unsigned integer, 2 = 16-bit signed integer, 3 = 32-bit real
      ofs<<iImage_type<<std::endl;
      ofs<<iByte_order<<std::endl; ///0 little endian order; 1 big endian order
      ofs<<nrow<<" "<<ncolumn<<std::endl; ///image dimension
      ofs<<iRow_start<<" "<<iRow_end<<" "<<iColumn_start<<" "<<iColumn_end<<std::endl; ///index of process window
      ofs<<nyear<<" "<<npoint<<std::endl; ///number of year and number of point in each year
      ofs<<min_value<<" "<<max_value<<std::endl; ///data range
      ofs<<"-1e+06 1e+06 1"<<std::endl; ///mask range
      ofs<<"-1e+06 1e+06 1"<<std::endl;
      ofs<<"-1e+06 1e+06 1"<<std::endl;

      ofs<<"0"<<std::endl; ///amplitude cutoff value
      ofs<<"0"<<std::endl; ///print function and weight
      ofs<<"1 1 0"<<std::endl; ///output file (seasonality, fitted data, and original data)
      ofs<<"0"<<std::endl; ///land cover
      ofs<<" "<<std::endl; ///filename of land cover
      ofs<<iSpike_method<<std::endl; ///spike method
      ofs<<iSpike_value<<std::endl; ///spike value
      ofs<<"0"<<std::endl;  ///<spatial half dimension; not in use
      ofs<<"1"<<std::endl; ///<number of land cover class
      ofs<<"************" <<std::endl;
      ofs<<"1"<<std::endl; ///<land cover class 1
      ofs<<"1"<<std::endl; ///<season parameter
      ofs<<"1"<<std::endl; ///<Number of envelop iterations
      ofs<<"2"<<std::endl; ///<adaptation strength
      ofs<<"0 -99999"<<std::endl; ///force minimum value
      ofs<<"3"<<std::endl;  ///<fitting method
      ofs<<"1"<<std::endl; ///<weight update method
      ofs<<"8"<<std::endl; ///<window size for sav-gol
      ofs<<"0"<<std::endl; ///<spatial-temporal smoothing factor
      ofs<<"0"<<std::endl; ///<spatial-temporal adaptation factor
      ofs<<"1"<<std::endl; ///<season start method
      ofs<<"0.5 0.5"<<std::endl;

      ofs.close();
    }


  return error_code;

}
