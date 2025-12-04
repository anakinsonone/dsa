/*
 * Given a 2-D grid of characters board and a string word, return true if the
 * word is present in the grid, otherwise return false.

 * For the word to be present it must be possible to form it with a path in the
 * board with horizontally or vertically neighboring cells. The same cell may
 *  not be used more than once in a word.

 * Example 1:
 * Input:
 * board = [
 *   ["A","B","C","D"],
 *   ["S","A","A","T"],
 *   ["A","C","A","E"]
 * ],
 * word = "CAT"
 * Output: true

 * Example 2:
 * Input:
 * board = [
 *   ["A","B","C","D"],
 *   ["S","A","A","T"],
 *   ["A","C","A","E"]
 * ],
 * word = "BAT"
 * Output: false

 * Constraints:
 * 1 <= board.length, board[i].length <= 5
 * 1 <= word.length <= 10
 * board and word consists of only lowercase and uppercase English letters.
 */

#include <iostream>
#include <string>
#include <vector>

bool dfs(std::vector<std::vector<char>>& board, std::string& word, int r, int c,
         int i) {
  if (i == word.size()) return true;

  if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() ||
      board[r][c] != word[i] || board[r][c] == '#')
    return false;

  board[r][c] = '#';
  bool res =
      dfs(board, word, r + 1, c, i + 1) || dfs(board, word, r - 1, c, i + 1) ||
      dfs(board, word, r, c + 1, i + 1) || dfs(board, word, r, c - 1, i + 1);
  board[r][c] = word[i];
  return res;
}

int main() {
  // inputs
  int rows, cols;
  std::cin >> rows >> cols;
  std::vector<std::vector<char>> board(rows, std::vector<char>(cols));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      std::cin >> board[i][j];
    }
  }
  std::string word;
  std::cin >> word;

  bool res = false;
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      if (dfs(board, word, r, c, 0)) {
        res = true;
        break;
      }
    }
  }

  std::cout << (res ? "true" : "false");

  return 0;
}
