CPPFLAGS = -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_POSIX_C_SOURCE=2 \
	   -DVERSION=\"${VERSION}\"
CFLAGS = -std=c99 -pedantic -Wall -Wno-deprecated-declarations -Os \
	 ${CPPFLAGS} -g -Wextra

include ../local.mk
