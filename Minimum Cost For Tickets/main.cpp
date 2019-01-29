class Solution {
public:
// dynamic programming solution answered by Leetcode user

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int cost = 0;
        queue<pair<int, int>> weeks, months;
        for (auto day : days) {
            while (!weeks.empty() && weeks.front().first + 7 <= day)
                weeks.pop();
            while (!months.empty() && months.front().first + 30 <= day)
                months.pop();
            weeks.push(make_pair(day, cost + costs[1]));
            months.push(make_pair(day, cost + costs[2]));
            cost = min({ cost + costs[0], weeks.front().second, months.front().second });
        }
        return cost;
    }

};
/*
 Input: days = [1,4,6,7,8,20], costs = [2,7,15]
 Output: 11  =  2,4,6,7,9,11
 Input: days = [1,2,3,4,5,6,7,8,09,10,30,31], costs = [2,7,15]
 Output: 17     2,4,6,7,7,7,7,9,11,13,15,17
 */


// int main() {
//     vector<int> days = {1,2,3,4,5,6,7,8,9,10,11,12};
//     vector<int> costs = {2,7,15};
//     Solution sol;
//     int i = sol.mincostTickets(days, costs);
//     cout <<"i is: "<< i << endl;
//     return 0;
// }


