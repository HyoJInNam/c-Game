
#include "mString.h"

bool mStrncpy_s(char* start, int count, const char* str, int str_count) {
	if (count < str_count) return false;
	for (int i = 0; i < str_count; i++) {
		*(start + i) = *(str + i);
	}
	return true;
}