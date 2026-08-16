class Solution {
    public double findMaxAverage(int[] nums, int k) {

        // Calculate the sum of the first window of size k
        int windowSum = 0;

        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        // Store the maximum sum found so far
        int maxSum = windowSum;

        // Slide the window through the array
        for (int i = k; i < nums.length; i++) {

            // Remove the element leaving the window
            // and add the new element entering the window
            windowSum = windowSum - nums[i - k] + nums[i];

            // Update maximum sum if current window is larger
            maxSum = Math.max(maxSum, windowSum);
        }

        // Average = maximum sum / number of elements
        return (double) maxSum / k;
    }
}