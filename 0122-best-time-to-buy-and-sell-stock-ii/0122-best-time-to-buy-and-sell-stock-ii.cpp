class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int answer = 0;
        int min = prices[0];
        int val;
        for(int i = 1; i < prices.size(); ++i) {
            val = prices[i] - min;
            if(val > 0) {
                answer += val;
                min = prices[i];
            }
            
            if(prices[i] < min)
                min = prices[i];
        }

        return answer;
    }
};