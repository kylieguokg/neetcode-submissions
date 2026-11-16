class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {};
        bool cols[9][9] = {};
        bool subBoxes[9][9] = {};
        vector<unordered_set<char>> subBoxesSet(9);

        for (int col = 0; col < 9; col++){
            for (int row = 0; row < 9; row++){
                char num = board[row][col];
                if (num == '.'){
                    continue;
                }
                int digit = num - '1';

                int subBox = ((row / 3) * 3) + (col / 3);
                if (rows[row][digit] ||
                    cols[col][digit] ||
                    subBoxes[subBox][digit])
                {
                    return false;
                }
                
                rows[row][digit] = true;
                cols[col][digit] = true;
                subBoxes[subBox][digit] = true;
            }
        }
        return true;
    }
};
