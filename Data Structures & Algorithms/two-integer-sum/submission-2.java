class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> seenNums = new HashMap<>();

        for (int i = 0; i < nums.length; i++){
            
            var diff = target - nums[i];
            var missing = seenNums.get(diff);

            if (missing != null){
                return new int[] {missing, i};
            }

            seenNums.put(nums[i], i);
        }
        return null;
    }
}
