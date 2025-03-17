#include <iostream>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int answer = 0;

        int min = prices[0];
        for(int i = 1; i < prices.size(); ++i) {
            if(answer < prices[i] - min)
                answer = prices[i] - min;
            if(prices[i] < min)
                min = prices[i];
        }

        return answer;
    }
};