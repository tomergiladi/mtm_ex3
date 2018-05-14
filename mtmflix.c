#include "MtmFlix.h"
#include "map.h"
struct mtmFlix_t {
    Map users;
};
static MapDataElement copyInt(MapDataElement element) {
    int* newInt = malloc(sizeof(int));
    *newInt = *(int*)element;
    return newInt;
}
static MapDataElement copyString(MapKeyElement element) {
    char* newString = malloc(sizeof(char) * strlen(element) + 1);
    strcpy(newString, element);
    return newString;
}
static void freeInt(MapDataElement element) {
    free(element);
}
static void freeString(MapKeyElement element) {
    free(element);
}
static int compareString(MapKeyElement element1, MapKeyElement element2) {
    return strcmp(element1, element2);
}

void mtmFlixDestroy(MtmFlix mtmflix) {
    if (mtmflix != NULL) {
        mapDestroy(mtmflix->users);
        free(mtmflix);
    }
}
MtmFlixResult mtmFlixAddUser(MtmFlix mtmflix, const char* username, int age) {
    if (mtmflix == NULL) {
        return MTMFLIX_NULL_ARGUMENT;
    }
    mapPut(mtmflix->users, username, age);
    return MTMFLIX_SUCCESS;
}