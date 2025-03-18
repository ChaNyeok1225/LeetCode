#include <iostream>

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();

        int reach = 0;
        for(int i = 0; i < size; ++i) {
            if(reach < i)
                return false;
            reach = max(reach, i + nums[i]);
        }

        return true;
    }
};