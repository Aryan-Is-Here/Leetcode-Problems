class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int>distance;
        int count = 0 , n = seats.size();
        int x = 0;
        while(seats[x] == 0) {
            distance.push_back(0);
            x++;
        }
        for(int i = x ; i < n ; i++) {
            if(seats[i] == 1) count = 0;
            else count++;
            distance.push_back(count);
        }
        count = 0;
        while(x > 0) {
            x--;
            count++;
            distance[x] = count;
        }
        count = 0 , x = n - 1;
        int ans = distance[n - 1];
        while(seats[x] == 0) x--;
        for(int i = x ; i >= 0 ; i--) {
            if(seats[i] == 1) count = 0;
            else count++;
            distance[i] = min(distance[i] , count);
            ans = max(distance[i] , ans);
        }
        return ans;
    }
};