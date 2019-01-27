class RandomizedSet {
    vector<int> vec;
    unordered_map<int, int> map;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto found = map.find(val);
        if (found != end(map)) {
            return false;
        }
        vec.push_back(val);
        int index = (int) vec.size() - 1;
        map.insert(make_pair(val, index));
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto found = map.find(val);
        if (found == map.end()) return false;
        int back = vec.back();
        map[back] = map[val];
        vec[map[val]] = back;
        vec.pop_back();
        map.erase(val);
//        vec.erase(vec.begin() + found->second);
//        map.erase(found);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return vec[rand() % vec.size()];
    }
};
int fast = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
