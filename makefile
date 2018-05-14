CC = gcc
OBJS = mtmFlixTest.o
INC = win32/libmtm.a
EXEC = prog
DEBUG_FLAG = -g# now empty, assign -g for debug
COMP_FLAG = -std=c99 -Wall -Werror
%.o : tests/%.c
	$(CC) -c $(CFLAGS) $(COMP_FLAG) $(DEBUG_FLAG) $< -o $@
%.o : %.c
	$(CC) -c $(CFLAGS) $(COMP_FLAG) $(DEBUG_FLAG) $< -o $@
$(EXEC) : $(OBJS) $(INC)
	$(CC) $(DEBUG_FLAG) $(OBJS) -Lwin32 -lmtm -o $@
mtmFlixTest.o :set.h map.h
clean:
	DEL $(OBJS) $(EXEC)