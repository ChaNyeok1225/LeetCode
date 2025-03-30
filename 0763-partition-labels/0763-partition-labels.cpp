class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();

        vector<int> result;
        vector<pair<int, int>> index(27, {n, 0});

        for(int i = 0; i < n; i++) {
            int alpha = s[i] - 'a';
            index[alpha].first = min(index[alpha].first, i);
            index[alpha].second = max(index[alpha].second, i);
        }

        sort(index.begin(), index.end());
        int curS = 0;
        int curE = index[0].second;
        for(auto range : index) {
            if(curE < range.first) {
                result.push_back(curE - curS + 1);
                curS = range.first;
                curE = range.second;
            }
            curE = max(range.second, curE);
            if(range.first == n)
                break;
        }

        return result;
    }
};