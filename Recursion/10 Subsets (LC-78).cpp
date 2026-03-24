class Solution {
public:
    vector<vector<int>> result;
 
    void solve(vector<int>& curr, vector<int>& nums, int idx){
        if(idx == nums.size()){
            result.push_back(curr);
            return;
        }
        
        curr.push_back(nums[idx]);
        solve(curr, nums, idx+1);
        curr.pop_back();
        
        solve(curr, nums, idx+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;

        solve(curr, nums, 0);

        return result;
    }
};
