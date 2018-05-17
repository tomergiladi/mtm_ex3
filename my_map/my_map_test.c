#include "map_mtm.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
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
    int ages[] = {21, 18, 9, 15, 5};
    char*(strings[]) = {"atomer", "gaia", "elad", "yaara", "edna"};
    for (int i = 0; i < 4; i++) {
        mapPut(m, strings[i], ages + i);
    }
    for (int i = 0; i < 5; i++) {
        printf("%s is in m? %d\n", strings[i], mapContains(m, strings[i]));
        int* data = mapGet(m, strings[i]);
        printf("%s value in m? %d\n--------------\n", strings[i],
               data ? *data : 0);
    }
    Map m2 = mapCopy(m);
    mapPut(m2, strings[4], ages + 4);
    for (int i = 0; i < 5; i++) {
        printf("%s is in m2? %d\n", strings[i], mapContains(m2, strings[i]));
        int* data = mapGet(m2, strings[i]);
        printf("%s value in m2? %d\n--------------\n", strings[i],
               data ? *data : 0);
    }
    for (int i = 0; i < 4; i++) {
        mapPut(m, strings[i], ages + i);
    }
    for (int i = 0; i < 5; i++) {
        printf("%s is in m? %d\n", strings[i], mapContains(m, strings[i]));
        int* data = mapGet(m, strings[i]);
        printf("%s value in m? %d\n--------------\n", strings[i],
               data ? *data : 0);
    }
    MAP_FOREACH(char*, itr, m) {
        printf("%s value in m? %d\n--------------\n", itr,
               *(int*)mapGet(m, itr));
    }
    mapRemove(m, "elad");
    int d[] = {22};
    mapPut(m, "atomer", d);
    printf("%d", mapGetSize(m));
    MAP_FOREACH(char*, itr, m) {
        printf("%s value in m? %d\n--------------\n", itr,
               *(int*)mapGet(m, itr));
    }
    MAP_FOREACH(char*, itr, m2) {
        printf("%s value in m2? %d\n--------------\n", itr,
               *(int*)mapGet(m2, itr));
    }
    mapClear(m);
    MAP_FOREACH(char*, itr, m) {
        printf("%s value in m? %d\n--------------\n", itr,
               *(int*)mapGet(m, itr));
    }
    mapDestroy(m);
    mapDestroy(m2);
}