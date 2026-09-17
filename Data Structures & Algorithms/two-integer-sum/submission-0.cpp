class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, size_t> seen_nums{};
        for (int i = 0; i < nums.size(); ++i) {
            auto difference = target - nums[i];

            if (!seen_nums.contains(difference)) {
                seen_nums[nums[i]] = i;
                continue;
            }

            int other = seen_nums[difference];
            if (other < i)
                return {other, i};
            
            return {i, other};
        }
        return {0, 0};
    }
};
