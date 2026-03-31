class Solution {
public:
    vector<string> ans;
    void solve(string &digits, int idx, vector<string> &mapping, string &curr) {
        if (idx == digits.size()) {
            ans.push_back(curr);
            return;
        }

        int digit = digits[idx] - '0';
        string letters = mapping[digit];

        for (char ch : letters) {
            curr.push_back(ch);
            solve(digits, idx + 1, mapping, curr);
            curr.pop_back(); 
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        string curr = "";
        solve(digits, 0, mapping, curr);

        return ans;
    }
};
