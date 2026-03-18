// Approach 1: Recursion + Memo  (TLE)
class Solution {
public:
    int t[1001][1001];

    int solve(string text1, string text2, int n1, int n2){
        if(n1 == 0 || n2 == 0)
            return t[n1][n2] = 0;

        if(t[n1][n2] != -1)
            return t[n1][n2];
        
        if(text1[n1-1] == text2[n2-1])
            return t[n1][n2] = 1 + solve(text1, text2, n1-1, n2-1);
        
        return t[n1][n2] = max(solve(text1, text2, n1, n2-1), solve(text1, text2, n1-1, n2));
    }


    int longestCommonSubsequence(string text1, string text2) {
        memset(t, -1, sizeof(t));
        int n1 = text1.size();
        int n2 = text2.size();

        return solve(text1, text2, n1, n2);
    }
};
