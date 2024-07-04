import java.util.*;

class Solution {
    public int[] kthSmallestPrimeFraction(int[] arr, int k) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b) -> {
            return Double.compare((double)a[0]/a[1], (double)b[0]/b[1]);
        });
        int n = arr.length;
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                pq.offer(new int[] {arr[i], arr[j]});
            }
        }

        for(int i = 1; i < k; i++) {
            pq.poll();
        }
        return pq.peek();
    }
}