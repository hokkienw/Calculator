CC = g++
CFLAGS = -Wall -Wextra -Werror --std=c++17
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
TARGET = SmartCalc_v2.a
MODEL= app/model/model.cc app/model/aditional_clases/*.cc app/controller/controller.cc
TEST = s21_test.cc
OS = $(shell uname)
ifeq ($(OS), Linux)
	CHECK_FLAGS = -lgtest -pthread
else
	CHECK_FLAGS = -lgtest -lgtest_main -lpthread
endif

all: install open dvi

install: 
	make clean
	mkdir build
	cd build 
	cd app && qmake && make && make clean && rm Makefile && rm .qmake.stash && cd ../ && mv app/SmartCalc_v2.app build

	
open:
	cd build && open SmartCalc_v2.app

test: 
	$(CC) $(CFLAGS) $(TEST) $(MODEL) ${CHECK_FLAGS} 
	./a.out

gcov_report: $(TARGET)
	$(CC) $(CFLAGS)  $(GCOV_FLAGS) $(TEST) $(SRC) -o unit_test $(FLAGS_PLATFORM)
	./unit_test
	gcov $(TEST)
	lcov -t "test" -o test.info -c -d .
	genhtml -o report/ test.info
	rm -rf *.o *.gcno *.gcda 
	open ./report/index.html

clang:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -i ./app/model/*.h ./app/model/aditional_clases/*.h ./app/model/aditional_clases/*.cc ./app/model/*.cc ./app/controller/*.h ./app/controller/*.cc ./app/view/*.h ./app/view/*.cc ./*cc

clangcheck:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n ./app/model/*.h ./app/model/*.cc ./app/model/aditional_clases/*.h ./app/model/aditional_clases/*.cc ./app/controller/*.h ./app/controller/*.cc ./app/view/*.h ./app/view/*.cc ./*cc

leaks: test
	CK_FORK=no leaks --atExit -- ./a.out

valgrind: test
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./a.out

dvi:
	open ./documentation/doc.pdf

dist: install
	rm -rf Archive_s21_smart_calc
	mkdir Archive_s21_smart_calc 
	cp -a build Archive_s21_smart_calc
	tar -cvzf Archive_s21_smart_calc.tar.gz Archive_s21_smart_calc 

uninstall:
	rm -rf build* 

clean_test:
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf report

clean: 
	rm -rf *.o *.gcno *.gcda *.a *.info report .clang-format s21_test *.out unit_test
	make uninstall
	rm -rf Archive_s21_smart_calc Archive_s21_smart_calc.tar.gz