
#include <iostream>
#include <vector>
#include "generate.h"
#include "sort.h"
#include "time_measurements.h"



template<typename T>
void print(T begin, T end) {
	for (auto it = begin; it != end; it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int main(){
	time_measurements measure_object;
	return measure_object.exec();
}