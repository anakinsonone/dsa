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
#include <string>

bool isValid(int arr[]) {
  for (int i = 0; i < 10; i++) {
    if (arr[i] > 1)
      return false;
  }
  return true;
}

int main() {
  std::string sudoku[9][9];

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      std::cin >> sudoku[i][j];
    }
  }

  bool res = true;
  for (int i = 0; i < 9; i++) {
    int rowFreq[10] = {0};
    for (int j = 0; j < 9; j++) {
      if (sudoku[i][j] == ".")
        continue;
      int ele = std::stoi(sudoku[i][j]);
      rowFreq[ele]++;
    }
    if (!isValid(rowFreq)) {
      res = false;
      break;
    }

    int colFreq[10] = {0};
    for (int j = 0; j < 9; j++) {
      if (sudoku[j][i] == ".")
        continue;
      int ele = std::stoi(sudoku[j][i]);
      colFreq[ele]++;
    }
    if (!isValid(colFreq)) {
      res = false;
      break;
    }

    int boxFreq[10] = {0};
    int jStart = (i / 3) * 3;
    int jLimit = jStart + 3;
    int kStart = (i % 3) * 3;
    int kLmit = kStart + 3;
    for (int j = jStart; j < jLimit; j++) {
      for (int k = kStart; k < kLmit; k++) {
        if (sudoku[j][k] == ".")
          continue;
        int ele = std::stoi(sudoku[j][k]);
        boxFreq[ele]++;
      }
    }
    if (!isValid(boxFreq)) {
      res = false;
      break;
    }
  }

  std::cout << (res ? "valid" : "invalid");

  return 0;
}
