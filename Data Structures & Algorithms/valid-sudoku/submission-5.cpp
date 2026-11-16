class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rowsSet(9);
        vector<unordered_set<char>> columnsSet(9);
        vector<unordered_set<char>> subBoxesSet(9);

        for (int col = 0; col < board[0].size(); col++){
            for (int row = 0; row < board.size(); row++){
                if (board[row][col] == '.'){
                    continue;
                }

                auto result = rowsSet[row].insert(board[row][col]);
                if (!result.second){
                    return false;
                }

                result = columnsSet[col].insert(board[row][col]);
                if (!result.second){
                    return false;
                }

                int subBox = ((row / 3) * 3) + (col / 3);
                result = subBoxesSet[subBox].insert(board[row][col]);
                if (!result.second){
                    return false;
                }
            }
        }
        return true;
    }
};
