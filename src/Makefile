CC = gcc -c
FLAGS = -Wall -Werror -Wextra
SOURCE = s21*.c
TEST = tests/test*.c
SOURCE_OBJ = s21*.o
TEST_OBJ = tests/test*.o
VALGRIND_FLAGS=--trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all --verbose

all: s21_string.a

valgrind: valgrind_build clean_o clean_a

valgrind_build: s21_string.a
	gcc $(TEST) -L. -lcheck -lsubunit s21_string.a -lm -o test_exec
	CK_FORK=no valgrind $(VALGRIND_FLAGS) --log-file=RESULT_VALGRIND.txt ./test_exec


s21_string.a: str.a clean_o

str.a:
	$(CC) $(FLAGS) $(SOURCE)
	ar cr s21_string.a *.o
	ranlib 	s21_string.a

test: test_build clean_o

test_build: s21_string.a
	gcc s21_string.a $(TEST) $(FLAGS) -lm -lpthread -lcheck -o check_filetest && ./check_filetest

gcov_report: clean_r report clean

report:
	gcc -fprofile-arcs -ftest-coverage $(SOURCE) $(TEST) -o s21_test -lcheck
	./s21_test
	lcov -t "test" -o *.info -c -d .
	genhtml -o report/ *.info
	open ./report/index.html

clean_o:
	rm -rf *.o

clean_a:
	rm -rf *.a

clean:
	rm -rf *.o | rm -rf *.a && rm -rf *.so | rm -rf hello* | rm *filetest | rm source/*.gch | rm tests/*.gch | rm *.gcno | rm *.gcda | rm s21_test | rm *.info | rm *_exec | rm RESULT_VALGRIND.txt | rm -rf test_exec*

clean_all: clean clean_o

clean_gcov:
	rm *.gcda | rm *.gcno

clean_r:
	rm -rf report

check:
	clang-format -style=Google -n ./*/*.c

install_brew:
	cd ~
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
	brew install lcov

rebuild: clean all



