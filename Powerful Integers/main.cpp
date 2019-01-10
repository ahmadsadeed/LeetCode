// #include <iostream>
// #include <string>
// #include <vector>
// #include <set>


// using namespace std;


class Solution {
public:
/*
     Input: x = 2, y = 3, bound = 10
     Output: [2,3,4,5,7,9,10]
     Explanation:
     2 = 2^0 + 3^0
     3 = 2^1 + 3^0
     4 = 2^0 + 3^1
     5 = 2^1 + 3^1
     7 = 2^2 + 3^1
     9 = 2^3 + 3^0
     10 = 2^0 + 3^2
*/
    vector<int> powerfulIntegers(int x, int y, int bound) {

        set<int> v;
        for (int i = 1 ; i <= bound ; i *= x) {
            for (int j = 1 ; j + i <= bound ; j *= y) {
                v.insert(i + j);
                if (y == 1) break;
            }
            if (x == 1) break;
        }

        vector<int> vec(v.begin(), v.end());
        return vec;
    }
};

// int main(){

//     Solution sol;
//     vector<int> v = sol.powerfulIntegers(1, 2, 100);
//     for (auto i : v) {
//         cout << i << " ";
//     }
//     cout << endl;



//     return 0;
// }
