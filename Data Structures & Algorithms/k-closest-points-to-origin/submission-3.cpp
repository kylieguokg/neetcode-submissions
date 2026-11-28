class Solution {
   private:
    struct ComparePoint {
        bool operator()(const vector<int>& a, const vector<int>& b) const {
        return a[0] * a[0] + a[1] * a[1]
             < b[0] * b[0] + b[1] * b[1];
        }
    };

   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, ComparePoint> sortedPoints;

        for (const auto& point : points) {
            sortedPoints.push(point);

            if (sortedPoints.size() > k) {
                sortedPoints.pop();
            }
        }

        vector<vector<int>> result;
        result.reserve(k);

        while (!sortedPoints.empty()){
            result.emplace_back(sortedPoints.top());
            sortedPoints.pop();
        }

        return result;
    }
};
