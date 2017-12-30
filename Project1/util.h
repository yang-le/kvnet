#pragma once

#include "kv.h"

void plot(const float data[], size_t num, float scale, bool show_val);
void hist(float data[], size_t size, float hist[], size_t bins);

void plot_kv(KV_PARAMS);