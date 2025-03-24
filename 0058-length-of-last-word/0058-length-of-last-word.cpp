class Solution {
public:
    int lengthOfLastWord(string s) {
        int answer = 0;
        int n = s.length();

        bool flag = false;
        for(int i = n - 1; i >= 0; --i) {
            if(s[i] == ' ') {
                if(flag)
                    break;
                continue;
            } else {
                flag = true;
                answer++;
            }
        }

        return answer;
    }
};