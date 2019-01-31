// #include <iostream>
// #include <string>
// #include <vector>
// #include <queue>

// using namespace std;

class Solution {
public:
    int countTriplets(vector<int> A) {
        size_t n = A.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                for (int k = j; k < n; k++) {
                    if ((A[i] & A[j] & A[k]) == 0) {
                        if (i == j && j == k)
                            count++;
                        else if (i == j || i == k || j == k)
                            count += 3;
                        else
                            count += 6;
        }}}}
        return count;
    }
};


// int main() {
//     vector<int> A = {2,2,2};
//     Solution sol;
//     int i = sol.countTriplets(A);
//     cout <<"i is: "<< i << endl;
//     return 0;
// }
