class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0,e=n-1;
        int m=s+(e-s)/2;
        while(s<=e)
        {
            if(target==nums[m])
            return m;
            else if(nums[m]>target)
            e=m-1;
            else 
            s=m+1;
            m=s+(e-s)/2;
        }
        return -1;
    }
};