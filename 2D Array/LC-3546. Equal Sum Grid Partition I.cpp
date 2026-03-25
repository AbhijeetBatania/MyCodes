class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        long long total = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                total += grid[i][j];
            }
        }

        if (total % 2 != 0) return false;

        long long target = total / 2;

        // for horizontal cuts
        long long count = 0;
        for (int i = 0; i < row-1; i++) {
            for (int j = 0; j < col; j++) {
                count += grid[i][j];
                if(count > target) break;
            }
            if (target == count)
                return true;
        }

        // for vertical cuts
        count = 0;
        for (int i = 0; i < col-1; i++) {
            for (int j = 0; j < row; j++) {
                count += grid[j][i];
                if(count > target) break;
            }
            if (target == count)
                return true;
        }
        return false;
    }
};
