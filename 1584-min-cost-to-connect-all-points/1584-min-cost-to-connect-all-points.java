import java.util.*;

class Solution {
    public int minCostConnectPoints(int[][] points) {
        int n = points.length;
        int[][] conn = new int[n][n];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i==j) continue;
                conn[i][j] = Math.abs( points[i][0] - points[j][0] ) + Math.abs( points[i][1] - points[j][1] );
            }
        }


        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b) -> a[1] - b[1]);
        int[] edge = new int[n];
        boolean[] vis = new boolean[n];
        Arrays.fill(edge, Integer.MAX_VALUE);
        edge[0] = 0;
        pq.offer(new int[] {0, 0});
        int cnt = 0;


        while(!pq.isEmpty()) {
            int[] cur = pq.poll();

            if(vis[cur[0]]) continue;
            vis[cur[0]] = true;
            if(++cnt == n) {
                break;
            }

            for(int i = 0; i < n; i++) {
                if(vis[i] || edge[i] <= conn[cur[0]][i]) continue;
                edge[i] = conn[cur[0]][i];
                pq.offer(new int[] {i, edge[i]});
            }

        }

        int answer = 0;
        for(int i = 0; i < n; i++) {
            answer += edge[i];
        }

        return answer;

    }
}