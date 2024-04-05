#include "vectortricks.hpp"

#include <time.h>
#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;

int randint(int min, int max) {
    static int seed = time(nullptr);
    srand(seed);
    const int num = min + (rand() % (max - min));
    seed += num + (time(nullptr) % 10);
    return num;
}

void init_vec(vector<int> *vec, int num) {
    vec->reserve(num);
    for (int i = 0; i < num; ++i) {
        const int rand_num = randint(0, 1000);
        vec->push_back(rand_num);
    }
}

using namespace std;
 
// Sorts array a[0..n-1] using Cocktail sort
void sort_vec(vector<int> *vec) {
    int left = 0;
    int right = vec->size() - 1;
    bool sw = true;
 
    while (sw) {
        sw = false;
        for (int i = left; i < right; ++i) {
            if (vec->at(i) <= vec->at(i + 1)) continue;
            std::swap(vec->at(i), vec->at(i + 1));
            sw = true;
        }
        --right;
 
        if (!sw) break;
        sw = false;
 
        for (int i = right - 1; i >= left; --i) {
            if (vec->at(i) <= vec->at(i + 1)) continue;
            std::swap(vec->at(i), vec->at(i + 1));
            sw = true;
        }
        ++left;
    }
}

void print_vec(const vector<int> *vec) {
    for (const int i : *vec) {
        cout << i << endl;
    }
}