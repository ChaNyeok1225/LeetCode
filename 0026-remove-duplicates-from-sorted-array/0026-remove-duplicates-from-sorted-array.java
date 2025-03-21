class Solution {
    public int removeDuplicates(int[] nums) {

        int idx = 1;
        for(int i = 1; i < nums.length; i++) {
            if(nums[i] == nums[i-1]) continue;
            nums[idx++] = nums[i];
        }
        
        return idx;
    }
}