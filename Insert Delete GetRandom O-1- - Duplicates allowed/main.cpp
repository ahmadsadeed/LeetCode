// #include <iostream>
// #include <vector>
// #include <cstdlib>
// #include <algorithm>
// #include <string>
// #include <unordered_map>
// #include <unordered_set>

// using namespace std;


class RandomizedCollection {
public:
    vector<int> v;
    unordered_map<int, unordered_set<int>> m;

    /** Initialize your data structure here. */
    RandomizedCollection() {

    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        m[val].insert((int)v.size());
        v.push_back(val);
        return m[val].size() == 1;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (m.find(val) == m.end())
            return false;
        m[v.back()].erase((int)v.size() - 1);
        if (val != v.back()) {
            int first = *m[val].begin();
            v[first] = v.back();
            m[v.back()].insert(first);
            m[val].erase(first);
        }
        v.pop_back();
        if (m[val].size() == 0) m.erase(val);
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        return v[rand() % v.size()];
    }
};
static int fast=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    return 0;
}();
/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

/*

int main(){
    RandomizedCollection obj;
    bool p1 = obj.insert(1);
    bool p12 = obj.insert(1);
    bool p2 = obj.insert(2);
    bool p3 = obj.insert(3);
    bool p4 = obj.insert(4);
    bool r2 = obj.remove(2);
    int ra1 = obj.getRandom();

    cout <<"param1: "<< p1 << endl;
    cout <<"param12: "<< p12 << endl;
    cout <<"param2: "<< p2 << endl;
    cout <<"param3: "<< p3 << endl;
    cout <<"param4: "<< p4 << endl;
    cout <<"r2: "<< r2 << endl;
    cout <<"rand1: "<< ra1 << endl;

    vector<int> v = obj.v;
    unordered_map<int, unordered_set<int>> m = obj.m;

    cout << endl;
    for (auto in : v) {
        cout << in << ", " ;
    }
    cout << endl;
    for (auto pair : m) {
        cout << pair.first << "-";
    }
    cout << endl;

    return 0;
}

 */
