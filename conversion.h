#pragma once

///=====================================================
///c++ library
///=====================================================
#include <string>
#include <iomanip>
#include <iterator>
#include <sstream>
#include <vector>


///=====================================================
///local header
///=====================================================
#include "global.h"
using namespace std;
///=====================================================


std::string convert_integer_to_string
(
	int iNumber
);

std::string convert_integer_to_string
(
	int iNumber,
	int iWidth
);

std::string convert_double_to_string
(
	int iPrecision,
	int iWidth,
	double dNumber
);
///=======================================================
///unit conversion
///=======================================================
double convert_from_kelvin_to_fahrenheit(double dTemperature_kelvin);
double convert_from_fahrenheit_to_kelvin(double dTemperature_fahrenheit);
double convert_from_joule_per_meter_to_calorie_per_centimeter(double dJoule_per_meter);
double convert_from_calorie_per_centimeter_to_joule_per_meter(double dCalorie_per_centimeter);

double convert_from_calorie_per_centimeter_to_joule_per_meter(double dCalorie_per_centimeter);
std::vector<std::string> split_string_by_space ( std::string sString_in);
std::vector<std::string> split_string_by_delimiter( std::string sString_in, char cDelimiter);
