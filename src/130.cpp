#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
	void dfs(vector<vector<char>>& board, int i, int j) {
		if (i >= board.size() || j >= board[0].size() ||
			i < 0 || j < 0 || board[i][j] != 'O')
		{
			return;
		}

		board[i][j] = 'F';
		dfs(board, i + 1, j);
		dfs(board, i - 1, j);
		dfs(board, i, j + 1);
		dfs(board, i, j - 1);
	}
public:
	void solve(vector<vector<char>>& board) {

		int width = board.size();
		if (0 == width)
		{
			return;
		}

		int height = board[0].size();

		for (int i = 0; i < width; i++) {
			if (board[i][0] == 'O')
			{
				dfs(board, i, 0);
			}
		}

		for (int j = 0; j < height; j++) {
			if (board[0][j] == 'O')
			{
				dfs(board, 0, j);
			}
		}

		for (int i = 0; i < width; i++) {
			if (board[i][height - 1] == 'O')
			{
				dfs(board, i, height - 1);
			}
		}

		for (int j = 0; j < height; j++) {
			if (board[width - 1][j] == 'O')
			{
				dfs(board, width - 1, j);
			}
		}


		for (int i = 0; i < width; ++i) {
			for (int j = 0; j < height; ++j) {
				if (board[i][j] == 'F')
				{
					board[i][j] = 'O';
				}
				else if (board[i][j] == 'O')
				{
					board[i][j] = 'X';
				}
			}
		}
	}
};

