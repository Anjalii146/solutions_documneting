#include <limits.h>

int thirdMax(int* nums, int numsSize) {
    long long first = LLONG_MIN;
    long long second = LLONG_MIN;
    long long third = LLONG_MIN;

    for (int i = 0; i < numsSize; i++) {
        long long val = nums[i];

       
        if (val == first || val == second || val == third) {
            continue;
        }

        if (val > first) {
            third = second;
            second = first;
            first = val;
        } else if (val > second) {
            third = second;
            second = val;
        } else if (val > third) {
            third = val;
        }
    }

    
    return (third == LLONG_MIN) ? (int)first : (int)third;
}