class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end(), std::greater<int>());
        vector<int> v;
        for (int x = 0; x < A.size() - 2; x++) {
//            if (x == A.size()-2) {
//                break;
//            }
            int a = A[x];
            int b = A[(x+1)];
            int c = A[(x+2)];
//            cout << "a: "<< a<< endl;
//            cout << "b: "<< b<< endl;
//            cout << "c: "<< c<< endl;
            if ((a+b )<=c || (b+c )<=a || (c+a)<=b ) {
                continue;
            } else {
                int para = (a + b + c);
//                cout << "para: "<< para<< endl;
                v.push_back(para);
            }
//            if ((a == b && b == c)) {
//                int para = (a + b + c);
//                cout << "para: "<< para<< endl;
//                v.push_back(para);
//            } else if ((a==b) || (a==c) || (b==c)){
//                int para = (a + b + c);
//                cout << "para2: "<< para<< endl;
//                v.push_back(para);
//            }

        }

        sort(v.begin(), v.end(), std::greater<int>());
        if (v.size() > 0) {
            return v[0];
        }
        return 0;
    }
};
