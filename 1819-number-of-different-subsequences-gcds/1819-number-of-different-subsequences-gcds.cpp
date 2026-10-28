class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());

        vector<bool> present(maxVal + 1, false);

        for (int num : nums) {
            present[num] = true;
        }

        int ans = 0;

        for (int target = 1; target <= maxVal; target++) {
            int g = 0;

            for (int multiple = target; multiple <= maxVal; multiple += target) {
                if (present[multiple]) {
                    g = gcd(g, multiple);
                }

                if (g == target) {
                    ans++;
                    break;
                }
            }
        }

        return ans;
    }
};