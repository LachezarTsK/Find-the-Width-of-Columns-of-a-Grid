
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    
public:
    vector<int> findColumnWidth(const vector<vector<int>>& grid) const {
        vector<int> maxWidthForEachColumn;

        for (int column = 0; column < grid[0].size(); ++column) {

            int maxColumnWidth = 0;
            for (int row = 0; row < grid.size(); ++row) {
                int additionForFirstDigit = 1;
                int additionForNegativeValue = grid[row][column] < 0 ? 1 : 0;

                int currentColumnWidth = grid[row][column] != 0
                        //alternatively: static_cast<int>(log10(abs(grid[row][column]))) instead of floor(...)
                        ? (floor(log10(abs(grid[row][column]))) + additionForFirstDigit + additionForNegativeValue)
                        : 1;

                maxColumnWidth = max(maxColumnWidth, currentColumnWidth);
            }
            maxWidthForEachColumn.push_back(maxColumnWidth);
        }

        return maxWidthForEachColumn;
    }
};
