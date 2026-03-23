class Solution {
public: 
    long long ans = -1;
    int m , n ;

    // memo[i][j][curr] → visited
    unordered_map<long long, bool> dp[16][16];

    int solve(int i, int j , vector<vector<int>>& grid, long long curr){

        curr = curr * grid[i][j];

        if(i == m-1 && j == n-1){
            if(curr >= 0){
                ans = max(ans, curr);
            }
            return 1;
        }

        //  Memo check
        if(dp[i][j].count(curr)) return 0;
        dp[i][j][curr] = true;

        if(j+1 < n){
            solve(i, j+1, grid , curr);
        } 
        if(i+1 < m){
            solve(i+1 , j, grid, curr);
        }

        return 1;
    }

    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        solve(0 , 0 , grid , 1);

        if(ans < 0) return -1;
        return ans % 1000000007;
    }
};
