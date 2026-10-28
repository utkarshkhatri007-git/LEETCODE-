class Solution {
public:

    bool ifpossible(vector<int>& nums, int n, int k, int mid)
    {
        int sum = 0;
        int count = 1;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] + sum <= mid)
            {
                sum += nums[i];
            }
            else
            {
                count++;

                if (nums[i] > mid || count > k)
                    return false;

                sum = nums[i];
            }
        }

        return true;
    }

    int splitArray(vector<int>& nums, int k)
    {
        int n = nums.size();

        int start = 0;
        int end = 0;
        int ans = -1;

        for (int i = 0; i < n; i++)
        {
            end += nums[i];
            start = max(start, nums[i]);
        }

        int mid = start + (end - start) / 2;

        while (start <= end)
        {
            if (ifpossible(nums, n, k, mid))
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }

            mid = start + (end - start) / 2;
        }

        return ans;
    }
};