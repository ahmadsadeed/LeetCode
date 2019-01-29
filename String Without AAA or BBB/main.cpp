class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string s = "";
        int len = A+B;
        for (int i = 0; i < len; i++) {
            if (s.size() >= 2) {
                if ((s[i-1] == 'a' && s[i-2] == 'a') && B != 0) {
                    s += ('b'); B--;
                } else if ((s[i-1] == 'b' && s[i-2] == 'b') && A != 0){
                    s += ('a'); A--;
                } else {
                    if (A > B) {
                        s += "a"; A--;
                    } else {
                        s += "b"; B--;
                    }
                }
            } else {
                if (A > B && A != 0) {
                    s += "a"; A--;
                } else {
                    if (B != 0) {
                        s += "b"; B--;
                    }
                }
            }
        }
        return s;
    }
};
