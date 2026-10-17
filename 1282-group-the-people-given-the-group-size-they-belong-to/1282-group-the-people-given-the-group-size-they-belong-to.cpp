class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<pair<int , int>>people;
        vector<vector<int>> ans;
        int n = groupSizes.size();
        for(int i = 0 ; i < n ; i++) people.push_back({groupSizes[i] , i});
        sort(people.begin() , people.end());
        for(int i = 0 ; i < n ; ) {
            int j = people[i].first;
            vector<int>a;
            while(j > 0 && i < n) {
                a.push_back(people[i].second);
                i++;
                j--;
            }
            ans.push_back(a);
        }
        return ans;
    }
};