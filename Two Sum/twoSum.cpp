class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            auto found = map.find(complement);
            if (found != map.end()) {
                return {found->second, i};
            }
            map[nums[i]] = i;
        }
        
        return {0,0};
        
    }
};
