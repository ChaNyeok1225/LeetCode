class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {

        int[] answer = new int[nums1.length];

        int idx1 = 0;
        int idx2 = 0;

        int idx = 0;
        int val = 0;
        while(idx1 < m && idx2 <n ) {
            if(nums1[idx1] < nums2[idx2]) {
                val = nums1[idx1++];
            } else {
                val = nums2[idx2++];
            }
            answer[idx++] = val;
        }

        while(idx1 < m) {
            answer[idx++] = nums1[idx1++];
        }
        while(idx2 < n) {
            answer[idx++] = nums2[idx2++];
        }

        for(int i = 0; i < nums1.length; i++) {
            nums1[i] = answer[i];
        }

    }
}