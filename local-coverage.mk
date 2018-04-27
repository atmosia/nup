COV = gcov
CFLAGS += -fprofile-arcs -ftest-coverage
LDFLAGS += -lpthread -static -lgcov --coverage
