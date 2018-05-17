#ifndef SERIES_H_
#define SERIES_H_
#include "../mtm_ex3.h"
typedef enum {
    SERIES_SUCCESS,
    SERIES_OUT_OF_MEMORY,  // You should exit program after this error
    SERIES_ILLEGAL_NAME,
} SereisStatus;

typedef struct series_t* Series;
Series SeriesCreate(const char* name,
                    int episodesNum,
                    Genre genre,
                    int* ages,
                    int episodeDuration);
Series SeriesCopy(Series series);
void SeriesDestroy(Series series);
// int UserGetAge(User user);
int SeriesCompare(Series series1, Series series2);
#endif