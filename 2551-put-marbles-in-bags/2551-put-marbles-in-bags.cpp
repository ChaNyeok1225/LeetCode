class Solution {
public:


    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();

        priority_queue<long long> maxh;
        priority_queue<long long, vector<long long>, greater<>> minh;

        for(int i = 0; i < n - 1; i++) {
            long long val = (long long)weights[i] + weights[i + 1];
            maxh.push(val);
            minh.push(val);
        }

        long long answer = 0;
        for(int i = 1; i < k; i++) {
            answer += maxh.top() - minh.top();
            maxh.pop(); minh.pop();
        }

        return answer;
    }
};