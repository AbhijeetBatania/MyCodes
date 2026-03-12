// Method 1: Using Stack but 3 pass
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> right(n);    // Next Smallest Right
        vector<int> left(n);     // Next smallest left
        stack<int>st;

        for(int i =0 ; i < n ; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()){
            right[st.top()] = n;
            st.pop();
        } 

        for(int i =n-1 ; i >=0 ; i--){
            while(!st.empty() && heights[st.top()] > heights[i]){
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()){
            left[st.top()] = -1;
            st.pop();
        } 

        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            ans = max(ans, heights[i] * (right[i] -left[i] -1));
        }
        return ans;
    }
};

// Method 2: Using Stack, but 1 pass
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        int n = heights.size();
        stack<int> st;

        for(int i = 0 ; i <n ; i++){
            while(!st.empty() && heights[st.top()] > heights[i] ){
                int index = st.top();
                st.pop();
                if(!st.empty()) ans= max(ans, heights[index] * (i-st.top()-1));
                else ans= max(ans, heights[index] * (i));
            }
            st.push(i);
        }
        while(!st.empty()){
            int index = st.top();
            st.pop();
            if(!st.empty()) ans= max(ans, heights[index] * (n-st.top()-1));
            else ans= max(ans, heights[index] * (n));
        }
        return ans;
    }
};

