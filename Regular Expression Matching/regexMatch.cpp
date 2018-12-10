//#include <iostream>
//#include <vector>
//#include <cstdlib>
//#include <string>
//
//using namespace std;
//

class Solution {
public:
    bool isMatch(string str, string pattern) {
        vector<vector<bool>> matrix(str.length() + 1, vector<bool>(pattern.size() + 1, false));
        matrix[str.length()][pattern.length()] = true;

        for (int row = str.length(); row >= 0; row--){
            for (int col = pattern.length() - 1; col >= 0; col--){
        /*
         s = "aa"            p = "a"            Output: false
         s = "aa"            p = "a*"           Output: true
         s = "ab"            p = ".*"           Output: true
         s = "aab"           p = "c*a*b"        Output: true
         s = "mississippi"   p = "mis*is*p*."   Output: false

         Matrix for "aab" and "c*a*b" is:
                                         1 0 1 0 0 0
                                         1 0 1 0 0 0
                                         1 0 1 0 1 0
                                         0 0 0 0 0 1
         */
                bool startMatch = row < str.length();
//                cout << "\ni: "<<row << ", j: "<<col << endl;
//                cout << "startMatch is: "<< startMatch << endl;

                bool matchingRowCol = startMatch && (str.at(row) == pattern.at(col) || pattern.at(col) == '.');;
//                cout << "matchingRowCol is: "<< matchingRowCol << endl;

                if (col + 1 < pattern.length() && pattern.at(col+1) == '*'){
                    matrix[row][col] = matrix[row][col+2] || (matchingRowCol && matrix[row+1][col]);
                } else {
                    matrix[row][col] = matchingRowCol && matrix[row+1][col+1];
                }
            }
        }
        /*cout << "\nDisplaying matrix: " << endl;
        for(auto row: matrix) {for(bool val: row) cout << val << ' '; cout <<'\n';}*/
        return matrix[0][0];
    }
};


//int main(){
//
//    Solution sol;
//    string str = "v";
//    string pattern = "v*";
//
//    bool b = sol.isMatch(str, pattern);
//    if (b) {
//        cout << "It is a match." << endl;
//    } else {
//        cout << "It is NOT a match." << endl;
//    }
//
//    return 0;
//}


