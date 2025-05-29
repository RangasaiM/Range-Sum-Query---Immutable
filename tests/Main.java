package tests;

import solutions.Solution.NumArray;
import java.util.Arrays;

public class Main {

    private static boolean anyTestFailed = false;

    private static void runTest(int[] nums, int[][] queries, int[] expected, int testNum) {
        NumArray numArray = new NumArray(nums);
        System.out.println("Test Case " + testNum + ":");

        for (int i = 0; i < queries.length; i++) {
            int result = numArray.sumRange(queries[i][0], queries[i][1]);
            if (result == expected[i]) {
                System.out.println("  Query " + i + " PASSED ✅ (Output: " + result + ")");
            } else {
                System.out
                        .println("  Query " + i + " FAILED ❌ (Output: " + result + ", Expected: " + expected[i] + ")");
                anyTestFailed = true;
            }
        }
    }

    public static void main(String[] args) {
        Object[][] testCases = {
                { new int[] { -2, 0, 3, -5, 2, -1 }, new int[][] { { 0, 2 }, { 2, 5 }, { 0, 5 } },
                        new int[] { 1, -1, -3 } },
                { new int[] { 5 }, new int[][] { { 0, 0 } }, new int[] { 5 } },
                { new int[] { 1, 2, 3, 4, 5 }, new int[][] { { 0, 4 } }, new int[] { 15 } },
                { new int[] { 10, -5, 7, 3, -2 }, new int[][] { { 1, 3 }, { 1, 3 }, { 0, 4 }, { 2, 2 } },
                        new int[] { 5, 5, 13, 7 } },
                { new int[1000], new int[][] { { 0, 999 }, { 100, 899 }, { 0, 499 } }, new int[] { 1000, 800, 500 } },
                { new int[] { 1, 2, 3, 4, 5 }, new int[][] { { 0, 0 }, { 4, 4 }, { 1, 3 }, { 2, 2 } },
                        new int[] { 1, 5, 9, 3 } }
        };

        Arrays.fill((int[]) testCases[4][0], 1); // Fill the large array with 1s

        for (int i = 0; i < testCases.length; i++) {
            runTest((int[]) testCases[i][0], (int[][]) testCases[i][1], (int[]) testCases[i][2], i + 1);
        }

        if (anyTestFailed) {
            System.out.println("\n❌ Some test cases failed.");
            System.exit(1);
        } else {
            System.out.println("\n✅ All test cases passed.");
            System.exit(0);
        }
    }
}
