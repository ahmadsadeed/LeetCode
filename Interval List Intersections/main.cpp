// #include <iostream>
// #include <string>
// #include <vector>
// #include <limits>
// #include <algorithm>

// using namespace std;

// // Definition for an interval.
// struct Interval {
//     int start;
//     int end;
//     Interval() : start(0), end(0) {}
//     Interval(int s, int e) : start(s), end(e) {}
// };

class Solution {
public:
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        vector<Interval> vInterval;
        for (int x = 0, y = 0; x < A.size() && y < B.size();) {
            if (A[x].start > B[y].end) {
                y++;
            } else if (A[x].end < B[y].start) {
                x++;
            } else {
                vInterval.push_back(Interval(max(A[x].start, B[y].start), min(A[x].end, B[y].end)));
                if (A[x].end > B[y].end)    y++;
                else    x++;
            }
        }
        return vInterval;
    }
};
/*
 Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
 Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
 Reminder: The inputs and the desired output are lists of Interval objects, and not arrays or lists.
 */

// int main() {

//     return 0;
// }


