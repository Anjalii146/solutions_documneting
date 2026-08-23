class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int n = temperatures.length;
        int[] answer = new int[n];

        // Stack stores indices of temperatures
        int[] stack = new int[n];
        int top = -1;

        for (int i = 0; i < n; i++) {

            // Remove indices whose temperature is smaller
            while (top >= 0 &&
                   temperatures[i] > temperatures[stack[top]]) {

                int previousDay = stack[top--];

                answer[previousDay] = i - previousDay;
            }

            // Add current day's index
            stack[++top] = i;
        }

        return answer;
    }
}