#include "utils.h"
#include "Strings.h"
#include "stdlib.h"
void* stringCopy(void* str) {
    char* new_str = malloc(strlen(str) + 1);
    if (new_str == NULL) {
        return NULL;
    }
    strcpy(new_str, str);
    return new_str;
}
int StringCompare(void* s1, void* s2) {
    return strcmp(s1, s2);
}
// dfsfdas