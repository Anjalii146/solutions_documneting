int heightChecker(int* heights, int heightsSize) {

    int expected[100];

    // Copy original array
    for(int i = 0; i < heightsSize; i++)
    {
        expected[i] = heights[i];
    }

    // Insertion Sort
    for(int i = 1; i < heightsSize; i++)
    {
        int key = expected[i];
        int j = i - 1;

        while(j >= 0 && expected[j] > key)
        {
            expected[j + 1] = expected[j];
            j--;
        }

        expected[j + 1] = key;
    }

    // Count mismatches
    int count = 0;

    for(int i = 0; i < heightsSize; i++)
    {
        if(heights[i] != expected[i])
        {
            count++;
        }
    }

    return count;
}