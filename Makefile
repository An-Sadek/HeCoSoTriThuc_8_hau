
test:
	g++ -o bin/test tests/test.cpp -Ilib src/_8_queens.cpp
	bin/test

run:
	g++ -o main main.cpp src/_8_queens.cpp -Ilib
	./main 3 3

history:
	g++ -std=c++23 -o bin/history tests/run_history.cpp src/history.cpp -Ilib
	bin/history 3 3