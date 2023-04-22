
/**
 * @param {number[][]} grid
 * @return {number[]}
 */
var findColumnWidth = function (grid) {
    const maxWidthForEachColumn = new Array(grid[0].length);

    for (let column = 0; column < grid[0].length; ++column) {

        let maxColumnWidth = 0;
        for (let row = 0; row < grid.length; ++row) {
            const additionForFirstDigit = 1;
            const additionForNegativeValue = grid[row][column] < 0 ? 1 : 0;

            const currentColumnWidth = grid[row][column] !== 0
                    ? (Math.floor(Math.log10(Math.abs(grid[row][column]))) + additionForFirstDigit + additionForNegativeValue)
                    : 1;

            maxColumnWidth = Math.max(maxColumnWidth, currentColumnWidth);
        }
        maxWidthForEachColumn[column] = maxColumnWidth;
    }

    return maxWidthForEachColumn;
};
