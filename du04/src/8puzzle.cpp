#include "8puzzle.h"

#include <iostream>

#include <vector>
#include <stack>
#include <unordered_set>
#include <string>
#include <cmath>
#include <assert.h>

using std::string;
using std::vector;
using std::unordered_set;
using std::stack;
using std::pair;

bool is_success(const board& b) {
    int last = b.at(0);
    for (const int& i : b) {
        if (last > i) return false;
        last = i;
    }
    return true;
}

int get_movable_location(const board& b, int movable) {
    for (size_t i = 0; i < b.size(); ++i) {
        if (b.at(i) == movable) return i;
    }
    return -1;
}

stack<board> make_combinations(const board& b, int movable) {
    stack<board> combinations;
    const int size = sqrtf(b.size());

    const int movable_location = get_movable_location(b, movable);
    assert(movable_location != -1);

    const pair<int, int> potential_switches[4] = {
        {-1,  0}, // -x
        { 1,  0}, // +x
        { 0, -1}, // -y
        { 0,  1}, // +y
    };
    for (const pair<int, int>& p : potential_switches) {
        int new_x = movable_location % size + p.first;
        int new_y = movable_location / size + p.second;
        // check for bounding boxes
        if (new_x < 0 || new_x >= size || new_y < 0 || new_y >= size) continue;
        board new_board = b;
        std::swap(new_board.at(movable_location), new_board.at(new_y * size + new_x));
        combinations.push(new_board);
    }
    return combinations;
}

int ep::depth_search(const board& puzzle, int movable, bool debug) {
    int iterations = 1;
    stack<board> st;
    unordered_set<string> visited;
    st.push(puzzle);

    while (false == st.empty()) {
        const board current = st.top();
        st.pop();
        if (debug) {
            std::cout << "visited ";
            print_board(current);
        }
        if (is_success(current)) return iterations; // If vector is {0,1,2,3,4,...}
        stack<board> combinations = make_combinations(current, movable); // All possible moves you could do
        while (false == combinations.empty()) {
            const board combination = combinations.top();
            combinations.pop();
            string hash = "";
            for (const int &i : combination) hash = std::to_string(i);
            if (visited.find(hash) != visited.end()) continue;
            st.push(combination);
            visited.insert(hash);
        }
        iterations ++;
    }
    return -1;
}