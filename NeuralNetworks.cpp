// NeuralNetworks.cpp : Defines the entry point for the application.
//

#include "headers\NeuralNetworks.h"
#include "headers/Levenshtein.h"
#include <chrono>

using namespace std;

int main()
{
	int fixes = 0;
	string x;
	string  a = "abcdefghijklmnopqrstuvwxyz", b="abcdefghijklmnopqrstuvwxyz";
	char str1[] = "abcdefghijklmnopqrstuvwxyz", str2[] = "abcdefghijklmopqrstuvwxyz";
	auto start = std::chrono::high_resolution_clock::now();
	//fixes = edit_distance(a, b);
	fixes = edit_distance2(str1, str2, sizeof(str1) / sizeof(str1[0]), sizeof(str2) / sizeof(str2[0]));
	auto finish = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "ns\n";
	std::cout << fixes << " fixes\n";
	cin >> x;
	return 0;
}
