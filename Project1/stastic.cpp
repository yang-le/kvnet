#include "stastic.h"

float sum(float data[], size_t size)
{
	float sum = 0;
	for (unsigned int i = 0; i < size; ++i)
		sum += data[i];
	return sum;
}

float avg(float data[], size_t size)
{
	return sum(data, size) / size;
}

float var(float data[], size_t size)
{
	float var = 0;
	float _avg = avg(data, size);
	for (unsigned int i = 0; i < size; ++i)
		var += (data[i] - _avg) * (data[i] - _avg);
	return var / size;
}

float max(float data[], size_t size)
{
	float max = data[0];
	for (unsigned int i = 1; i < size; ++i)
	{
		if (data[i] > max)
			max = data[i];
	}
	return max;
}

float min(float data[], size_t size)
{
	float min = data[0];
	for (unsigned int i = 1; i < size; ++i)
	{
		if (data[i] < min)
			min = data[i];
	}
	return min;
}
