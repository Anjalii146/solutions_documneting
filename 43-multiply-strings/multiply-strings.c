#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* multiply(char* num1, char* num2) {
    int m = strlen(num1);
    int n = strlen(num2);

    if (strcmp(num1, "0") == 0 || strcmp(num2, "0") == 0)
        return "0";

    int *res = (int*)calloc(m + n, sizeof(int));

    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + res[i + j + 1];

            res[i + j + 1] = sum % 10;
            res[i + j] += sum / 10;
        }
    }

    // Convert to string
    char *result = (char*)malloc(m + n + 1);
    int k = 0, i = 0;

    // Skip leading zeros
    while (i < m + n && res[i] == 0) i++;

    while (i < m + n) {
        result[k++] = res[i++] + '0';
    }

    result[k] = '\0';

    free(res);
    return result;
}