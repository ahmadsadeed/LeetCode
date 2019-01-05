#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        vector<string> mainVec{""};
        vector<string> charsVec{" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        for (int i = 0; i < digits.length(); i++) {
            int currentDigit = digits[i] - '0';
            if (currentDigit < 0 || currentDigit > 9) break;

            string &str = charsVec[currentDigit];
            vector<string> newVec;

            for (int x = 0; x < mainVec.size(); x++) {
                for (int z = 0; z < str.size(); z++) {
                    newVec.push_back(mainVec[x] + str[z]);
                }
            }
            mainVec.swap(newVec);
        }
        return mainVec;
    }
};

int main(){
    string s = "23";
    Solution sol;
    vector<string> v = sol.letterCombinations(s);
    for (auto & str : v) {
        cout << str << " ";
    }
    cout << endl;
    return 0;
}

