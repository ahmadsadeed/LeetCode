// #include <iostream>
// #include <vector>
// #include <cstdlib>
// #include <algorithm>
// #include <string>

// using namespace std;

int static fast = [](){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); return 0;
}();
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int startIndex = 0;
        int endIndex = (int) nums.size() - 1;
        int midIndex = -1;
        while (startIndex <= endIndex) {
            midIndex = startIndex + (endIndex - startIndex) / 2;
            int num = nums[midIndex];
            if (num == target) {
                return midIndex;
            } else if (num > target) {
                endIndex = midIndex - 1;
            } else {
                startIndex = midIndex + 1;
            }
        }

        return -1;
    }
};
//  [-1,0,3,5,9,12], target = 9     4
//  [-1,0,3,5,9,12], target = 2     -1
// int main(){

//     vector<int> nums = {-1,0,3,5,9,12} ;
//     Solution sol;
//     int i = sol.search(nums, 9);
//     cout << "It is: " << i << endl;

//     return 0;
// }
