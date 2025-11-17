
test:
	g++ -o test test.cpp _8_queens.cpp
	./test

run:
	g++ -o main main.cpp _8_queens.cpp
	./main 3 3

history:
	g++ -std=c++23 -o history run_history.cpp history.cpp
	./history 3 3