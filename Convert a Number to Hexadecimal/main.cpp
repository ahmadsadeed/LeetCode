// #include <iostream>
// #include <string>
// #include <vector>
// #include <bitset>

// using namespace std;
const string HEX = "0123456789abcdef";
class Solution {
public:

    string toHex(int num) {
//        cout << "hex: " << hex << num << endl;
        if (num == 0) return "0";
        string s = "";
        int count = 0;
        while (num && count++ < 8) {
            s = HEX[(num & 0xf)] + s;
            num >>= 4;
        }
        return s;
    }

};

// int main() {
//     Solution sol;
//     string s = sol.toHex(-1);
//     cout << "string: " << s << endl;
//     return 0;
// }


