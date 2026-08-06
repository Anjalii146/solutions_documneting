void merge(int nums[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = 0;

    int temp[right - left + 1];

    while(i <= mid && j <= right)
    {
        if(nums[i] <= nums[j])
            temp[k++] = nums[i++];
        else
            temp[k++] = nums[j++];
    }

    while(i <= mid)
        temp[k++] = nums[i++];

    while(j <= right)
        temp[k++] = nums[j++];

    for(i = left, k = 0; i <= right; i++, k++)
        nums[i] = temp[k];
}

void mergeSort(int nums[], int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;

        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        merge(nums, left, mid, right);
    }
}

int* sortArray(int* nums, int numsSize, int* returnSize)
{
    mergeSort(nums, 0, numsSize - 1);

    *returnSize = numsSize;

    return nums;
}