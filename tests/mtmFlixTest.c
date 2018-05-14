#include "../map.h"
#include "../set.h"
#include "stdio.h"
#include "stdlib.h"
// dasdsadadssdasdsa
#include "string.h"
typedef MapDataElement (*copyMapDataElements)(MapDataElement);
MapDataElement copyInt(MapDataElement element) {
    int* newInt = malloc(sizeof(int));
    *newInt = *(int*)element;
    return newInt;
}
MapDataElement copyString(MapKeyElement element) {
    char* newString = malloc(sizeof(char) * strlen(element) + 1);
    strcpy(newString, element);
    return newString;
}
void freeInt(MapDataElement element) {
    free(element);
}
void freeString(MapKeyElement element) {
    free(element);
}
int compareString(MapKeyElement element1, MapKeyElement element2) {
    int res = strcmp(element1, element2);
    // printf("%s:%s :: %d\n", element1, element2, res);
    return res;
}
int main() {
    Map m = mapCreate(copyInt, copyString, freeInt, freeString, compareString);
    Set s = setCreate(copyString, freeString, compareString);
    int ages[] = {21, 18, 9, 15};
    mapPut(m, "atomer", ages);
    mapPut(m, "gaia", ages + 1);
    mapPut(m, "elad", ages + 2);
    mapPut(m, "yaara", ages + 3);

    MAP_FOREACH(char*, itr, m) {
        printf("%s : %d\n", itr, *(int*)(mapGet(m, itr)));
    }
    setAdd(s, "def");
    setAdd(s, "xyz");
    setAdd(s, "abv");

    SET_FOREACH(char*, itr, s) { printf("%s :\n", itr); }
}