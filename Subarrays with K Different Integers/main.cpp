class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {

        vector<int> vec(A.size() + 1);
        int j = 0, prefix = 0, count = 0, total = 0;

        for (int i = 0; i < A.size(); ++i) {
            if (vec[A[i]]++ == 0)
                ++count;
            if (count > K) {
                --vec[A[j++]];
                --count;
                prefix = 0;
            }
            while (vec[A[j]] > 1) {
                ++prefix;
                --vec[A[j++]];
            }
            if (count == K)
                total += prefix + 1;
        }
        return total;
    }
};
/*
 */

int main() {
    Solution sol;
    vector< int> v = {5,7,5,2,3,3,4,1,5,2,7,4,6,2,3,8,4,5,7};
    int i = sol.subarraysWithKDistinct(v, 7);
    cout << i << endl;
    return 0;
}
