// #include <iostream>
// #include <vector>
// #include <cstdlib>
// #include <algorithm>
// #include <string>
// #include <unordered_map>
// #include <cmath>
// #include <numeric>

// using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> vecPrefix = {0};
        for (auto num : A)
            vecPrefix.push_back(vecPrefix.back() + num);

        // for (auto num : vecPrefix) cout << num << " "; cout << endl;

        vector<int> vecCount(K, 0);
        for (auto num : vecPrefix)
            vecCount[(num % K + K) % K]++;

        // for (auto num : vecCount) cout << num << " "; cout << endl;

        int count = 0;
        for (int num: vecCount)
            count += num * (num - 1) / 2;

        return count;
    }
};
/*
 {4,5,0,-2,-3,1}
 [0,4,9,9,7,4,5]
 [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
 */


// int main(){

//     vector<int> v = {4,5,0,-2,-3,1};
//     int k = 5;
//     Solution sol;
//     int x = sol.subarraysDivByK(v, k);
//     cout << "int: " << x << endl;

//     return 0;
// }
