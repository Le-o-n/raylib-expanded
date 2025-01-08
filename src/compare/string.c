
#include "compare/string.h"

int Compare_string(void *key01, void *key02) {
    const char *str1 = (const char *)key01;
    const char *str2 = (const char *)key02;
    return strcmp(str1, str2);
}