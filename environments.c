#include <geometry.h>
#include <constants.h>
#include <math.h>

double NaiveNASAEnvironment_GetTemperature(Vector pos)
{
	double positionLength = Vector_GetLength(pos);
	if(positionLength - RADIUS_OF_EARTH < 11019)
		return (positionLength - RADIUS_OF_EARTH) / 1000 * (-9.8) + AIR_SURFACE_TEMPERATURE;
	else if(positionLength - RADIUS_OF_EARTH < 25098)
		return 216.483333;
	else
		return (-205.05 + .00164 * 3.2808399 * (positionLength - RADIUS_OF_EARTH) - 32) * 5 / 9 + 273.15;
}

double NaiveNASAEnvironment_GetPressure(Vector pos)
{
	double positionLength = Vector_GetLength(pos);
	if(positionLength - RADIUS_OF_EARTH < 11019)
		return 47.8477908 * (2116 * pow((59 - .00356 * 3.2808399 * (positionLength - RADIUS_OF_EARTH) + 459.7)/518.6, 5.256));
	else if(positionLength - RADIUS_OF_EARTH < 25098)
		return 47.8477908 * (473.1 * exp(1.73 - .000048 * 3.2808399 * (positionLength - RADIUS_OF_EARTH)));
	else
		return 47.8477908 * (51.97 * pow((254.65 + .00164 * 3.2808399 * (positionLength - RADIUS_OF_EARTH)) / 398.98,-11.388));

}

double NaiveNASAEnvironment_GetDensity(Vector pos)
{
	return NaiveNASAEnvironment_GetPressure(pos) / AIR_SPECIFIC_GAS_CONSTANT / NaiveNASAEnvironment_GetTemperature(pos);
}
