
public class Solution {

    public int[] findColumnWidth(int[][] grid) {
        int[] maxWidthForEachColumn = new int[grid[0].length];

        for (int column = 0; column < grid[0].length; ++column) {

            int maxColumnWidth = 0;
            for (int row = 0; row < grid.length; ++row) {
                int additionForFirstDigit = 1;
                int additionForNegativeValue = grid[row][column] < 0 ? 1 : 0;

                int currentColumnWidth = grid[row][column] != 0
                        ? ((int) Math.log10(Math.abs(grid[row][column])) + additionForFirstDigit + additionForNegativeValue)
                        : 1;

                maxColumnWidth = Math.max(maxColumnWidth, currentColumnWidth);
            }
            maxWidthForEachColumn[column] = maxColumnWidth;
        }

        return maxWidthForEachColumn;
    }
}
