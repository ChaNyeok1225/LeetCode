#include <iostream>

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int start = 0;
        int bal = 0;
        int needs = 0;
        for(int i = 0; i < n; ++i) {
            bal += gas[i] - cost[i];
            if(bal < 0) {
                needs += bal;
                bal = 0;
                start = i + 1;
            }
        }    

        if(needs + bal >= 0) return start;
        return -1;
    }
};