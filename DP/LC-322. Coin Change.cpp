// Approach 1: Recursion+Memo
class Solution {
public:
    int t[13][10001];

    int solve(int idx, vector<int>& coins, int amount){

        if(idx == 0){
            if(amount % coins[0] == 0) 
                return amount / coins[0];
            return INT_MAX;
        }

        if(t[idx][amount] != -1) return t[idx][amount];

        int not_take = solve(idx - 1, coins, amount);

        int take = INT_MAX;

        if(coins[idx] <= amount){
            int res = solve(idx, coins, amount - coins[idx]);
            if(res != INT_MAX)
                take = 1 + res;
        }

        return t[idx][amount] = min(take, not_take);
    }

    int coinChange(vector<int>& coins, int amount) {
        memset(t, -1, sizeof(t));
        int n = coins.size();

        int ans = solve(n - 1, coins, amount);

        if(ans == INT_MAX) return -1; 
        return ans;
    }
};
