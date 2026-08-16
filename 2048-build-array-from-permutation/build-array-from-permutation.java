class Solution {
    public int[] buildArray(int[] nums) {

        int n = nums.length;

        // Create an array to store the answer
        int[] ans = new int[n];

        // For every index, store nums[nums[i]]
        for (int i = 0; i < n; i++) {
            ans[i] = nums[nums[i]];
        }

        // Return the constructed array
        return ans;
    }
}