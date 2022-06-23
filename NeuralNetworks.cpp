// NeuralNetworks.cpp : Defines the entry point for the application.
//
// cpp_compiler_options_openmp.cpp
#include <omp.h>
#include "headers\NeuralNetworks.h"
#include "headers/Levenshtein.h"
#include <chrono>
#include <thread>

using namespace std;

void doEditDistance() {
	char str1[] = "abcdefghijklmnopqrstuvwxyz", str2[] = "abcdefghijklmnopqrstuvwxyyyz";
	for (int i = 0; i < 100000; i++)
		edit_distance4(str1, str2, sizeof(str1) / sizeof(str1[0]), sizeof(str2) / sizeof(str2[0]));
}

int main()
{
	int fixes = 0;
	std::string x;
	std::string  a = "abcdefghijklmnopqrstuvwxyz", b="abcdefghijklmnopqrstuvwxyyyz";
	char str1[] = "abcdefghijklmnopqrstuvwxyz", str2[] = "abcdefghijklmnopqrstuvwxyyyz";
	int threads = std::thread::hardware_concurrency();
	auto start = std::chrono::high_resolution_clock::now();

	//for (int i = 0; i < 400000; i++)
	//fixes = edit_distance4(str1, str2, sizeof(str1) / sizeof(str1[0]), sizeof(str2) / sizeof(str2[0]));
	std::thread myThreads[8];
	for (int i = 0; i < threads; i++)
		myThreads[i]=std::thread(doEditDistance);
	for (int i = 0; i < threads; i++)
		myThreads[i].join();
	auto finish = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "ns\n";
	std::cout << fixes << " fixes\n";
	//std::cout << std::thread::hardware_concurrency();
	cin >> x;
	return 0;
}
