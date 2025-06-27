DEBUG_CFLAGS = -g3 -Wpedantic -Wextra -Werror -march=native -mtune=native -Wshadow 
CFLAGS = -O3 -march=native -mtune=native
FILES = bern.c bin.c pnc.c
OUTPUT = simulator

sim:
	gcc -o ${OUTPUT} ${CFLAGS} -lm ${FILES}

debug:
	gcc -o ${OUTPUT}_debug ${DEBUG_CFLAGS} -lm ${FILES}
