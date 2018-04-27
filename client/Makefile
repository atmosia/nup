# nup-client: client for nup game

NAME = nup-client
SRC = main.c
OBJ = ${SRC:.c=.o}

COV = gcov

TESTS_SRC = $(wildcard t/*.c)
TESTS = ${TESTS_SRC:.c=}

CPPFLAGS = -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_POSIX_C_SOURCE=2 \
	   -DVERSION=\"${VERSION}\"
CFLAGS = -std=c99 -pedantic -Wall -Wno-deprecated-declarations -Os \
	 ${CPPFLAGS} -g -Wextra
CFLAGS += -fprofile-arcs -ftest-coverage
CPPFLAGS += -I../include
LDFLAGS += -L../lib -lpthread -static -lgcov --coverage

all: options ${NAME}

options:
	@echo ${NAME} build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"
	@echo "COV      = ${COV}"


.c.o:
	@echo CC $<
	@${CC} -c ${CFLAGS} $<

${NAME}: ${OBJ} ${EXTERN_OBJ}
	@echo CC -o $@
	@${CC} -o $@ $^ ${LDFLAGS}

test: all ${TESTS}
	@failures=0; \
	for test in "${TESTS}"; do \
		if ! $$test; then \
			failures=$$(( $$failures + 1 )); \
		fi; \
	done; \
	exit $$failures
	@${COV} ${SRC} ${TESTS_SRC}

clean:
	rm -f ${OBJ} ${TESTS}

.PHONY: all options clean
