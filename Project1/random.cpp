#include <cstdlib>
#include <ctime>

#include "random.h"

void uniform(float data[], size_t size, float a, float b)
{
	if (a > b)
	{
		float c = a;
		a = b;
		b = c;
	}

	srand((unsigned int)time(NULL));
	for (unsigned int i = 0; i < size; ++i)
		data[i] = a + (b - a) * rand() / RAND_MAX;
}

void normal(float data[], size_t size, float mean, float var)
{
	float u, v, w;
	srand((unsigned int)time(NULL));

	float std_dev = (float)sqrt(var);
	for (unsigned int i = 0; i < size; ++i)
	{
		do {
			u = (float)(2. * rand() / RAND_MAX - 1.);
			v = (float)(2. * rand() / RAND_MAX - 1.);
			w = u * u + v * v;
		} while ((w < 0) || (w > 1));

		// see Box-Muller
		data[i] = std_dev * (float)(u * sqrt(-2 * log(w) / w)) + mean;
	}
}

void uniform_kv(KV_PARAMS)
{
	float *data = NULL;
	size_t size = 0;
	float a = 0;
	float b = 1;

	KV_START
		KV_GET(float*, data);
			data = _data;
		KV_NEXT
		KV_GET_INT(size)
			size = _size;
		KV_NEXT
		KV_GET_FLOAT(start)
			a = (float)_start;
		KV_NEXT
		KV_GET_FLOAT(stop)
			b = (float)_stop;
		KV_NEXT
	KV_END
	
	uniform(data, size, a, b);
}

void normal_kv(KV_PARAMS)
{
	float *data = NULL;
	size_t size = 0;
	float mean = 0;
	float var = 1;

	KV_START
		KV_GET(float*, data);
			data = _data;
		KV_NEXT
		KV_GET_INT(size)
			size = _size;
		KV_NEXT
		KV_GET_FLOAT(mean)
			mean = (float)_mean;
		KV_NEXT
		KV_GET_FLOAT(var)
			var = (float)_var;
		KV_NEXT
	KV_END

	normal(data, size, mean, var);
}
