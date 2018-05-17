#include "../../map.h"
#include "../../mtm_ex3.h"
#include "../../set.h"
#include "../series.h"
#include "../user.h"
#include "stdio.h"
#include "stdlib.h"
#include "test_utilities.h"
// dasdsadadssdafdssdsa
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
    // printf("%s:%s :: %d\n", dasdelement1, element2, res);
    return res;
}
bool seriesCreateTest() {
    int ages[2] = {7, 9};
    Series series = SeriesCreate("new series", 32, SCIENCE_FICTION, ages, 34);
    ASSERT_TEST(series != NULL);
    return true;
}
void SeriesTest() {
    printf("\nseries create was :%s\n",
           seriesCreateTest() ? "success" : "fail");
}
bool UserCreateTest() {
    User u = UserCreate("Tomer", 21, NULL);
    bool User_Name_Valid = !strcmp(UserGetUsername(u), "Tomer");
    ASSERT_TEST(User_Name_Valid);
    bool User_age_Valid = UserGetAge(u) == 21;
    ASSERT_TEST(User_age_Valid);
    UserDestroy(u);
    UserStatus status;
    u = UserCreate(NULL, 21, &status);
    bool check_null = u == NULL;
    bool status_not_valid = status == USER_ILLEGAL_USERNAME;
    ASSERT_TEST(check_null && status_not_valid);
    status = USER_SUCCESS;
    u = UserCreate("", 21, &status);
    bool check_empty = u == NULL;
    status_not_valid = status == USER_ILLEGAL_USERNAME;
    ASSERT_TEST(check_empty && status_not_valid);
    status = USER_SUCCESS;
    u = UserCreate("&", 21, &status);
    bool check_non_aldigit = u == NULL;
    status_not_valid = status == USER_ILLEGAL_USERNAME;
    ASSERT_TEST(check_non_aldigit && status_not_valid);
    status = USER_SUCCESS;
    u = UserCreate("432423", 21, &status);
    bool allow_digit = u != NULL;
    status_not_valid = status == USER_SUCCESS;
    ASSERT_TEST(allow_digit && status_not_valid);
    UserDestroy(u);
    u = UserCreate("432423", 2, &status);
    bool check_min_age = u == NULL;
    status_not_valid = status == USER_ILLEGAL_AGE;
    ASSERT_TEST(check_min_age && USER_ILLEGAL_AGE);
    u = UserCreate("432423", 178, &status);
    bool check_max_age = u == NULL;
    status_not_valid = status == USER_ILLEGAL_AGE;
    ASSERT_TEST(check_max_age && USER_ILLEGAL_AGE);
    return true;
}
bool UserCopyTest() {
    User u = UserCreate("Tomer", 21, NULL);
    User u2 = UserCopy(u);
    bool user_Name_Valid = !strcmp(UserGetUsername(u2), "Tomer");
    ASSERT_TEST(user_Name_Valid);
    bool user_age_Valid = UserGetAge(u2) == 21;
    ASSERT_TEST(user_age_Valid);
    UserDestroy(u);
    UserDestroy(u2);
    return true;
}
void UserTest() {
    printf("\nuser create was :%s\n", UserCreateTest() ? "success" : "fail");
    printf("\nuser copy was :%s\n", UserCopyTest() ? "success" : "fail");
}
int main() {
    UserTest();
    SeriesTest();
}