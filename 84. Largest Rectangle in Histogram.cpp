class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, 0), right(n, 0);
        stack<int> stk;

        for(int i = n - 1; i >= 0; i--){
            while(!stk.empty() && heights[stk.top()] >= heights[i]){
                stk.pop();
            }

            right[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }
        while(!stk.empty()) stk.pop();
        for(int i = 0; i < n; i++){
            while(!stk.empty() && heights[stk.top()] >= heights[i]){
                stk.pop();
            }

            left[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }

        int ans = 0;

        for(int i = 0; i < n; i++){
            int width = heights[i] * (right[i] - left[i] - 1);
            ans = max(ans, width);
        }

        return ans;
    }
};