#ifndef H_8PUZZLE
#define H_8PUZZLE
#include <vector>

typedef std::vector<int> board;

// Prints a vector
#define print_board(v) { for (const int i : v) std::cout << i << " "; std::cout << std::endl; }

namespace ep {
    /// @brief Finds out whether 8-puzzle represented as a vector could be
    /// @brief shifted to {0,1,2,3,4,...}
    /// @param puzzle Initial puzzle vector
    /// @param movable Value that is the "free space"
    /// @param debug Whether there should be debug printing
    /// @return Number of iterations needed to find result of `-1` of nothing was found
    int depth_search(const board& puzzle, int movable, bool debug);
}

#endif