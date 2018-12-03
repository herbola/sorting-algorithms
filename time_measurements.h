#ifndef TIME_MEASUREMENTS_H
#define TIME_MEASUREMENTS_H
#include <vector>
#include <chrono>
#include <map>
#include <list>
#include <functional>
#include <fstream>
#include <string>
#include "generate.h"
#include "sort.h"


using namespace std::chrono;

// plot "file.dat" u 1:2 w l 
struct deviation {
	deviation(double time, int amount) :time(time), amount(amount) {

	}
	double time;
	int amount;
};


struct gnuplot {
	void operator()(const deviation &d, const std::string &algorithm)const {
		std::ofstream outfile;
		outfile.open("dat\\" + algorithm + ".dat", std::fstream::in | std::fstream::out | std::fstream::app);
		outfile << d.amount << " " << d.time << std::endl;
			
	}
};

class time_measurements
{
	std::vector<int>vec;
	int runs = 5;
	std::vector<int> numbers{1000,2000,3000,4000,5000,6000,7000,8000,9000,10000} ;
	std::map<std::string,std::vector<deviation>> deviation_vec;
public:
	time_measurements();
	int exec(std::string algorithm = "");
	void print(std::string algorithm);
	double deviation_function(std::string algorithm);
	// changes vector size
	template <typename T> void change_vec_size(T begin, T end, int &n) {
		vec.resize(n);
		generate::generate_random(std::begin(vec), std::end(vec));
	}
	template<template<typename> typename Functor> void loop_run_algorithm( std::string &algorithm) {
		for (auto e : numbers) {
			for (int i = 0; i < runs; i++) {
				change_vec_size(std::begin(vec), std::end(vec), e);
				run_algorithm<Functor>(std::begin(vec), std::end(vec), e, algorithm);
			}
			gnuplot()(deviation_vec[algorithm].front(), algorithm);
			print(algorithm);
			deviation_vec.erase(deviation_vec.begin());
		}
	}
	template<template<typename> typename  Functor, typename  T> void run_algorithm(T begin, T end, int &n, std::string &algorithm) 	// this function takes operator to algortihm, numbers , what type of algortihm. 
	{
		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		Functor<T>()(begin, end);
		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
		deviation_vec[algorithm].push_back({ time_span.count(), n });
	} 
};


// learned me this here https://stackoverflow.com/questions/1282914/pass-pointer-to-template-function-as-function-argument

#endif