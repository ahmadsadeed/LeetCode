
/*
 Input: S = "0.(52)", T = "0.5(25)"
 Output: true
 Explanation:
 Because "0.(52)" represents 0.52525252..., and "0.5(25)" represents 0.52525252525..... , the strings represent the same number.
 */
class Solution {
public:
    bool isRationalEqual(string S, string T) {
        double sDouble = 0.0, tDouble = 0.0;
        auto positionS = S.find("(");
        if (positionS != string::npos) {
            string newS = S.substr(0, positionS);
            while (newS.size() < 20) { // 15 digit precision returned false
                newS += S.substr(positionS + 1, S.size() - positionS - 2) ; // -2 for two ()
            }
            sDouble = stod(newS);
        } else sDouble = stod(S);   // if string T = "1.";
        auto positionT = T.find("(");
        if (positionT != string::npos) {
            string newT = T.substr(0, positionT);
            while (newT.size() < 20) {
                newT += T.substr(positionT + 1, T.size() - positionT - 2) ; // -2 for two ()
            }
            tDouble = stod(newT);
        } else tDouble = stod(T);   // if string T = "1.";
        return sDouble == tDouble;
    }
};

// int main(){

// //    string S = "0.(52)";
// //    string T = "0.5(25)";
//     string S = "0.9(9)";
//     string T = "1.";
//     Solution sol;
//     bool b = sol.isRationalEqual(S, T);
//     cout << "It is: " << b << endl;

//     return 0;
// }
