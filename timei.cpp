#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
   bool canPartitionGrid(vector<vector<int> >& grid) {

        // Horizontally Prefix Sum
        int up_row = 0;
        int low_row = grid.size() - 1;
        int col = grid[0].size();
        int up_sum = 0;
        int low_sum = 0;
        while (up_row < low_row) {
            if (low_sum >= up_sum) {
                for (int i = 0; i < col; i++) {
                    up_sum += grid[up_row][i];
                }
                up_row++;
            } else {
                for (int i = 0; i < col; i++) {
                    low_sum += grid[low_row][i];
                }
                low_row--;
            }
        }
            if (up_row == low_row) {
                int mid_sum = 0;
                for (int i = 0; i < col; ++i)
                    mid_sum += grid[up_row][i];
                if (up_sum <= low_sum)
                    up_sum += mid_sum;
                else
                    low_sum += mid_sum;
            }
        if (low_sum == up_sum)
            return true;

        // Vertically Prefix Sum
        int left_col = 0;
        int right_col = grid[0].size() - 1;
        int row = grid.size();
        int left_sum = 0;
        int right_sum = 0;
        while (left_col < right_col) {
            if (left_sum >= right_sum) {
                for (int i = 0; i < row; i++) {
                    left_sum += grid[i][left_col];
                }
                left_col++;
            } else {
                for (int i = 0; i < row; i++) {
                    right_sum += grid[i][right_col];
                }
                right_col--;
            }
        }
            if (right_col == left_col) {
                int mid_sum = 0;
                for (int i = 0; i < row; ++i)
                    mid_sum += grid[i][left_col];
                if (right_sum <= left_sum)
                    right_sum += mid_sum;
                else
                    left_sum += mid_sum;
            }
        if (left_sum == right_sum)
            return true;
        return false;
    }
};

int main() {
    Solution sol;

    vector<vector<int> > grid;
    grid.push_back(vector<int>());
    grid[0].push_back(156954);
    
  
    
    grid.push_back(vector<int>());
    grid[1].push_back(156954);
  
   
    

    if (sol.canPartitionGrid(grid)) {
        cout << "Grid can be partitioned." << endl;
    } else {
        cout << "Grid cannot be partitioned." << endl;
    }

    return 0;
}
