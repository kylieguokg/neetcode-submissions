class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            // if (left == right){
            //     break;
            // }

            // if mid > right -> right half is sorted half
            if (nums[mid] < nums[right]) {
                // in sorted right half
                if (mid + 1 < n &&
                    nums[mid + 1] <= target && target <= nums[right]) {
                    left = mid + 1;
                } else if (mid - 1 >= 0) {
                    // in rotated left half
                    right = mid - 1;
                } else {
                    break;
                }
            } else {
                // else -> right half is rotated half
                if (mid - 1 >= 0 &&     nums[left] <= target && target <= nums[mid - 1]) {
                    // in sorted left half
                    right = mid - 1;
                } else if (mid + 1 < n) {
                    // in rotated right half
                    left = mid + 1;
                } else {
                    break;
                }
            }
        }
        return -1;
    }
};
