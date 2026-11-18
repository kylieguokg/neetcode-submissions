class Solution {
public:
    int trap(vector<int>& height) {
        vector<pair<int, int>> maxLeftRight(height.size());

        int maxLeftHeight = 0;
        for (int i = 0; i < height.size(); i++){
            maxLeftRight[i].first = maxLeftHeight;
            maxLeftHeight = max(maxLeftHeight, height[i]);
        }

        int maxRightHeight = 0;
        for (int i = height.size() - 1; i >= 0; i--){
            maxLeftRight[i].second = maxRightHeight;
            maxRightHeight = max(maxRightHeight, height[i]);
        }
        
        int total = 0;
        for (int i = 0; i < height.size(); i++){
            total += max(min(maxLeftRight[i].first, maxLeftRight[i].second) - height[i], 0);
        }
        return total;
    }
};
