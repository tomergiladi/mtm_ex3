

typedef struct user_t* User;
User UserCreate(const char* username, int age);
void UserDestroy(User user);
void UserAddFavoriteSeries(User user, const char* seriesName);
void UserRemoveFavoriteSeries(User user, const char* seriesName);
void UserAddFriend(User user, const char* freind_name);
void UserRemoveFriend(User user, const char* freind_name);
