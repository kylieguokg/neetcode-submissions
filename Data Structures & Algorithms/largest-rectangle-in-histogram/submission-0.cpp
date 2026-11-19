/**
For each bar, find the widest rectangle where this bar is the limiting height
**/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftBoundaries(n, -1);
        vector<int> rightBoundaries(n, n);
        stack<int> smaller;

        // from left
        for (int i = 0; i < heights.size(); i++){
            while (!smaller.empty() && heights[smaller.top()] >= heights[i]){
                smaller.pop();
            }
            if (!smaller.empty()){
                leftBoundaries[i] = smaller.top();
            }
            smaller.push(i);
        }

        smaller = {};

        // from right
        for (int i = heights.size() - 1; i >= 0; i--){
            while (!smaller.empty() && heights[smaller.top()] >= heights[i]){
                smaller.pop();
            }
            if (!smaller.empty()){
                rightBoundaries[i] = smaller.top();
            }
            smaller.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++){
            leftBoundaries[i]++;
            rightBoundaries[i]--;
            int width = rightBoundaries[i] - leftBoundaries[i] + 1;
            int area = width * heights[i];
            maxArea = max(maxArea, width * heights[i]);
        }
        return maxArea;
    }
};

/**
constricted by min (H)
H=7, W=1 -> 7 [7], max = 7
H=1, W=2 -> 2 -> H is smaller -> stack pop [1], max = 7
H=7, W=3 -> 3 -> H is greater -> [7]
H=2

(height, width, area)

[7, 1, 7, 2, 2, 4]
7: [7], W = 1, max = 7
1: 1 < 7 -> [1]
7: (1, 3, 3) or (7, 1, 7) -> pop 1 -> [7]
2: 2 <= 7 -> [2 7]
2: 2 <= 2 -> [2 2 7]
4: 4

// min height
7, 2, 7, 4, 6, 8

1, 3, 6/7->7


**/