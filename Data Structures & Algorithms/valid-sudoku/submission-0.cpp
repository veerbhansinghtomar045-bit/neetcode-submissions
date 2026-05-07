class Solution {
public:
    bool check(vector<vector<char>>& board,int  row ,int  column, char n) {
        for(int i =0; i<9; i++){
        if(board[row][i] == n) return false;
        if(board[i][column] == n) return false;
        }

        int startrow= (row/3)*3;
        int startcolumn= (column/3)*3;
        for(int i = startrow; i<startrow+3; i++){
            for(int j = startcolumn; j<startcolumn+3; j++){
                if(board[i][j] == n)
                return false;
            }
        }
        return true;
   
    }
     bool isValidSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int column = 0; column < 9; column++) {
                if (board[row][column] == '.') continue;

                char n = board[row][column];

                board[row][column] = '.';

                if (check(board, row, column, n) == false) {
                    return false;
                }

                board[row][column] = n;
            }
        }

        return true;
    }
};
