#include "util.h"
#include "stastic.h"
#include <cstdio>

void plot(const float data[], size_t num, float scale, bool show_val)
{
	printf("* = %d\n", (int)(1 / scale));
	for (unsigned int i = 0; i < num; ++i) {
		for (int j = 0; j < data[i] * scale; ++j) putchar('*');
		if (show_val) printf(" %f", data[i] * scale);
		putchar('\n');
	}
}

void hist(float data[], size_t size, float hist[], size_t bins)
{
	float _max = max(data, size);
	float _min = min(data, size);

	memset(hist, 0, bins * sizeof(hist[0]));
	for (unsigned int i = 0; i < size; ++i)
		++hist[(int)(bins * (data[i] - _min) / (_max - _min))];
}

void plot_kv(KV_PARAMS)
{
	const float *data = NULL;
	int num = 0;
	float scale = 1;
	bool show_val = false;

	KV_START
		KV_GET_PTR(float, data)
			data = _data;
		KV_NEXT

		KV_GET_INT(num)
			num = _num;
		KV_NEXT

		KV_GET_FLOAT(scale)
			scale = (float)_scale;
		KV_NEXT

		KV_GET_BOOL(show_val)
			show_val = _show_val;
		KV_NEXT
	KV_END

	plot(data, num, scale, show_val);
}
