class Solution {
    public boolean hasDuplicate(int[] nums) {
        var seenNums = new HashSet<Integer>();
        for (int n : nums){
            if (!seenNums.add(n)){
                return true;    
            }
        }
        return false;
    }
}