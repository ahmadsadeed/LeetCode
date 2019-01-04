#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using std::vector;
using std::min;
using std::max;
using std::cout;
using std::endl;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        int sizeNums = (int) nums.size();
        vector<vector<int>> vecOfVecs;

        // if nums has less than 3 elements
        if (sizeNums < 3) return vecOfVecs;

        sort(nums.begin(), nums.end());

        // Only operate on negative numbers. break if reached positives
        for (int i = 0; i < sizeNums - 2 && nums[i] <= 0; i++) {
            // continue if two consecutive numbers are equal
            if ( i != 0 && (nums[i] == nums[i - 1])) continue;

            // complement + nums[i] = 0. find two numbers that make complement when added together
            int complement = 0 - nums[i];

            int *begin = &nums[i + 1];
            int *end   = &nums[sizeNums -1];
            while (begin < end) {
                if ((*begin + *end) > complement) {
                    end--;
                } else if ( (*begin + *end) < complement){
                    begin++;
                } else {
                    vecOfVecs.push_back(vector<int>{-complement, *begin, *end});
                    begin++;
                    end--;
                    // jump to next number if next number equals current begin
                    while (begin < end && *begin == *(begin - 1)) {
                        begin++;
                    }
                    // jump to previous number if previous number equals current end
                    while (begin < end && *end == *(end + 1)) {
                        end--;
                    }
                }
            }
        }
        return vecOfVecs;
    }
};

int main(){
    vector<int> param = {-4, -1, -1, 0, 1, 2};//{-4, -1, -1, 0, 1, 2};//{-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    Solution sol;
    vector<vector<int>> v = sol.threeSum(param);
    for (auto & vSub : v) {
        for (int & n : vSub) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}

