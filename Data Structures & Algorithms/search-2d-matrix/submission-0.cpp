class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int height = matrix.size();
        int width = matrix[0].size();

        int top = 0;
        int bottom = height - 1;
        int left = 0;
        int right = width - 1;

        while (left <= right && top <= bottom){
            int midRow = top + ((bottom - top)/2);
            int midCol = left + ((right - left)/2);
            // cout << matrix[midRow][midCol] << "\n";

            if (matrix[midRow][midCol] > target){
                if (midCol - 1 >= 0){
                    right = midCol - 1;
                } else {
                    bottom = midRow - 1;
                    left = 0;
                    right = width - 1;
                }
            } else if (matrix[midRow][midCol] < target){
                if (midCol + 1 < width){
                    left = midCol + 1;
                } else {
                    top = midRow + 1;
                    left = 0;
                    right = width - 1;
                }
            } else {
                return true;
            }
        }
        return false;  
    }
};
