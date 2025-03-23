class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int answer = 0;

        vector<int> total;
        total.resize(n, 1);
        for(int i = 1; i < n; ++i) {
            if(ratings[i - 1] < ratings[i])
                total[i] = total[i - 1] + 1;
        }

        for(int i = n - 2; i >= 0; --i) {
            if(ratings[i] > ratings[i + 1])
                total[i] = max(total[i], total[i + 1] + 1);
        }

        for(int x : total)
            answer += x;
        
        return answer;
    }
};