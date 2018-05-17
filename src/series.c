#include "series.h"
struct series_t {
    const char* name;
    int episodesNum;
    Genre genre;
    int max_ages;
    int min_age;
    int episodeDuration;
};

Series SeriesCreate(const char* name,
                    int episodesNum,
                    Genre genre,
                    int* ages,
                    int episodeDuration) {
    return NULL;
}
