class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        pair<int, int> find = {0, 0};
        vector<int> res;
        vector<int> index(n);
        vector<int> arr(n, -1);
        vector<int> count(n, 0);

        for(int i = 0; i < n; i++)
            index[i] = i;
        sort(index.begin(), index.end(), [&](int a, int b) { return nums[a] < nums[b]; } );

        for(int i = n - 1; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                int cnt = 0;
                int cur = j;
                while(cur >= 0 && valid(nums, index[i], index[cur])) {
                    cnt++;
                    cur = arr[cur];
                }
                if(count[i] < cnt) {
                    count[i] = cnt;
                    arr[i] = j;
                }
                if(find.first < count[i]) {
                    find = {count[i] , i};
                }
            }
        }

        int cur = find.second;
        while(cur != -1) {
            res.push_back(nums[index[cur]]);
            cur = arr[cur];
        }

        // for(int i = 0; i < n; i++) {
        //     printf("%d: %d, %d, %d \n", i, index[i], arr[i], count[i]);
        // }
        // printf("FIND : %d, %d", find.first, find.second);

        return res;
    }

    bool valid(vector<int> &nums, int a, int b) {
        return nums[a] % nums[b] == 0 || nums[b] % nums[a] == 0;
    }
};