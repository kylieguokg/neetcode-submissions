class Solution {
    public int[] productExceptSelf(int[] nums) {
        
        int[] products = new int[nums.length];

        // left product first 
        int leftProduct = 1;
        for (int i = 0; i < nums.length; i++){
            products[i] = leftProduct;
            leftProduct *= nums[i];
        }

        // then right product
        int rightProduct = 1;
        for (int i = nums.length - 1; i >= 0; i--){
            products[i] *= rightProduct;
            rightProduct *= nums[i];
        }

        return products;
        
    }
}  
