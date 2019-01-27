//        int minimum = 0;
//        while (pow(minutesToTest/minutesToDie+1,minimum) < buckets) {
//            minimum++;
//        }

// https://leetcode.com/problems/poor-pigs/discuss

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        return ceil( log(buckets) / log(minutesToTest/minutesToDie+1) );
    }
};

// int main(){

//     int buckets = 1000;
//     int minutesToDie = 15;
//     int minutesToTest = 60;
//     Solution sol;
//     int minimum = sol.poorPigs(buckets, minutesToDie, minutesToTest);
//     cout << "It is: " << minimum << endl;

//     return 0;
// }
