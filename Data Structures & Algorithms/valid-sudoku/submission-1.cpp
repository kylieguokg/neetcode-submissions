class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<int>> columnsSet;
        unordered_map<int, unordered_set<int>> subBoxesSet;

        for (int row = 0; row < board.size(); row++){
            unordered_set<int> curRow;
            for (int col = 0; col < board[0].size(); col++){
                if (board[row][col] != '.'){
                    auto result = curRow.insert(board[row][col]);
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
        }
        return true;
    }
};
