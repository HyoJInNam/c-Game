
#include "Utility.h"

bool mStrncpy_s(char* start, unsigned int count, const char* str, unsigned int str_count) {
	if (start == nullptr || str == nullptr) return false;
	if (count < str_count) return false;
	for (int i = 0; i < str_count; i++) {
		*(start + i) = *(str + i);
	}
	return true;
}