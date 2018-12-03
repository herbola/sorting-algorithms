#ifndef SORT_H
#define SORT_H


// https://github.com/alveko/keithschwarz_cpp/blob/master/Introsort.hh
template<typename T>
T partition(T begin, T end) {

		T left = begin + 1;
		T right = end - 1;
		while (true) {
			while (left < right && !(*right < *begin)) {
				--right;
			}
			while (left < right && *left < *begin) {
				++left;
			}
			if (left == right) break;
			std::iter_swap(left, right);
		}
		if (*begin<*left)
			return begin;
		std::iter_swap(begin, left);
		return left;
	}


template<typename T>
struct right_elem_quick_sort{
	void operator()(T begin, T end)const {
		r_quick_sort(begin, end);
	}
	void r_quick_sort(T begin, T end)const {
		const size_t length = size_t(end - begin);
		if (length < 2) return;
		T pivot = end - 1;
		std::iter_swap(pivot, begin);
		T partitionPoint = partition(begin, end);
		r_quick_sort(begin, partitionPoint);
		r_quick_sort(partitionPoint + 1, end);
	}
};


template<typename T>
struct median_quick_sort  {
	void operator()(T begin, T end)const {
		m_quick_sort(begin, end);
	}
	void m_quick_sort(T begin, T end)const {
		const size_t length = size_t(end - begin);
		if (length < 2) return;
		T pivot = median_of_three(begin, begin + length / 2, end - 1);
		std::iter_swap(pivot, begin);
		T partitionPoint = partition(begin, end);
		m_quick_sort(begin, partitionPoint);
		m_quick_sort(partitionPoint + 1, end);
	}
	T median_of_three(T one, T two,T three)const {
		/* Do all three comparisons to determine which is in the middle. */
		const bool comp12 = *one<*two;
		const bool comp13 = *one<*three;
		const bool comp23 = *two<*three;

		/* Based on the relationships between them, return the proper entry. */
		if (comp12 && comp23) return two;               // 1  < 2  < 3
		if (comp12 && !comp23 && comp13) return three;  // 1  < 3 <= 2
		if (!comp12 && comp13) return one;              // 2 <= 1  < 3
		if (!comp12 && !comp13 && comp23) return three; // 2 <  3 <= 1
		if (comp12 && !comp13) return one;              // 3 <= 1  < 2
		return two;                                     // 3 <= 2 <= 1
	}

};

// finding the min element and puts it to the left
template<class T>
struct selection_sort {
	void operator()(T begin, T end)const {
		while (begin != end) {
			auto min = begin;
			for (auto it = begin; it != end; it++) {
				if (*it < *min) {
					min = it;
				}
			}
			std::iter_swap(min, begin);
			++begin;
		}
	}
};

// rotates till right position
template<class T>
struct insertion_sort {
	void operator()(T begin, T end)const {
		for (auto it = begin; it + 1 != end; it++) {
			if (*it > *(it + 1)) {
				rotate(begin, it + 2);
			}
		}
	}
	void rotate(T begin, T end)const {
		if (begin == end || begin == end - 1) {
			return;
		}
		auto first = *(end - 1);
		auto it = end - 1;
		for (; it != begin; it--) {
			if (first >= *(it - 1)) {
				break;
			}
			*it = *(it - 1);
		}
		*it = first;
	}
};


template <typename T> // egen
struct right_elem_quick_sort_own {
	void operator()(T begin, T end)const {
		right_quick_sort(begin, end);
	}
	void right_quick_sort(T begin, T end)const
	{
		const size_t length = size_t(end - begin);
		if (length < 2) return;
		auto const pivot = end - 1;
		auto right = begin;
		auto left = begin;

		while (right != pivot) {
			if (*right > *pivot) {
				right++;
			}
			else {
				std::iter_swap(left++, right++);
			}
		}
		std::iter_swap(right, left);
		right_quick_sort(begin, left);
		right_quick_sort(left + 1, end);
	}
};

template <typename T> // egen
struct fast_quick_sort {
	void operator()(T begin, T end)const {
		fast_qs(begin, end);
	}
	void fast_qs(T begin, T end)const
	{
		if (begin == end) return;
		auto cur = begin;
		if (++cur == end) return;
		auto mid = begin;
		for (; cur != end; ++cur)
			if (*cur < *begin)
				std::iter_swap(cur, ++mid);
		std::iter_swap(begin, mid);
		fast_qs(begin, mid);
		fast_qs(++mid, end);
	}
};


// Standard Library Sort
template <typename T> 
struct std_sort {
	void operator()(T begin, T end)const {
		std::sort(begin, end);
	}
};




struct is_sorted
{
public:
	template<typename T>
	bool operator()(T begin, T end)const {
		for (auto it = begin; it != end - 1; it++) {
			if (*(it + 1) < *it) {
				std::cout << "not sorted at:" << *it;
				return false;
			}
		}
		std::cout << "is sorted";
		return true;
	}
};


template<typename T>
void printt(T begin, T end) {
	for (auto it = begin; it != end; it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}


/**
std::cout << "left:" << *left << std::endl;
std::cout << "right:" << *right << std::endl;
std::cout << "_left:" << *_left << std::endl;
std::cout << "_right:" << *_right << std::endl;
std::cout << "pivot:" << *pivot << std::endl;
char idiot;
std::cin >> idiot;

**/


/*
template <typename T>
void right_elem_quick_sort_test(T begin, T end) {
const size_t length = size_t(end - begin);
if (length < 2) return;
T pivot = end - 1;
std::iter_swap(pivot, begin);
T partition_point = partition(begin, end);
median_quick_sort(begin, partition_point);
median_quick_sort(partition_point + 1, end);
}*/

#endif