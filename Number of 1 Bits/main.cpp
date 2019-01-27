class Solution {
public:
    int hammingWeight(uint32_t n) {
        int weight = 0;
        while (n) {
            n = n &+ (n-1);
            weight++;
        }
        return weight;
    }
};
static int fast = [](){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();

// int main(){

//     uint32_t i = 00000000000000000000001100001011;
//     Solution sol;
//     int x = sol.hammingWeight(i);
//     cout << "It is: " << x << endl;

//     return 0;
// }
