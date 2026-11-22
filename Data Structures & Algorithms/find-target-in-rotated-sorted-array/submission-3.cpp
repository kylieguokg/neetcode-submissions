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

            if (nums[mid] <= target && target <= nums[right]){
                left = mid;
            } else if (nums[left] <= target && target < nums[mid]){
                right = mid;
            }
   
            // if mid > right -> right half is sorted half
            if (nums[mid] < nums[right]) {
                // in sorted right half
                if (nums[mid] <= target && target <= nums[right]){
                    left = mid + 1;
                } else {
                    // in rotated left half
                    right = mid - 1;
                }
            } else {
                // else -> right half is rotated half
                if (nums[left] <= target && target <= nums[mid]) {
                    // in sorted left half
                    right = mid - 1;
                } else {
                    // in rotated right half
                    left = mid + 1;
                } 
            }
        }
        return -1;
    }
};
