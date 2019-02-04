// #include <iostream>
// #include <string>
// #include <vector>
// #include <limits>
// #include <cfloat>
// #include <queue>

// using namespace std;

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        vector<vector<double>> vWorkers;
        for (int x = 0; x < quality.size(); x++) {
            vWorkers.push_back({ (double) (wage[x])/quality[x], (double) quality[x] });
        }
        sort(vWorkers.begin(), vWorkers.end());
        double qsum = 0;
        double result = DBL_MAX;
        priority_queue<int> queue;
        for (auto worker : vWorkers) {
            qsum += worker[1];
            queue.push(worker[1]);
            if (queue.size() > K){
                qsum -= queue.top();
                queue.pop();
            }
            if (queue.size() == K)
                result = min(result, qsum * worker[0]);
        }
        return result;
    }
};
/*
 Input: quality = [10,20,5], wage = [70,50,30], K = 2           Output: 105.00000
 Explanation: We pay 70 to 0-th worker and 35 to 2-th worker.

 Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], K = 3      Output: 30.66667
 Explanation: We pay 4 to 0-th worker, 13.33333 to 2-th and 3-th workers seperately.
 */

// int main() {

//     return 0;
// }




