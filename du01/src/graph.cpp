#include <iostream>
#include <fstream>
#include <cstring>

#include "graph.hpp"

using std::cout, std::endl;
using std::ifstream;
using std::pair;

#define max(a,b) ((a) > (b) ? (a) : (b))

Graph::Graph(int vertex_c, int edge_c) {
    this->vertex_c = vertex_c;
    this->edge_c = edge_c;
    this->largest_vertex = 0;
}

// Creates a graph from file
Graph::Graph(string filename) {
    this->edge_c = 0;
    this->vertex_c = 0;
    this->largest_vertex = 0;

    ifstream in_stream;
    string line;
    in_stream.open(filename);

    char *tk; // Token

    while (getline(in_stream, line)) {
        tk = strtok(line.data(), ": ");
        const int vertex = std::stoi(tk);

        vector<int> neighbours;
        tk = std::strtok(NULL, ", ");
        while (tk) {
            const int nb = std::stoi(tk);
            neighbours.push_back(nb);
            tk = std::strtok(NULL, ", ");
        }
        pair<int, vector<int>> new_p(vertex, neighbours);

        this->add_vertex(new_p);
    }
    in_stream.close();
}

void Graph::add_vertex(pair<int, vector<int>> pair) {
    this->vertex_c ++;
    this->edge_c += pair.second.size();
    const int max_index = max(this->largest_vertex, pair.first);
    this->largest_vertex = max_index;
    this->list.emplace(pair);
}

void Graph::print_graph() {
    cout << "Graph: " << endl;
    cout << "Vertices: " << this->vertex_c << ", Egdes: " << this->edge_c << endl;
    for (const pair<int, vector<int>> i : this->list) {
        cout << i.first << ": ";
        for (int n : i.second) {
            cout << n << " ";
        }
        cout << endl;
    }
}

void init_matrix(matrix& M, int vertex_c) {
    vector<int> zero;
    for (int i = 0; i < vertex_c; ++i) zero.push_back(0);
    for (int i = 0; i < vertex_c; ++i) M.push_back(zero);
}

matrix Graph::to_matrix() {
    matrix M;
    init_matrix(M, this->largest_vertex);
    for (const pair<int, vector<int>> pair : this->list) {
        const int vertex = pair.first;
        for (const int i : pair.second) {
            M[vertex-1][i-1] = 1;
            M[i-1][vertex-1] = 1;
        }
    }
    return M;
}
