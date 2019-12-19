///==============================================================
/*!
  \file   conversion.cpp
  \brief

  <long description>

  \author Chang Liao
  \date   2016-10-06
*/
///==============================================================
#include "conversion.h"

///===================================================================
///<it is used to convert integer to string since c++ 11 doesn't support well
///===================================================================

std::string convert_integer_to_string
(
 int iNumber
 )
{
  std::string str = "";
  stringstream ss;
  ss << iNumber;
  str = ss.str();
  return str;
}

std::string convert_integer_to_string
(
 int iNumber,
 int iWidth
 )
{
  std::string str = "";
  stringstream ss;
  ss << setfill('0') << setw(iWidth) << iNumber;
  str = ss.str();
  return str;
}
std::string convert_double_to_string
(
 int iPrecision,
 int iWidth,
 double dNumber
 )
{
  std::string str = "";
  stringstream ss;
  ss << std::fixed << std::setw(iWidth) << std::setprecision(iPrecision) << dNumber;
  str = ss.str();
  return str;
}


double convert_from_kelvin_to_fahrenheit(double dTemperature_kelvin)
{
  double dTemperature_celsius = dTemperature_kelvin + kelvin_2_celsius;
  double dTemperature_fahrenheit = dTemperature_celsius * 1.8 + 32.0;
  return dTemperature_fahrenheit;
}
double convert_from_fahrenheit_to_kelvin(double dTemperature_fahrenheit)
{
  double dTemperature_celsius = (dTemperature_fahrenheit - 32.0) / 1.8;
  double dTemperature_kelvin = dTemperature_celsius - 273.15;
  return dTemperature_kelvin;
}
double convert_from_joule_per_meter_to_calorie_per_centimeter(double dJoule_per_meter)
{
  double dCalorie_per_meter = dJoule_per_meter * joule_2_calorie;
  double dCalorie_per_centimeter = dCalorie_per_meter / 10000.0;
  return dCalorie_per_centimeter;
}

double convert_from_calorie_per_centimeter_to_joule_per_meter(double dCalorie_per_centimeter)
{
  double dCalorie_per_meter = dCalorie_per_centimeter * 10000;
  double dJoule_per_meter = dCalorie_per_meter * calorie_2_joule;
  return dJoule_per_meter;
}

///==============================================================
/*!
  <long-description>

  \param sString_in
*/
///==============================================================

std::vector<std::string> split_string_by_space ( std::string sString_in)
{
  auto lLength = sString_in.length();
  if (lLength >0)
    {
      std::istringstream iss(sString_in);
      std::istream_iterator<std::string> iterator_begin(iss), iterator_end;
      std::vector<std::string> vTokens( iterator_begin, iterator_end); // done!
      return vTokens;
    }
  else
    {
      std::vector<std::string> nothing;
      return nothing;
    }
}

///==============================================================
/*!
  <long-description>

  \param sString_in
  \param cDelimiter
*/
///==============================================================

std::vector<std::string> split_string_by_delimiter( std::string sString_in, char cDelimiter)
{
  auto lLength =  sString_in.length();
  std::vector<std::string> vTokens;
  if (lLength >0)
    {
      std::stringstream ss;
      ss.str(sString_in);
      std::string dummy;
      while ( std::getline(ss, dummy, cDelimiter) )
        {
          vTokens.push_back(dummy);
        }

    }
  else
    {

    }
  return vTokens;
}
