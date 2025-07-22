# include "../Precompiled/loadresource.h"

/*
	The check_value_in_range check if the float input value is 
	in the given intervallum. If the input value smaller, or bigger 
	than the given minimum and maximum value it return false, 
	otherwise it return true.
*/

bool	check_value_in_range(float input_value, float min, float max)
{
	if (input_value < min || input_value > max)
		return (false);
	return (true);
}

/*
	The clamp_calculation function not allow the input value will 
	be bigger or smaller than the given intervallum. If the input value smaller, 
	it returns the min value, if bigger, return the max value.
*/
float	clamp_calculation(float input_value, float min, float max)
{
	if (input_value <= min)
		return (min);
	if (input_value >= max)
		return (max);
	return (input_value);
}

/*
	The double_clamp_calculation fucntion does the same thing than float 
	clamp calculation, but it use double varables
*/
double	double_clamp_calculation(double input_value, double min, double max)
{
	if (input_value <= min)
		return (min);
	if (input_value >= max)
		return (max);
	return (input_value);
}