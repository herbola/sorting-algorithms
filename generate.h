#ifndef GENERATE_H
#define GENERATE_H

#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <functional>

struct random_pred {
	size_t size;
	random_pred(size_t size):size(size) {
	}
	void operator()(int &n)const {
		n = rand() % (size*10);
	}
};

struct monotonous_pred {
	int start;
	int counter;
	monotonous_pred(int counter, int start) : start(start), counter(counter) {
	}
	void operator()(int &n) {
		counter += start;
		n = counter;
	}
};

class generate
{
public:
	template<typename T>
	static void generate_random(T begin, T end){
		std::for_each(begin, end, random_pred(end-begin));
	}
	template<typename T>
	static void generate_monotonous_rise(T begin, T end) {
		std::for_each(begin, end, monotonous_pred(0,20));
	}
	template<typename T>
	static void generate_monotonous_falling(T begin, T end){
		std::for_each(begin, end, monotonous_pred(3000,-20));
	}
	template<typename T>
	static void generate_constant(T begin, T end){
		std::for_each(begin, end, [](int &n) {
			n = 0;
		});

	}
};




#endif //GENERATE_H
