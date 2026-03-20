// Approach 1: Using for loop
class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int>& curr, vector<int>& nums, int idx){
        result.push_back(curr);

        for(int i = idx; i < nums.size(); i++){
            
            // skip duplicates
            if(i > idx && nums[i] == nums[i-1]) continue;

            curr.push_back(nums[i]);
            solve(curr, nums, i + 1);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<int> curr;
        solve(curr, nums, 0);
        return result;
    }
};


// Approach 2: Using Simple Recursion
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

        // skip duplicates
        int next = idx + 1;
        while(next < nums.size() && nums[next] == nums[idx]){
            next++;
        }

        solve(curr, nums, next);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // important 
        vector<int> curr;
        solve(curr, nums, 0);
        return result;
    }
};
