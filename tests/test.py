import sys
import os
from typing import List

# Add root folder to Python path for importing solutions
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from solutions.solution import NumArray  # Adjust if needed


def run_test(nums: List[int], queries: List[List[int]], expected: List[int], test_num: int):
    num_array = NumArray(nums)
    print(f"Test Case {test_num}:")
    failed = False

    for i, (left, right) in enumerate(queries):
        result = num_array.sumRange(left, right)
        if result == expected[i]:
            print(f"  Query {i} PASSED [OK] (Output: {result})")
        else:
            print(f"  Query {i} FAILED [FAIL] (Output: {result}, Expected: {expected[i]})")
            failed = True

    return failed


if __name__ == "__main__":
    test_cases = [
        # nums, queries, expected results
        ([ -2, 0, 3, -5, 2, -1], [[0, 2], [2, 5], [0, 5]], [1, -1, -3]),
        ([5], [[0, 0]], [5]),
        ([1, 2, 3, 4, 5], [[0, 4]], [15]),
        ([10, -5, 7, 3, -2], [[1, 3], [1, 3], [0, 4], [2, 2]], [5, 5, 13, 7]),
        ([1]*1000, [[0, 999], [100, 899], [0, 499]], [1000, 800, 500]),
        ([1, 2, 3, 4, 5], [[0, 0], [4, 4], [1, 3], [2, 2]], [1, 5, 9, 3]),
    ]

    failed_any = False
    for i, (nums, queries, expected) in enumerate(test_cases, 1):
        if run_test(nums, queries, expected, i):
            failed_any = True

    if failed_any:
        print("\n[FAIL] Some test cases failed.")
        sys.exit(1)
    else:
        print("\n[OK] All test cases passed.")
        sys.exit(0)
