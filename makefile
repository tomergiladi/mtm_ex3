CC = gcc
SRCS = src/user.c src/series.c src/tests/mtmFlixTest.c src/utils.c
#OBJS = mtmFlixTest.o user.o utils.o 
OBJS = $(notdir $(SRCS:.c=.o))
INC = win32/libmtm.a
EXEC = prog
DEBUG_FLAG = -g# now empty, assign -g for debug
COMP_FLAG = -std=c99 -Wall -Werror
A = $(shell cmd //c $(CC) -MM $(SRCS) > dep.d)
$(A)
$(EXEC) : $(OBJS) $(INC)
	$(CC) $(DEBUG_FLAG) $(OBJS) -Lwin32 -lmtm -o $@
%.o : 
	$(CC) -c $(CFLAGS) $(COMP_FLAG) $(DEBUG_FLAG) $< -o $@
%.o :
	$(CC) -c $(CFLAGS) $(COMP_FLAG) $(DEBUG_FLAG) $< -o $@

-include dep.d

clean:
	cmd //c del  $(OBJS) $(EXEC)