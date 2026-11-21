/**
flatten 2D to 1D array since always non-decreasing
**/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int height = matrix.size();
        int width = matrix[0].size();

        int left = 0;
        int right = height * width - 1;

        while (left <= right){
            int mid = left + ((right - left)/2);

            // middle row col - divided by width
            int row = mid / width;
            int col = mid % width;

            if (matrix[row][col] > target){
                right = mid - 1;
            } else if (matrix[row][col] < target){
                left = mid + 1;
            } else {
                return true;
            }
        }
        return false;
        
    }
};
