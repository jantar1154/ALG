#include <iostream>
#include <vector>
#include <string>

#include "graph.hpp"

using std::cout, std::endl;
using std::string;

void print_matrix(const matrix &M) {
    cout << "  |";
    for (size_t i = 0; i < M.size(); ++i) {
        cout << " " << i+1;
    }
    cout << endl;
    for (size_t i = 0; i < 2 * M.size() + 3; ++i) {
        if (2 == i) {
            cout << "+";
            continue;
        }
        cout << "-";
    }
    cout << endl;
    for (size_t i = 0; i < M.size(); ++i) {
        cout << i+1 << " | ";
        const vector<int> vec = M.at(i);
        for (size_t j = 0; j < M.size(); ++j) {
            const int n = vec.at(j);
            cout << n << " ";
        }
        cout << endl;
    }
}

int main() {
    const char *filename = "input.txt";
    Graph *g1 = new Graph(filename);

    g1->print_graph();

    matrix M = g1->to_matrix();

    print_matrix(M);

    delete g1;
    return 0;
}