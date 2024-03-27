#ifndef H_MATRIX
#define H_MATRIX

#include <unordered_map>
#include <vector>
#include <string>

#define matrix std::vector<std::vector<int>>

using std::unordered_map;
using std::vector;
using std::string;
using std::pair;

class Graph {
    private:
        void add_vertex(pair<int, vector<int>> pair);
        int vertex_c;
        int edge_c;
        int largest_vertex;

    public:
        unordered_map<int, vector<int>> list;
        Graph(int vertex_c, int edge_c);
        Graph(string filename);
        void print_graph();
        matrix to_matrix();
};

#endif