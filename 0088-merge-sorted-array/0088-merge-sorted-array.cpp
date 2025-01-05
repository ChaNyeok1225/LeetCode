#include <iostream>
using namespace std;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int size = m + n;        
        int* arr = new int[size];

        int index1 = 0;
        int index2 = 0;
        int p = 0;
        while(index1 < m && index2 < n) {
            if(nums1[index1] < nums2[index2]) {
                arr[p++] = nums1[index1++];
            } else {
                arr[p++] = nums2[index2++];
            }
        }    

        while(index1 < m) {
            arr[p++] = nums1[index1++];
        }
        while(index2 < n) {
            arr[p++] = nums2[index2++];
        }

        for(int i = 0; i < size; i++)
            nums1[i] = arr[i];

        delete[] arr;
        arr = nullptr;
    }
};