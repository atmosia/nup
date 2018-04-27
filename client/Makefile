# nup-client: client for nup game

NAME = nup-client
SRC = main.c
OBJ = ${SRC:.c=.o}


TESTS_SRC = $(wildcard t/*.c)
TESTS = ${TESTS_SRC:.c=}

include ../config.mk

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
	@${CC} -o $@ $^ ${CFLAGS} ${CPPFLAGS} ${LDFLAGS}

${TESTS}:
	@echo CC -o $@
	@${CC} -o $@ $@.c ${CFLAGS} ${CPPFLAGS} ${LDFLAGS}

test: all ${TESTS}
	@failures=0; \
	for test in "${TESTS}"; do \
		echo running $$test; \
		if ! $$test; then \
			failures=$$(( $$failures + 1 )); \
		fi; \
	done; \
	exit $$failures
	@if test ! -z "${COV}"; then \
		${COV} -pb $$(find . -name '*.gcno'); \
	fi

clean:
	rm -f ${OBJ} ${TESTS}

.PHONY: all options clean
