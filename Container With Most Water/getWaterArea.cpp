#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

using std::vector;
using std::min;
using std::max;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int maxAreaInt = 0, start = 0, end = (int) height.size() - 1;
        while (end > start) {
            maxAreaInt = max(maxAreaInt, min(height[start], height[end]) * (end - start));

            (height[end] > height[start]) ? start++ : end--;
        }

        return maxAreaInt;
    }
};

int main(){

    vector<int> height = {1,8,6,2,5,4,8,3,7};
    Solution sol;
    int area = sol.maxArea(height);
    std::cout << "Max area is: " << area << std::endl;


    return 0;
}
