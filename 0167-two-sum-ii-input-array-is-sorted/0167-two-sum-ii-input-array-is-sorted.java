class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int[] answer = new int[2];
        
        int n = numbers.length;

        int sum = Integer.MIN_VALUE;
        int j = 1;
        for(int i = 0; i < n; i++) {
            sum = numbers[i] + numbers[j];

            while(j < n - 1 && sum < target) {
                sum = numbers[i] + numbers[++j];
            }

            if(sum == target) {
                answer[0] = i + 1;
                answer[1] = j + 1;
                break;
            }

            while(j > i + 1 && sum > target) {
                sum = numbers[i] + numbers[--j];
            }

            if(sum == target) {
                answer[0] = i + 1;
                answer[1] = j + 1;
                break;
            }

        }
        
        return answer;
    }
}