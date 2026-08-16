class Solution {
    public boolean isPalindrome(String s) {

        // Two pointers: one starts from the beginning
        // and the other starts from the end.
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {

            // Skip characters that are not letters or digits.
            while (left < right && !Character.isLetterOrDigit(s.charAt(left))) {
                left++;
            }

            // Skip characters that are not letters or digits.
            while (left < right && !Character.isLetterOrDigit(s.charAt(right))) {
                right--;
            }

            // Compare both characters without considering case.
            if (Character.toLowerCase(s.charAt(left)) !=
                Character.toLowerCase(s.charAt(right))) {
                return false;
            }

            // Move both pointers towards the center.
            left++;
            right--;
        }

        // If all characters matched, it is a palindrome.
        return true;
    }
}