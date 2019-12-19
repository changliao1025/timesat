#include "global.h"
///========================================================                                                                                                     
///the global  constant file for all the modules                                                                                                                     
///some  constants or variables are written cross-platfrom                                                                                                           
///========================================================    

const double dTimestep_ecosystem = 1.0; ///<unit: second
const double dResolution = 500.0;//unit: meter
const double dArea = 500.0 * 500.0;
const double dTemperature_all_rain = 273.0; //unit: kelvin
const double dTemperature_all_snow = 273.0; //unit: kelvin
const double dFraction_sublimation = 0.5; //snow, this one should be in snow class
 const double tkwat=1.0;			// thermal conductivity of water (w/m/kelvin)
 const double tkice=1.0;			// thermal conductivity of ice (w/m/kelvin)
 const double cwat=1.0;		// specific heat capacity of water (j/m**3/kelvin)
 const double cice=1.0;		// specific heat capacity of ice (j/m**3/kelvin)



const double  near_zero = 0.000001;
const double  pi = 3.141592654;

//gis                                                                                                                                                           
const double  dFrozen_temperature = 273.15; //unit: K                                                                                                           
const double  dDensity_water = 1000.0;//density of water, unit:                                                                                                 

//physical                                                                                                                                                      
const double  calorie_2_joule = 4.1858;//convert from calorie  to langley                                                                                       
const double  joule_2_calorie = 1.0 / 4.1858;
const double  inch_2_cm = 2.54;
const double  inch_2_meter = 2.54 / 100.0;
const double  joule_2_langley = 1.0 / 41840.0; //convert from joulies  to langley                                                                               
const double  kelvin_2_celsius = -273.15;
const double  kg_per_meter_2_gram_per_centimeter = 1000 / 1000000.0;
const double  celsius_2_kelvin = 273.15;
const double  langley_2_joule = 41840.0;
const double  meter_2_foot = 3.28084; ///<conversion                                                                                                            
const double  dLatent_heat_water = 333.55 * 1000.0; //heat of fusion (latent heat) of water. units: joule per kilogram                                          
const double  dSpecific_heat_water = 4.179 * 1000.0; //the specific heat of water, units: j / (kg * kelvin )                                                    
const double  dSpecific_heat_ice = 2.03 * 1000.0; ///<the specific heat of ice, units: j / (kg * kelvin )                                                       
///revolution speed of the Earth, radians per day , this is very close to pi/180, but it is different.                                                          
const double  radian = 0.0172;
const double  dEccentricy = 0.0167;
///solar   units: watt per square meter, look at wiki: https://en.wikipedia.org/wiki/Solar_ ant                                                                 
const double  dSolar_constant = 1368.0 ;


//system                                                                                                                                                        
#if defined(__linux__)
const char slash = '/';
#else
const char slash = '\\';
#endif
const double  missing_value = -9999.0;

