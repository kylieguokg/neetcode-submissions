class Solution {
    public int maxSubArray(int[] nums) {

        int maxSum = Integer.MIN_VALUE;
        int curSum = 0;
        int leftIndex, rightIndex = 0;

        for (int i = 0; i < nums.length; i++){
            // take sum if positive
            if (curSum < 0){
                curSum = 0;
                leftIndex = rightIndex;
            } 

            curSum += nums[i];

            if (curSum > maxSum){
                maxSum = curSum;
                rightIndex += 1;
            }
        }
        return maxSum;
    }
}
