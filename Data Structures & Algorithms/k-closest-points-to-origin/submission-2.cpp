class Solution {
   private:
    struct ComparePoint {
        bool operator()(const vector<int>& a, const vector<int>& b) const {
            double aDistance = sqrt(pow(a[0], 2) + pow(a[1], 2));
            double bDistance = sqrt(pow(b[0], 2) + pow(b[1], 2));
            return aDistance < bDistance;
        }
    };

   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, ComparePoint> sortedPoints(points.begin(), points.end());

        while (sortedPoints.size() > k){
            sortedPoints.pop();
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
