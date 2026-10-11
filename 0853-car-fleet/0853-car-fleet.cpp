class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int , float>> car;
        int n = position.size();
        for(int i = 0 ; i < n ; i++) car.push_back({position[i] , speed[i]});
        sort(car.begin() , car.end());
        for(int i = 0 ; i < n ; i++) car[i].second = (target - car[i].first) / car[i].second;
        int count = 0 ;
        float time = -1.0;
        for(int i = n - 1 ; i >= 0 ; i--) {
            if(car[i].second > time) {
                count++;
                time = car[i].second;
            }
        }
        return count;
    }
};