/*
 * Valid Sudoku

 * You are given a a 9 x 9 Sudoku board board. A Sudoku board is valid if the
following rules are followed:

 *     Each row must contain the digits 1-9 without duplicates.
 *     Each column must contain the digits 1-9 without duplicates.
 *     Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9
without duplicates.

 * Return true if the Sudoku board is valid, otherwise return false

 * Note: A board does not need to be full or be solvable to be valid.

 * Example 1:
 * Input: board =
 1 2 . . 3 . . . .
 4 . . 5 . . . . .
 . 9 8 . . . . . 3
 5 . . . 6 . . . 4
 . . . 8 . 3 . . 5
 7 . . . 2 . . . 6
 . . . . . . 2 . .
 . . . 4 1 9 . . 8
 . . . . 8 . . 7 9


 * Output: true

 * Example 2:
 * Input: board =
1 2 . . 3 . . . .
4 . . 5 . . . . .
. 9 1 . . . . . 3
5 . . . 6 . . . 4
. . . 8 . 3 . . 5
7 . . . 2 . . . 6
. . . . . . 2 . .
. . . 4 1 9 . . 8
. . . . 8 . . 7 9
 * Output: false

*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

bool isValid(int arr[]) {
  for (int i = 0; i < 10; i++) {
    if (arr[i] > 1)
      return false;
  }
  return true;
}

int main() {
  std::vector<std::vector<char>> board(9);
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      char c;
      std::cin >> c;
      board[i].push_back(c);
    }
  }

  std::unordered_map<int, std::unordered_set<char>> cols;
  std::unordered_map<int, std::unordered_set<char>> rows;
  std::unordered_map<int, std::unordered_set<char>> grids;

  bool res = true;
  for (int r = 0; r < 9; r++) {
    for (int c = 0; c < 9; c++) {
      char cell = board[r][c];
      if (cell == '.')
        continue;

      if (rows[r].count(cell) || cols[c].count(cell) ||
          grids[(r / 3) * 3 + c / 3].count(cell)) {
        res = false;
        break;
      }
      rows[r].insert(cell);
      cols[c].insert(cell);
      grids[(r / 3) * 3 + c / 3].insert(cell);
    }
  }

  std::cout << (res ? "valid" : "invalid");

  return 0;
}
