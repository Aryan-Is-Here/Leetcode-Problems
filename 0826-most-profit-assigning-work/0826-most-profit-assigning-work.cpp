class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int , int>>job;
        int n = profit.size();
        for(int i = 0 ; i < n ; i++) job.push_back({difficulty[i] , profit[i]});
        sort(job.begin() , job.end() , greater<pair<int , int>>());
        for(int i = n - 2 ; i >= 0 ; i--) if(job[i].second < job[i + 1].second) job[i].second = job[i + 1].second;
        sort(worker.begin() , worker.end() , greater<int>());
        int sum = 0 , i = 0 , j = 0 , m = worker.size();
        while(i < n && j < m) {
            if(worker[j] < job[i].first) i++;
            else {
                sum += job[i].second;
                j++;
            }
        }
        return sum;
    }
};