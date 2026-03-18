// Approach 1: Recursion+Memo
class Solution {
public:
    int n;
    int t[2501][2501];

    int solve(int i , int p , vector<int>& nums){
        if( i == n) return 0;       //i = current index, p = previous index

        if(p != -1 && t[i][p] != -1)
            return t[i][p];

        int not_take = solve(i+1, p, nums);

        int take = 0;

        if(p == -1 || nums[i] > nums[p]){
            take = 1 + solve(i+1, i, nums);
        }

        if(p != -1)
            return t[i][p] = max(take, not_take);

        return max(take, not_take);
    }

    int lengthOfLIS(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        n = nums.size();

        return solve(0,-1,nums);
    }
};
