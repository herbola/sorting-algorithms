
output: time_measurements.o
	g++ -std=c++11 main.cpp time_measurements.o -o output

time_measurements.o: time_measurements.cpp time_measurements.h
	g++ -c -std=c++11 time_measurements.cpp



clean:
	rm *.o output
