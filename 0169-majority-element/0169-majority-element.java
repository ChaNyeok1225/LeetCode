import java.util.*;

class Solution {
    public int majorityElement(int[] nums) {

        Arrays.sort(nums);

        int cnt = 1;
        int maxCnt = 1;
        int answer = nums[0];
        for(int i = 1; i < nums.length; i++) {
            if(nums[i-1] == nums[i]) {
                cnt++;
                if(maxCnt < cnt) {
                    answer = nums[i];
                    maxCnt = cnt;
                }
            } else {
                cnt = 1;
            }
        }

        return answer;
                
    }
}