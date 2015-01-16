class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        vector<char> test;
		 int i = 0, j = 0;

		 for (i = 0; i < 9;i++)
		 {
			 test.clear();
			 for (j = 0; j < 9; j++)
			 {
				 if (board[i][j] != '.')
				 {
					test.push_back(board[i][j]);
				 }
			 }
			 sort(test.begin(), test.end());
			 auto it = unique(test.begin(), test.end());
			 if (it != test.end())
			 {
				 return false;
			 }

		 }
		 
		 for (i = 0; i < 9; i++)
		 {
			 test.clear();
			 for (j = 0; j < 9; j++)
			 {
				 if (board[j][i] != '.')
				 {
					 test.push_back(board[j][i]);
				 }
			 }
			 sort(test.begin(), test.end());
			 auto it = unique(test.begin(), test.end());
			 if (it != test.end())
			 {
				 return false;
			 }

		 }

		 int block = 0;
		 for (block = 0; block < 9; block ++)
		 {
			 int start1 = (block % 3) * 3;
			 int start2 = (block / 3)*3;
			 test.clear();
			 for (i = start1; i < start1+3; i++)
			 {
				 for (j = start2; j < start2 + 3; j++)
				 {
					 if (board[i][j] != '.')
					 {
						 test.push_back(board[i][j]);
					 }
				 }
			 }
			 sort(test.begin(), test.end());
			 auto it = unique(test.begin(), test.end());
			 if (it != test.end())
			 {
				 return false;
			 }
		 }
		 return true;
    }
};
