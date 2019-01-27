// #include <iostream>
// #include <vector>
// #include <cstdlib>
// #include <algorithm>
// #include <string>
// #include <set>

// using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        set<string> setFromDict(wordDict.begin(), wordDict.end());
        int strSize = (int) s.size();
        vector<bool> boolsVec(strSize + 1, false);
        boolsVec[0] = true;

        for (int i = 1; i <= strSize; ++i) {
            for (int j = i - 1; j >= 0; --j) {
//                cout << "S: " << s.substr(j, i - j) << endl;
                if ( (boolsVec[j]) && (setFromDict.find(s.substr(j, i - j)) != setFromDict.end()) ) {
//                    cout << "S2: " << s.substr(j, i - j) << endl;
                    boolsVec[i] = true;
                    break;
                }
            }
        }

        return boolsVec[strSize];
    }
    // s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]    (false)
    // s = "applepenapple", wordDict = ["apple", "pen"]                     (true)
    // s = "catsanddog"     {"dog", "and", "cats", "cat"}    ???
};

// int main(){

//     string s = "catsanddog";
//     vector<string> vec = {"dog", "sand", "cat", "cats"} ;
//     Solution sol;
//     bool b = sol.wordBreak(s, vec);
//     if (b) cout << "It is true." << endl;
//     else cout << "It is false." << endl;

//     return 0;
// }
