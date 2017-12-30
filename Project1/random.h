#pragma once

#include "kv.h"

void uniform(float data[], size_t size, float a, float b);
void normal(float data[], size_t size, float mean, float var);

void uniform_kv(KV_PARAMS);
void normal_kv(KV_PARAMS);
