class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> vReturn;
        int sum = 0;
        for (auto num : A)
            if (num%2==0) sum += num;
            
        for (auto ref : queries) {
            int & target = A[ref[1]];
            int i = ref[0];
            if (i % 2 == 0) 
                sum += ((target % 2 == 0) ? i : 0);
            else 
                sum += ((target % 2 == 0) ? -target : (target + i));
            
            target += i;
            vReturn.push_back(sum);
        }

        return vReturn;
    }
};
