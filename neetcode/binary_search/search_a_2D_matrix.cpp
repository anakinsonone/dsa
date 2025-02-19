/*
* You are given an m x n 2-D integer array matrix and an integer target.
* Each row in matrix is sorted in non-decreasing order.
* The first integer of every row is greater than the last integer of the
* previous row.
* Return true if target exists within matrix or false otherwise.
* Can you write a solution that runs in O(log(m * n)) time?

* Example 1:
* Input: matrix = [[1,2,4,8],[10,11,12,13],[14,20,30,40]], target = 10
* Output: true

* Example 2:
* Input: matrix = [[1,2,4,8],[10,11,12,13],[14,20,30,40]], target = 15
* Output: false
*/

#include <iostream>
#include <vector>

int main() {
  // inputs
  int rows, columns, target;
  std::cin >> rows >> columns;
  std::vector<std::vector<int>> matrix(rows, std::vector(columns, 0));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      std::cin >> matrix[i][j];
    }
  }
  std::cin >> target;

  // solution
  int low = 0, high = (rows * columns) - 1;
  bool exists = false;
  while (low <= high) {
    int mid = (low + high) / 2;
    int row = (mid / columns), column = (mid % columns);
    int num = matrix[row][column];

    if (num == target) {
      exists = true;
      break;
    } else if (target < num) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  std::cout << exists;
  std::cout << '\n' << matrix.size();

  return 0;
}
