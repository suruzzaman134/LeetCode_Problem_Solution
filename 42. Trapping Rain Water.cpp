class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int lmax = 0, rmax = 0;
        int result = 0;
        while(l < r){
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);

            if(lmax < rmax){
                result += lmax - height[l];
                l++;
            }else{
                result += rmax - height[r];
                r--;
            }
        }
        return result;
    }
};