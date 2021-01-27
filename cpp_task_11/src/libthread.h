/*
 * libthread.h
 *
 *      Author: user
 */

#ifndef LIBTHREAD_H_
#define LIBTHREAD_H_

#include <iostream>
#include <thread>
#include <random>
#include "glvars.h"

namespace libthread {

void func1(std::vector<int> &mas, float &time) {
	std::cout << "id = " << std::this_thread::get_id() << std::endl;
	int n = mas.size();
	int ma = mas[0], i;
	auto start = std::chrono::high_resolution_clock::now();
	for (i = 1; i < n; i++)
		ma = std::max(ma, mas[i]);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> duration = end - start;
	std::cout << "Local maximum = " << ma << std::endl;
	time = duration.count();
	std::cout << "Duration " << time << " s" << std::endl;
}

void getmax(std::vector<int> &mas, int le, int re) {
	int ma = mas[le];
	int i;
	for (i = le + 1; i <= re; i++)
		ma = std::max(ma, mas[i]);
	glvars::max_loc.push_back(ma);
	std::cout << "id = " << std::this_thread::get_id() << " loc_max = " << ma
			<< std::endl;
}

void manythreads(std::vector<int> &mas, int cnt, float &time) {
	std::cout << "main id = " << std::this_thread::get_id() << std::endl;
	std::vector<std::thread> th_vec;
	int i, a, b, step, ost, n = mas.size();
	step = n / cnt;
	ost = n % cnt;
	std::vector<int> steps(cnt);
	for (i = 0; i < cnt; i++)
		steps[i] = step;
	for (i = 0; i < ost; i++)
		steps[i] += 1;
	int le = 0, re;
	auto start = std::chrono::high_resolution_clock::now();
	for (i = 0; i < cnt; i++) {
		re = le + steps[i] - 1;
		th_vec.push_back(std::thread(getmax, std::ref(mas), le, re)); // @suppress("Symbol is not resolved")
		le = re + 1;
	}
	for (int i = 0; i < cnt; i++)
		th_vec[i].join();
	int ma = glvars::max_loc[0];
	for (i = 1; i < cnt; i++)
		ma = std::max(glvars::max_loc[i], ma);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> duration = end - start;
	std::cout << "Global maximum = " << ma << std::endl;
	time = duration.count();
	std::cout << "Duration " << time << " s" << std::endl;
	if (time < glvars::MIN_TIME) {
		glvars::MIN_TIME = time;
		glvars::cntthreads = cnt;
	}

}

}

#endif /* LIBTHREAD_H_ */
