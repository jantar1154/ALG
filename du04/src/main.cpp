#include <iostream>
#include "8puzzle.h"

using std::cout;
using std::endl;

/*
    Reseni v Haskellu
    type Result = [String]

    pp :: Result -> IO ()
    pp x = putStr (concat (map (++ "\n") x))

    puzzle2 :: Result
    puzzle2 = ["AC DE",
               "FBHIJ",
               "KGLNO",
               "PQMRS",
               "UVWXT"]

    puzzle :: Result -> [Char] -> Result
    puzzle res [] = res
    puzzle res (y:ys) = puzzle (swap y res) ys where
        swap :: Char -> Result -> Result
        swap c = map (swap' c) where
            swap' :: Char -> String -> String
            swap' c' = map (\x -> if x == c' then ' ' else if x == ' ' then c' else x)
*/

int main() {
    // // Nejde
    // const board mat = {
    //     1, 3, 0,
    //     4, 8, 5,
    //     7, 2, 6,
    // };

    // // Nejde
    // const board mat = {
    //     2, 1, 0,
    //     3, 4, 5,
    //     6, 7, 8,
    // };

    // Jde
    const board mat = {
        7, 4, 8,
        0, 1, 3,
        6, 5, 2,
    };

    // // Jde
    // const board mat = {1,0,2,3};

    // // Jde (duh)
    // const board mat = {
    //     0, 1, 2,
    //     3, 4, 5,
    //     6, 7, 8,
    // };

    const int found = ep::depth_search(mat, 0, false);

    if (-1 != found) {
        cout << "Found! Iterations: " << found;
    } else {
        cout << "There is no way to complete the puzzle!";
    }
    cout << endl;

    return 0;
}