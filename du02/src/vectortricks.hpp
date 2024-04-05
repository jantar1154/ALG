#ifndef H_VECTORTRICKS
#define H_VECTORTRICKS

#include <vector>

using std::vector;

int randint(int min, int max);

void init_vec(vector<int> *vec, int num);

void sort_vec(vector<int> *vec);

void swap(int &n1, int &n2);

void print_vec(const vector<int> *vec);

#endif