#pragma once

template<typename T>
T Clamp(const T val, const T min, const T max)
{
	T output = val;
	output = (output < min) ? min : output;
	output = (output > max) ? max : output;
	return output;
}

