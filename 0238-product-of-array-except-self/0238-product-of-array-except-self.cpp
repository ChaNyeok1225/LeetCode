class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();

        vector<int> ans(size);
        
        int val = 1;    
        for(int i = 0; i < size; ++i) {
            ans[i] = val;
            val *= nums[i];
        }
        val = 1;
        for(int i = size - 1; i >= 0; --i) {
            ans[i] *= val;
            val *= nums[i];
        }

        return ans;
    }
};