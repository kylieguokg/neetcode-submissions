class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rowsSet(9);
        vector<unordered_set<char>> colsSet(9);
        vector<unordered_set<char>> subBoxesSet(9);

        for (int col = 0; col < 9; col++){
            for (int row = 0; row < 9; row++){
                char digit = board[row][col];
                if (digit == '.'){
                    continue;
                }

                int subBox = ((row / 3) * 3) + (col / 3);
                if (!rowsSet[row].insert(digit).second ||
                    !colsSet[col].insert(digit).second ||
                    !subBoxesSet[subBox].insert(digit).second)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
