class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, sumCpy = nums[0];
        
        for (int num : nums) {
            if (sum < 0) sum = 0;
            sum += num;
            sumCpy = max(sum, sumCpy);
        }
        return sumCpy;
    }
};
static const auto fast = []() {
	std::ios::sync_with_stdio( false );
	std::cin.tie( nullptr );
	return nullptr;
}( );
