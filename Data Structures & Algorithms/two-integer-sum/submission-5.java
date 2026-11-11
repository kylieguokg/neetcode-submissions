class Solution {
    public int[] twoSum(int[] nums, int target) {
        var searchingFor = new HashMap<Integer, Integer>();

        for (int i = 0; i < nums.length; i++){
            var matchingNumIndex = searchingFor.getOrDefault(target - nums[i], -1);
            if (matchingNumIndex != -1){
                return new int[]{matchingNumIndex, i};
            }
            searchingFor.put(nums[i], i);
        }
        return new int[2];
    }
}
