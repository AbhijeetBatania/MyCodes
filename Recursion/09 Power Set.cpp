class Solution {
public:
    vector<string> result;

    void solve(string &curr, string &s, int idx) {
        
        if (idx == s.length()) {
            if (curr != "") {
                result.push_back(curr);
            }
            return;
        }

        curr.push_back(s[idx]);   // take current idx
        solve(curr, s, idx + 1);   
        curr.pop_back();
        
        solve(curr, s, idx + 1);  // Skip current idx
    }

    vector<string> AllPossibleStrings(string s) {
        string curr = "";
        solve(curr, s, 0);
        sort(begin(result), end(result));
        return result;
    }
};
