class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> vToReturn;
        map<double,int, std::less<double>> map;
        for (int x = 0; x < points.size(); x++) {
            vector<int> vPair = points[x];
            double distance = sqrt(pow(vPair[0], 2) + pow(vPair[1], 2));
//            cout<< "sqrt: "<< distance<<endl;
            map.insert(make_pair(distance, x));
        }
        for (int i = 0; i < K; i++) {
            auto p = map.begin();
            vToReturn.push_back(points[p->second]);
            auto it = map.find(map.begin()->first);
            map.erase (it);
        }
        return vToReturn;
    }
};
