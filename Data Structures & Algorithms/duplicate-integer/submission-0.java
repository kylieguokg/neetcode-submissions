class Solution {
    public boolean hasDuplicate(int[] nums) {
        Set<Integer> seenNums = new HashSet<>();
        for (int num : nums){
            if (!seenNums.add(num)){
                return true;
            }
        }
        return false;
    }
}