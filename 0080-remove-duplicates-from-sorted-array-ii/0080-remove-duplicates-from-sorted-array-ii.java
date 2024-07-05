class Solution {
    public int removeDuplicates(int[] nums) {
        
        int idx = 1;
        int cnt = 0;
        for(int i = 1; i < nums.length; i++) {
            if(nums[i] == nums[i-1]) {
                cnt++;
                if(cnt > 1) {
                    continue;
                }
            } else {
                cnt = 0;
            }
            nums[idx++] = nums[i];
        }

        return idx;
    }
}