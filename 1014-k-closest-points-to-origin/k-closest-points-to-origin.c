void swap(int **a, int **b)
{
    int *temp = *a;
    *a = *b;
    *b = temp;
}

int distance(int *point)
{
    return point[0] * point[0] + point[1] * point[1];
}

int partition(int **points, int low, int high)
{
    int pivot = distance(points[high]);
    int i = low;

    for(int j = low; j < high; j++)
    {
        if(distance(points[j]) < pivot)
        {
            swap(&points[i], &points[j]);
            i++;
        }
    }

    swap(&points[i], &points[high]);

    return i;
}

void quickSelect(int **points, int low, int high, int k)
{
    if(low >= high)
        return;

    int p = partition(points, low, high);

    if(p == k)
        return;
    else if(p > k)
        quickSelect(points, low, p - 1, k);
    else
        quickSelect(points, p + 1, high, k);
}

int** kClosest(int** points, int pointsSize, int* pointsColSize,
               int k, int* returnSize, int** returnColumnSizes)
{
    quickSelect(points, 0, pointsSize - 1, k);

    *returnSize = k;

    *returnColumnSizes = malloc(k * sizeof(int));

    for(int i = 0; i < k; i++)
        (*returnColumnSizes)[i] = 2;

    return points;
}