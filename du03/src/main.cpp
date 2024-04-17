#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

string arr_to_str(const vector<int>& array) {
    std::stringstream ss;
    ss << "(";
    for (size_t i = 0; i < array.size(); ++i) {
        ss << array[i];
        if (i+1 != array.size()) ss << " ";
    }
    ss << ")";
    return ss.str();
}

void vec_init(vector<int>& vec, int initial, size_t len) {
    vec.reserve(len);
    for (size_t i = 0; i < len; ++i) {
        vec.emplace_back(i) = initial;
    }
}

int main() {
    static const int input[4][4] = {
                // JOB  1  2  3  4
        /* Person 1 */ {9, 2, 7, 8,},
        /* Person 2 */ {6, 4, 3, 7,},
        /* Person 3 */ {5, 8, 1, 8,},
        /* Person 4 */ {7, 6, 9, 4,},
    };

    vector<int> assignment = {0, 1, 2, 3,};
    vector<int> best_permutation;
    
    vec_init(best_permutation, 9, 4);

    vector<int> cost;
    vec_init(cost, 0, 24);
    
    int max_cost = -1;

    int perm_count = 0;
    // Iterate through every possible assignment
    do {
        for (int i = 0; i < 4; ++i) {
            cost.at(perm_count) += input[assignment.at(i)][i];
        }
        cout << arr_to_str(assignment) << " -> "; 
        cout << "cost: " << cost.at(perm_count) << endl;
        // Find best permutation
        if (cost.at(perm_count) > max_cost) {
            max_cost = cost.at(perm_count);
            best_permutation = assignment;
        }
        perm_count ++;
    } while (std::next_permutation(std::begin(assignment), std::end(assignment)));

    cout << "best permutation: " << arr_to_str(best_permutation);
    cout << ", cost: " << max_cost << endl;

    return 0;
}