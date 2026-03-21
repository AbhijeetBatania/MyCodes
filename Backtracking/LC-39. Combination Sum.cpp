// Approach 1: Simple Recursion
class Solution {
public:
    vector<vector<int>> result;
    void solve(int idx, int sum, vector<int>& candidates, int target , vector<int>& curr){
        if(sum == target){
            result.push_back(curr);
            return;
        }
        if(sum > target || idx >= candidates.size()){
            return;
        }

        curr.push_back(candidates[idx]);
        solve(idx , sum+candidates[idx], candidates, target, curr);
        curr.pop_back();

        solve(idx+1 , sum, candidates, target, curr);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        solve(0, 0, candidates, target , curr);
        return result;
    }
};


// Approach 2: Using for loop
class Solution {
public:
    vector<vector<int>> result;
    void solve(vector<int>& candidates, int target , vector<int>& curr, int idx){
        if(target < 0)
            return;
        if(target == 0) {
            result.push_back(curr);
            return;
        }
        
        for(int i = idx; i < candidates.size(); i++) {
            curr.push_back(candidates[i]);
            solve(candidates, target-candidates[i], curr, i);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        solve(candidates, target, curr, 0);
        return result;
    }
};
