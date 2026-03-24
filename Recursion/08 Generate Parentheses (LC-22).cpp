//Approach-1 (Simple Recursion)
class Solution {
public:
    vector<string> result;

    bool isValid(string& temp){
        int count = 0;

        for(int i = 0 ; i< temp.size() ; i++){
            if(temp[i] == '(') count  ++;
            else count--;

            if(count<0) return false;
        }
        return count == 0;
    }   

    void solve(string &temp , int n){
        if(temp.size() == 2*n){
            if(isValid(temp)){
                result.push_back(temp);
            }
            return;
        }

        temp.push_back('(');
        solve(temp , n);
        temp.pop_back();

        temp.push_back(')');
        solve(temp , n);
        temp.pop_back();

    }
    vector<string> generateParenthesis(int n) {
        string temp = "";

        solve(temp , n);

        return result;
    }
};



//Approach-2 (Smart Recursion) Using Checks to reduce time
class Solution {
public:
    vector<string> result;  

    void solve(string &temp , int n , int open, int close){
        if(temp.size() == 2*n){
            result.push_back(temp);
            return;
        }
        if(open < n){
            temp.push_back('(');
            solve(temp , n, open+1 , close);
            temp.pop_back();
        }
        if(close < open){
            temp.push_back(')');
            solve(temp , n, open, close+1);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string temp = "";

        solve(temp, n, 0, 0);

        return result;
    }
};

