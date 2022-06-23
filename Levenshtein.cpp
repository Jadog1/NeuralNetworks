#include "headers/Levenshtein.h"

unsigned int min(unsigned int a, unsigned int b, unsigned int c) {
	if (a < b && a < c)
		return a;
	else if (b < a && b < c)
		return b;
	else
		return c;
}

//Copied from wiki -- Less efficient due to usage of "string" and "std::vector"
unsigned int edit_distance(const std::string& s1, const std::string& s2)
{
	const std::size_t len1 = s1.size(), len2 = s2.size();
	std::vector<std::vector<unsigned int>> d(len1 + 1, std::vector<unsigned int>(len2 + 1));

	for (unsigned int i = 0; i <= len1; ++i)
		for (unsigned int j = 0; j <= len2; ++j)
			if (i == 0 && j == 0) d[0][0] = 0;
			else if (i == 0) d[0][j] = j;
			else if (j == 0) d[i][0] = i;
			else {
				d[i][j] = min(d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1));
			}
	return d[len1][len2];
}

//Reworking above method for speed
unsigned int edit_distance2(char s1[], char s2[], int len1, int len2)
{
	//int len1 = (sizeof(s1) / sizeof(s1[0])), len2 = (sizeof(s2) / sizeof(s2[0]));
	int d[50][50];

	for (unsigned int i = 0; i <= len1; ++i)
		for (unsigned int j = 0; j <= len2; ++j)
			if (i == 0 && j == 0) d[0][0] = 0;
			else if (i == 0) d[0][j] = j;
			else if (j == 0) d[i][0] = i;
			else {
				d[i][j] = min(d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1));
			}

	return d[len1][len2];
}

int edit_distance3(const std::string& source, const std::string& target) {
	if (source.size() > target.size()) {
		return edit_distance3(target, source);
	}
	const int min_size = source.size(), max_size = target.size();
	std::vector<int> lev_dist(min_size + 1);

	for (int i = 0; i <= min_size; ++i) {
		lev_dist[i] = i;
	}

	for (int j = 1; j <= max_size; ++j) {
		int previous_diagonal = lev_dist[0], previous_diagonal_save;
		++lev_dist[0];

		for (int i = 1; i <= min_size; ++i) {
			previous_diagonal_save = lev_dist[i];
			if (source[i - 1] == target[j - 1]) {
				lev_dist[i] = previous_diagonal;
			}
			else {
				lev_dist[i] = min(lev_dist[i - 1], lev_dist[i], previous_diagonal) + 1;
			}
			previous_diagonal = previous_diagonal_save;
		}
	}

	return lev_dist[min_size];
}

int edit_distance4(char s1[], char s2[], int min_size, int max_size) {
	int* lev_dist = (int*)malloc(((size_t)min_size + 1) * sizeof(int));
	int distance = 0, previous_diagonal, previous_diagonal_save;

	for (int i = 0; i <= min_size; ++i) {
		lev_dist[i] = i;
	}

	for (int j = 1; j <= max_size; ++j) {
		previous_diagonal = lev_dist[0], previous_diagonal_save;
		++lev_dist[0];

		for (int i = 1; i <= min_size; ++i) {
			previous_diagonal_save = lev_dist[i];
			if (s1[i - 1] == s2[j - 1]) {
				lev_dist[i] = previous_diagonal;
			}
			else {
				lev_dist[i] = min(lev_dist[i - 1], lev_dist[i], previous_diagonal) + 1;
			}
			previous_diagonal = previous_diagonal_save;
		}
	}
	distance = lev_dist[min_size];
	free(lev_dist);
	return distance;
}