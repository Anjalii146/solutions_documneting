import java.util.HashSet;

class Solution {
    public boolean containsDuplicate(int[] nums) {

        // Create a HashSet to store unique elements
        HashSet<Integer> set = new HashSet<>();

        // Traverse through the array
        for (int num : nums) {

            // Check if the element already exists
            if (set.contains(num)) {
                return true; // Duplicate found
            }

            // Add the element to the HashSet
            set.add(num);
        }

        // No duplicate was found
        return false;
    }
}