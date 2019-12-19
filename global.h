#pragma once
///========================================================
///the global constant file for all the modules
///some constants or variables are written cross-platfrom
///========================================================
extern const double near_zero;
extern const double pi;

///soil
extern const double dFrozen_temperature ; //unit: K
extern const double dDensity_water ;//density of water, unit: 
extern const double tkwat ;			// thermal conductivity of water (w/m/kelvin)
extern const double tkice ;			// thermal conductivity of ice (w/m/kelvin)
extern const double cwat ;		// specific heat capacity of water (j/m**3/kelvin)
extern const double cice ;		// specific heat capacity of ice (j/m**3/kelvin)
//physical
extern const double calorie_2_joule ;//convert from calorie  to langley
extern const double joule_2_calorie ;
extern const double inch_2_cm ;
extern const double inch_2_meter ;
extern const double joule_2_langley ; //convert from joulies  to langley
extern const double kelvin_2_celsius ;
extern const double kg_per_meter_2_gram_per_centimeter ;
extern const double celsius_2_kelvin ;
extern const double langley_2_joule ;
extern const double meter_2_foot ; ///<conversion
extern const double dLatent_heat_water ; //heat of fusion (latent heat) of water. units: joule per kilogram
extern const double dSpecific_heat_water ; //the specific heat of water, units: j / (kg * kelvin )
extern const double dSpecific_heat_ice ; ///<the specific heat of ice, units: j / (kg * kelvin )
// revolution speed of the Earth, radians per day , this is very close to pi/180, but it is different.
extern const double radian ;
extern const double dEccentricy ;
extern const double dSolar_constant  ; // solar extern const units: watt per square meter, look at wiki: https://en.wikipedia.org/wiki/Solar_constant

//system

extern const char slash ;

extern const double missing_value;

//================================
extern const double dTimestep_ecosystem; ///<unit: second
										 //gis

extern const double dResolution;//unit: meter
extern const double dArea;



extern const double dTemperature_all_rain; //unit: kelvin
extern const double dTemperature_all_snow; //unit: kelvin
extern const double dFraction_sublimation; //snow, this one should be in snow class