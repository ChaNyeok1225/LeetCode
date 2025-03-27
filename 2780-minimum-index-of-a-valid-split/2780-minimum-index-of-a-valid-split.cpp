class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();

        // 보이어 무어 다수결 투표 알고리즘 (최빈값 탐색)
        int candidate = 0, count = 0;
        for(int num : nums) {
            if(count == 0) candidate = num;
            count += (num == candidate) ? 1 : -1;
        }
        
        int exfreq = 0;
        for(int num : nums) {
            if(num == candidate)
                ++exfreq;
        }

        int curfreq = 0;
        for(int i = 0; i < n; ++i) {
            if(nums[i] == candidate) {
                ++curfreq;
                --exfreq;
            }

            if(curfreq * 2 > i + 1 && exfreq * 2 > n - i - 1)
                return i;
        }
        
        return -1;
    }
};