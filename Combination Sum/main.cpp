#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> temp;
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        depthSearch(target, candidates, 0);
        return result;
    }
    void depthSearch(int target, vector<int>& candidates, int index) {
        // add answer
        if (target == 0) {
            result.push_back(temp);
            return ;
        }
        for(int i = index; i < candidates.size(); i++) {
            if (candidates[i] > target) break;
            temp.push_back(candidates[i]);
            depthSearch(target-candidates[i], candidates, i);
            temp.pop_back();
        }
        return ;
    }

};
/*
 [1,2,3,4,5,6,7,8]      7
 Input: candidates = [2,3,5], target = 8,
 A solution set is:     [ [2,2,2,2], [2,3,3], [3,5] ]
*/

int main() {
    vector<int> vec = {1,2,3,4,5,6,7};
    Solution sol;
    vector<vector<int>> vecVec = sol.combinationSum(vec, 7);
    cout << endl;
    for (auto v : vecVec) {
        cout << "[";
        for (auto i : v) {
            cout << i << ", ";
        }
        cout << "]" << endl;
    }
    return 0;
}

