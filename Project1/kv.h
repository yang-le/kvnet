#pragma once

#include <cstdarg>
#include <cstring>

#define KV_PARAMS					int __start__, ...
#define KV_ARG(type)				va_arg(__params__, type)

#define KV_START							\
	va_list __params__;						\
	va_start(__params__, __start__);		\
	for(;;) {								\
		char *__key__ = KV_ARG(char*);		\
		if(0 == *__key__) break;

#define KV_GET(type, key)			if (0 == strcmp(#key, __key__)) {type _##key = KV_ARG(type);
#define KV_NEXT						continue;}

#define KV_END						break;} va_end(__params__);

#define KV(...)						0, ## __VA_ARGS__, ""
#define KV_CALL(func, ...)			func(KV(__VA_ARGS__))

#define KV_GET_INT(key)				KV_GET(int, key)
#define KV_GET_FLOAT(key)			KV_GET(double, key)
#define KV_GET_CHAR(key)			KV_GET(char, key)

#define KV_GET_PTR(type, key)		KV_GET(const type*, key)
#define KV_GET_STRING(key)			KV_GET_PTR(char, key)

#ifdef __cplusplus
#define KV_GET_BOOL(key)			KV_GET(bool, key)
#endif
