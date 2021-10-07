//============================================================================
// Name        : cpp_task_11.cpp
// Author      : John Doe
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "libthread.h"
#include "glvars.h"

int main() {
	srand((unsigned int) time(NULL));
	std::vector<int> mas(glvars::N);
	int i;
	int maxznach = 100;
	for (i = 0; i < glvars::N; i++)
		mas[i] = rand() % maxznach + 1;
	std::cout << "Using 1 thread:" << std::endl;
	float time1, time2;
	libthread::func1(mas, time1);
	std::cout << std::endl;
	int maxthreads = 12;
	for (i = 2; i < maxthreads; i++) {
		std::cout << "Using " << i << " threads" << std::endl;
		libthread::manythreads(mas, i, time2);
		glvars::max_loc.clear();
		std::cout << std::endl;
	}
	std::cout << "MINIMAL TIME IS " << glvars::MIN_TIME << " ACHIEVED WITH "
			<< glvars::cntthreads << " THREADS" << std::endl;

	int cnt_th = glvars::cntthreads;
	int n = 20;
	while (true) {
		std::vector<int> mas2(n);
		for (i = 0; i < n; i++)
			mas2[i] = rand() % maxznach + 1;
		std::cout << "for n = " << n << std::endl;
		libthread::func1(mas2, time1);
		std::cout << std::endl;
		libthread::manythreads(mas2, cnt_th, time2);
		std::cout << std::endl;
		if (time2 < time1) {
			std::cout << "STARTING FROM N = " << n << " " << cnt_th
					<< " threads program is better than 1 thread program:"
					<< std::endl;
			std::cout << time2 << " < " << time1 << std::endl;
			break;
		}
		glvars::max_loc.clear();
		n *= 10;
	}
}
