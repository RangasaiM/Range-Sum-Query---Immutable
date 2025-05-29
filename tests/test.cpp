#include "../solutions/solution.cpp"
#include <iostream>
#include <vector>
using namespace std;

void runTest(vector<int> nums, vector<pair<int, int>> queries, vector<int> expected, int testNum)
{
    NumArray numArray(nums);
    cout << "==== Test Case " << testNum << " ====" << endl;
    cout << "Array: [";
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (i > 0)
            cout << ", ";
        cout << nums[i];
    }
    cout << "]" << endl;

    bool allPassed = true;
    for (size_t i = 0; i < queries.size(); i++)
    {
        int left = queries[i].first;
        int right = queries[i].second;
        int result = numArray.sumRange(left, right);

        cout << "Query " << i + 1 << " (sumRange(" << left << ", " << right << ")): ";
        if (result == expected[i])
        {
            cout << "PASSED ✅ (Got " << result << ")" << endl;
        }
        else
        {
            cout << "FAILED ❌ (Got " << result << ", Expected " << expected[i] << ")" << endl;
            allPassed = false;
        }
    }

    cout << "=== " << (allPassed ? "PASSED" : "FAILED") << " ===" << endl;
}

int main()
{
    vector<tuple<vector<int>, vector<pair<int, int>>, vector<int>>> testCases = {
        // Test Case 1: Example from problem statement
        {
            {-2, 0, 3, -5, 2, -1},
            {{0, 2}, {2, 5}, {0, 5}},
            {1, -1, -3}},

        // Test Case 2: Single element
        {
            {5},
            {{0, 0}},
            {5}},

        // Test Case 3: All elements
        {
            {1, 2, 3, 4, 5},
            {{0, 4}},
            {15}},

        // Test Case 4: Repeated queries
        {
            {10, -5, 7, 3, -2},
            {{1, 3}, {1, 3}, {0, 4}, {2, 2}},
            {5, 5, 13, 7}},

        // Test Case 5: Large array
        {
            vector<int>(1000, 1), // 1000 ones
            {{0, 999}, {100, 899}, {0, 499}},
            {1000, 800, 500}},

        // Test Case 6: Edge cases
        {
            {1, 2, 3, 4, 5},
            {{0, 0}, {4, 4}, {1, 3}, {2, 2}},
            {1, 5, 9, 3}}};

    int failedTests = 0;

    for (size_t i = 0; i < testCases.size(); i++)
    {
        auto &testCase = testCases[i];
        bool passed = true;

        NumArray numArray(get<0>(testCase));
        auto &queries = get<1>(testCase);
        auto &expected = get<2>(testCase);

        for (size_t j = 0; j < queries.size(); j++)
        {
            int result = numArray.sumRange(queries[j].first, queries[j].second);
            if (result != expected[j])
            {
                passed = false;
                break;
            }
        }

        runTest(get<0>(testCase), get<1>(testCase), get<2>(testCase), i + 1);

        if (!passed)
        {
            failedTests++;
        }
    }

    if (failedTests == 0)
    {
        cout << "All test cases passed successfully!" << endl;
    }
    else
    {
        cout << failedTests << " test cases failed!" << endl;
    }

    return failedTests > 0 ? 1 : 0;
}