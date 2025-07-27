class Solution {
public:
    int conquer(vector<int>& nums, int s, int m, int e){
        int cnt = 0;
        int j = m + 1;


        for(int i = s; i <= m; i++){
            while(j <= e && (long long)nums[i] > 2LL * nums[j]){
                j++;
            }
            cnt += (j - (m + 1));
        }


        vector<int> temp;
        int l = s, r = m + 1;
        while(l <= m && r <= e){
            if(nums[l] <= nums[r]){
                temp.push_back(nums[l++]);
            } else {
                temp.push_back(nums[r++]);
            }
        }
        while(l <= m) temp.push_back(nums[l++]);
        while(r <= e) temp.push_back(nums[r++]);

        for(int i = 0; i < temp.size(); i++){
            nums[s + i] = temp[i]; // not l+i
        }

        return cnt;
    }

    int divide(vector<int>& nums, int s, int e){
        if(s >= e) return 0;

        int m = s + (e - s) / 2;

        int left_count = divide(nums, s, m);
        int right_count = divide(nums, m + 1, e);
        int cross_count = conquer(nums, s, m, e);

        return left_count + right_count + cross_count;
    }

    int reversePairs(vector<int>& nums) {
        return divide(nums, 0, nums.size() - 1);
    }
};
