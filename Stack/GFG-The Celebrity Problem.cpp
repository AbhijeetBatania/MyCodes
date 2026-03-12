class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {

        stack<int> st;
        int n = mat.size();

        for(int i = n-1; i >= 0; i--)
            st.push(i);

        while(st.size() > 1){
            int first = st.top(); st.pop();
            int second = st.top(); st.pop();

            if(mat[first][second])
                st.push(second);
            else
                st.push(first);
        }

        int num = st.top();

        int row = 0, col = 0;

        for(int i = 0; i < n; i++){
            row += mat[num][i];
            col += mat[i][num];
        }

        return (row == 1 && col == n) ? num : -1;
    }
};
