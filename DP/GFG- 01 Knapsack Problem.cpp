// Approach 1: Recursion + Memo      // GFG Question
class Solution {
  public:
    int t[1001][1001];
    int solve(int i, int W, vector<int> &val, vector<int> &wt){
        if(i == 0){
            if(wt[0] <= W) return val[0];
            return 0;
        }    
            
        if(t[i][W] != -1) return t[i][W];
        
        int not_take = solve(i-1, W, val, wt);
        int take = 0 ;
        
        if(wt[i]<=W)
            take = val[i] + solve(i-1, W-wt[i] , val, wt);
            
        return t[i][W] = max(take, not_take);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        memset(t, -1, sizeof(t));
        int n = wt.size();
        
        return solve(n-1, W, val , wt);
    }
};

