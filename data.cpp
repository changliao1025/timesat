#include "data.h"
data::data(void)
{
}
data::~data(void)
{
}

///====================================================
///read binary file (float type)
///====================================================
float * data::read_binary(string sFilename)
{
  float dummy;
  ifstream ifs;
  ifs.open (sFilename.c_str(), ios::in | ios::binary);
  ifs.seekg(0,ios::end);
  long lLength1 = ifs.tellg();
  ifs.seekg(0,ios::beg);
  long lLength2 = lLength1 /sizeof(float);
  float * pdata = new float[lLength2];
  for (long i = 0; i < lLength2; ++i)
    {
      ifs.read( reinterpret_cast<char*>( &dummy ), sizeof dummy );
      pdata[i] = dummy;
    }
  ifs.close();
  return pdata;
}

///====================================================
///read binary into a two dimension array pointer
///====================================================

float ** data::read_binary(string sFilename,long lCol,long lRow)
{
  float dummy;
  ifstream ifs;
  ifs.open(sFilename.c_str(), ios::in | ios::binary);
  float * pdata_dummy = new float[lCol*lRow];
  for (long i = 0; i < lCol*lRow - 1; ++i)
    {
      ifs.read( reinterpret_cast<char*>( &dummy ), sizeof dummy );
      pdata_dummy[i]=dummy;
    }
  ifs.close();

  float ** pdata = new float *[lCol];
  for (long i = 0;i < lCol; ++i )
    {
      pdata[i] = pdata_dummy + lRow * i ;
    }
  return pdata;
}

///====================================================
///read binary and save to a vector
///====================================================
vector<double> data::read_binary_vector(string sFilename)
{
  float dummy;
  ifstream ifs;
  ifs.open(sFilename.c_str(), ios::in | ios::binary);
  ifs.seekg(0,ios::end);
  long lLength1 = ifs.tellg();
  ifs.seekg(0,ios::beg);
  long lLength2 = lLength1 /sizeof(float);
  vector<double> vdata;
  for (long i = 0;i < lLength2; ++i)
    {
      ifs.read( reinterpret_cast<char*>( &dummy ), sizeof dummy );
      vdata.push_back(dummy);
    }
  ifs.close();
  return vdata;
}


///====================================================
//write vector to float binary file
///====================================================
int data::write_binary_vector( std::string sFilename, std::vector <double> vData_out)
{
  int error_code = 1 ;
  std::vector<float> vData( vData_out.begin(), vData_out.end() );
  ofstream ofs(sFilename.c_str(), ios::out | ios::binary);
  if( ofs.is_open() )
    {
      ofs.write(reinterpret_cast<char*>(&vData[0]), vData.size()* sizeof(float));
      ofs.close();
    }
  else
    {
      error_code = 0 ;
    }
  return error_code;
}
