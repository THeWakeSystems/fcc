CC=gcc
LLVMCC=clang
AR=ar

WARNINGS=-Wall \
	-Wextra \
	-Wconversion \
	-Wshadow \
	-Wcast-qual \
	-Wstrict-prototypes \
	-Winit-self \
	-Wmissing-include-dirs \
	-Wc++-compat \
	-Winline

DEFINE=-D_BSD_SOURCE \
	-D_POSIX_C_SOURCE=199309L \
	-U_FORTIFY_SOURCE

CFLAGS=-std=c99 -g -O3 -pedantic -fPIC ${DEFINE} ${WARNINGS}

LDFLAGS=-lrt

SRCS=$(shell ls *.c)

.SECONDARY:

all : version.unit test_astream test_astream2.instr \
	resteer.unit test_commit us_recovery.unit \
	libsmtx.a libsmtx.so test_recovery sw_queue.noinline.o

version.unit : sw_queue.o
test_commit : commit.o version.o sw_queue.o us_recovery.o
test_astream : sw_queue.o
test_astream.noinline : sw_queue.noinline.o
test_astream2.instr : sw_queue.instr.o
us_recovery.unit : sw_queue.o version.o
libsmtx.a : commit.o version.o sw_queue.o us_recovery.o
libsmtx.so : commit.o version.o sw_queue.o us_recovery.o
test_recovery : us_recovery.o version.o sw_queue.o

%.o : %.c
	${CC} ${CFLAGS} $< -c -o $@

%.s : %.c
	${CC} ${CFLAGS} $< -S -o $@

%.unit.o : %.c
	${CC} ${CFLAGS} -DUNIT_TEST $< -c -o $@

%.noinline.o : %.c
	${CC} ${CFLAGS} -DNO_INLINE $< -c -o $@

%.instr.o : %.c
	${CC} ${CFLAGS} -DINSTRUMENT $< -c -o $@

% : %.o
	${CC} ${CFLAGS} $^ ${LDFLAGS} -o $@

%.a :
	${AR} rcs $@ $^

%.so :
	${CC} ${CFLAGS} ${LDFLAGS} -shared $^ -o $@

%.bc : %.c
	${LLVMCC} ${CFLAGS} $< -c -o $@ -emit-llvm

clean:
	rm -f *~
	rm -f *.o
	rm -f *.d.*
	rm -f *.d
	rm -f *\#
	rm -f *.a
	rm -f *.s
	rm -f *.so
	rm -f *.bc
	rm -f a.out
	rm -f resteer.unit version.unit us_recovery.unit
	rm -f test_astream.noinline
	rm -f test_astream2.instr
	rm -f test_astream
	rm -f test_recovery
	rm -f test_commit

%.d: %.c
	@set -e; rm -f $@; \
	$(CC) -M $(CFLAGS) -DUNIT_TEST $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o \1.unit.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

-include $(SRCS:.c=.d)
