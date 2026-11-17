class Solution {
public:

    int getArea(vector<int>& heights, int left, int right){
        return min(heights[left], heights[right]) * (right - left);
    }

    int maxArea(vector<int>& heights) {

        int left = 0;
        int right = heights.size() - 1;
        int maxArea = 0;

        while (left < right){
            int curArea = getArea(heights, left, right);
            maxArea = max(curArea, maxArea);

            if (heights[left] < heights[right]){
                left++;
            } else if (heights[right] < heights[left]){
                right--;
            } else {
                left++;
                right--;
            }
        }
        return maxArea;
    }
};
