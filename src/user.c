#include "user.h"

struct user_t {
    char* username;
    int age;
    Set friends;
    Set favorite_series;
};
static void setStatus(UserStatus* status, UserStatus value) {
    if (status) {
        *status = value;
    }
}
static bool isUsernameValid(const char* username) {
    if (!username || !*username) {
        return false;
    }
    while (*username) {
        bool is_digit = *username > '0' && *username < '9';
        bool is_capital = *username > 'A' && *username < 'Z';
        bool is_lower = *username > 'a' && *username < 'z';
        if (!is_digit && !is_capital && !is_lower) {
            return false;
        }
        username++;
    }
    return true;
}

static bool isAgeValid(int age) {
    return age >= MTM_MIN_AGE && age <= MTM_MAX_AGE;
}
User UserCreate(const char* username, int age, UserStatus* status) {
    if (!isUsernameValid(username)) {
        setStatus(status, USER_ILLEGAL_USERNAME);
        return NULL;
    }
    if (!isAgeValid(age)) {
        setStatus(status, USER_ILLEGAL_AGE);
        return NULL;
    }
    User user = malloc(sizeof(*user));
    if (user == NULL) {
        setStatus(status, USER_OUT_OF_MEMORY);
        return NULL;
    }
    user->username = malloc(sizeof(char) * strlen(username) + 1);
    user->friends = setCreate(stringCopy, free, StringCompare);
    user->favorite_series = setCreate(stringCopy, free, StringCompare);
    if (user->username == NULL || user->favorite_series == NULL ||
        user->friends == NULL) {
        UserDestroy(user);
        setStatus(status, USER_OUT_OF_MEMORY);
        return NULL;
    }
    strcpy(user->username, username);
    user->age = age;
    setStatus(status, USER_SUCCESS);
    return user;
}

const char* UserGetUsername(User user) {
    if (user == NULL) {
        return NULL;
    }
    return user->username;
}
int UserGetAge(User user) {
    if (user == NULL) {
        return -1;
    }
    return user->age;
}
User UserCopy(User user) {
    if (user == NULL) {
        return NULL;
    }
    User new_user = UserCreate(user->username, user->age, NULL);
    if (new_user == NULL) {
        return NULL;
    }
    new_user->friends = setCopy(user->friends);
    new_user->favorite_series = setCopy(user->favorite_series);
    if (new_user->friends == NULL || new_user->favorite_series == NULL) {
        UserDestroy(new_user);
        return NULL;
    }
    return new_user;
}
void UserDestroy(User user) {
    if (user) {
        free(user->username);
        setDestroy(user->favorite_series);
        setDestroy(user->friends);
        free(user);
    }
}
void UserAddFavoriteSeries(User user, const char* series_name) {
    if (user == NULL) {
        return;
    }
    setAdd(user->favorite_series, (SetElement)series_name);
}
void UserRemoveFavoriteSeries(User user, const char* series_name) {
    if (user == NULL) {
        return;
    }
    setRemove(user->favorite_series, (SetElement)series_name);
}
void UserAddFriend(User user, const char* user_name) {
    if (user == NULL) {
        return;
    }
    setAdd(user->friends, (SetElement)user_name);
}
void UserRemoveFriend(User user, const char* user_name) {
    if (user == NULL) {
        return;
    }
    setRemove(user->favorite_series, (SetElement)user_name);
}
int UserCompare(User user1, User user2) {
    return strcmp(UserGetUsername(user1), UserGetUsername(user2));
}