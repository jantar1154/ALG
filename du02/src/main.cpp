#include <iostream>
#include <algorithm>
#include <chrono>

#include "vectortricks.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    vector<int> *intvec = new vector<int>;
    vector<int> *intvec2 = new vector<int>;
    
    // Init array
    init_vec(intvec, 1'000);
    *intvec2 = *intvec;

    auto start = std::chrono::high_resolution_clock::now();
    std::sort(intvec->begin(), intvec->end());
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    cout << "Built-in sort: " << duration.count()*1000 << "ms" << endl;

    start = std::chrono::high_resolution_clock::now();
    sort_vec(intvec2);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "Shake sort: " << duration.count()*1000 << "ms" << endl;

    delete intvec;
    delete intvec2;

    return 0;
}