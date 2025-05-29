#include <stdio.h>
#include <stdlib.h>
#include "../solutions/solution.c" // Contains NumArray implementation


void printArray(int *nums, int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        if (i > 0)
            printf(", ");
        printf("%d", nums[i]);
    }
    printf("]");
}

int runTest(int *nums, int numsSize,
            int *leftIndices, int *rightIndices, int *expected,
            int queriesSize, int testNum)
{
    printf("\n=== Test Case %d ===\n", testNum);
    printf("Array: ");
    printArray(nums, numsSize);
    printf("\n");

    NumArray *obj = numArrayCreate(nums, numsSize);
    int failed = 0;

    for (int i = 0; i < queriesSize; i++)
    {
        int result = numArraySumRange(obj, leftIndices[i], rightIndices[i]);
        printf("Query %d (sumRange(%d, %d)): ", i + 1, leftIndices[i], rightIndices[i]);

        if (result == expected[i])
        {
            printf("PASSED ✅ (Got %d)\n", result);
        }
        else
        {
            printf("FAILED ❌ (Got %d, Expected %d)\n", result, expected[i]);
            failed = 1;
        }
    }

    numArrayFree(obj);
    printf("=== %s ===\n", failed ? "FAILED" : "PASSED");
    return failed;
}

int main()
{
    printf("Starting NumArray Test Suite...\n");
    printf("==============================\n");

    int totalTests = 0;
    int failedTests = 0;

    // Test Case 1: Original example
    {
        int nums[] = {-2, 0, 3, -5, 2, -1};
        int left[] = {0, 2, 0};
        int right[] = {2, 5, 5};
        int expected[] = {1, -1, -3};
        failedTests += runTest(nums, 6, left, right, expected, 3, ++totalTests);
    }

    // Test Case 2: Single element
    {
        int nums[] = {5};
        int left[] = {0};
        int right[] = {0};
        int expected[] = {5};
        failedTests += runTest(nums, 1, left, right, expected, 1, ++totalTests);
    }

    // Test Case 3: All elements
    {
        int nums[] = {1, 2, 3, 4, 5};
        int left[] = {0};
        int right[] = {4};
        int expected[] = {15};
        failedTests += runTest(nums, 5, left, right, expected, 1, ++totalTests);
    }

    // Test Case 4: Repeated queries
    {
        int nums[] = {10, -5, 7, 3, -2};
        int left[] = {1, 1, 0, 2};
        int right[] = {3, 3, 4, 2};
        int expected[] = {5, 5, 13, 7};
        failedTests += runTest(nums, 5, left, right, expected, 4, ++totalTests);
    }

    // Test Case 5: Large array
    {
        int nums[1000];
        for (int i = 0; i < 1000; i++)
            nums[i] = 1;
        int left[] = {0, 100, 0};
        int right[] = {999, 899, 499};
        int expected[] = {1000, 800, 500};
        failedTests += runTest(nums, 1000, left, right, expected, 3, ++totalTests);
    }

    // Test Case 6: Edge cases
    {
        int nums[] = {1, 2, 3, 4, 5};
        int left[] = {0, 4, 1, 2};
        int right[] = {0, 4, 3, 2};
        int expected[] = {1, 5, 9, 3};
        failedTests += runTest(nums, 5, left, right, expected, 4, ++totalTests);
    }

    printf("\nTest Summary:\n");
    printf("=============\n");
    printf("Total Tests: %d\n", totalTests);
    printf("Passed: %d\n", totalTests - failedTests);
    printf("Failed: %d\n", failedTests);

    if (failedTests == 0)
    {
        printf("\n✅ All tests passed successfully!\n");
    }
    else
    {
        printf("\n❌ Some tests failed!\n");
    }

    return failedTests > 0 ? 1 : 0;
}