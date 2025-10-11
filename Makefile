
test:
	g++ -o test test.cpp _8_queens.cpp
	./test

run:
	g++ -o main main.cpp _8_queens.cpp
	./main 1