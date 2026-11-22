class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        int minNum = nums[left];

        while (left <= right){
            if (nums[left] <= nums[right]){
                minNum = min(nums[left], minNum);
                break;
            }

            int mid = left + (right - left)/2;
            minNum = min(nums[mid], minNum);
            // left side is sorted, move to the right half
            if (nums[mid] >= nums[left]){
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return minNum;
    }
};
