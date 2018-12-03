#include "time_measurements.h"



time_measurements::time_measurements()
{  

} 
 
int time_measurements::exec(std::string algorithm) {

	
	algorithm = "std_sort";
	loop_run_algorithm<std_sort>(algorithm);
	
	algorithm = "median_quick_sort";
	loop_run_algorithm<median_quick_sort>(algorithm);

	algorithm = "right_elem_quick_sort";
	loop_run_algorithm<right_elem_quick_sort>(algorithm);

	algorithm = "fast_quick_sort";
	loop_run_algorithm<fast_quick_sort>(algorithm);

	algorithm = "right_elem_quick_sort_own";
	loop_run_algorithm<right_elem_quick_sort_own>(algorithm);

	algorithm = "selection_sort";
	loop_run_algorithm<selection_sort>(algorithm);

	algorithm = "insertion_sort";
	loop_run_algorithm<insertion_sort>(algorithm);
	
	int stop;
	std::cin >> stop;
	return 0;
} 

// https://www.programiz.com/cpp-programming/examples/standard-deviation
double time_measurements::deviation_function(std::string algorithm) {
	double tot_time = 0;
	double std_dev = 0;
	for (auto e : deviation_vec[algorithm]) {
		tot_time+=e.time; 
	} 
	auto n = deviation_vec[algorithm].size(); 
	auto avg = tot_time / n;
	for (auto e : deviation_vec[algorithm]) {
		std_dev += pow(e.time - avg, 2); 
	}
	return sqrt(std_dev / n);
}

void time_measurements::print(std::string algorithm)
{
	/// lägger till i felsökningslistan
	std::cout << "Algorithm: " << algorithm 
		<< ", Runs: " <<runs
		<<", Numbers: " << deviation_vec[algorithm].front().amount
		<< ", Time: " << deviation_vec[algorithm].front().time<< " seconds, " 
		<< "Deviation: " << deviation_function(algorithm) << ", ";
	is_sorted ()(std::begin(vec), std::end(vec));
	std::cout << std::endl;
}




