
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "series.h"
#include "utils.h"

#include "../list.h"
#include "../mtm_ex3.h"
#include "../set.h"
#ifndef USER_H_
#define USER_H_

typedef struct user_t* User;
typedef enum {
    USER_SUCCESS,
    USER_OUT_OF_MEMORY,  // You should exfsdit program after this error
    USER_ILLEGAL_USERNAME,
    USER_ILLEGAL_AGE,
} UserStatus;

User UserCreate(const char* username, int age, UserStatus* status);
const char* UserGetUsername(User user);
int UserGetAge(User user);
User UserCopy(User user);
void UserDestroy(User user);
void UserAddFavoriteSeries(User user, const char* series_name);
void UserRemoveFavoriteSeries(User user, const char* series_name);
void UserAddFriend(User user, const char* user_name);
void UserRemoveFriend(User user, const char* user_name);
int UserCompare(User user1, User user2);
#endif