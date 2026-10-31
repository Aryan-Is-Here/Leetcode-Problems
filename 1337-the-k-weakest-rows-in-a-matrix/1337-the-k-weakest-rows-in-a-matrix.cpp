class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<pair<int,int>> soldiers;
        for(int i = 0; i < m; i++) {
            int low = 0, high = n;
            while(low < high) {
                int mid = low + (high - low) / 2;
                if(mat[i][mid] == 1) low = mid + 1;
                else high = mid;
            }
            soldiers.push_back({low, i});
        }
        sort(soldiers.begin(), soldiers.end());
        vector<int> ans;
        for(int i = 0; i < k; i++) {
            ans.push_back(soldiers[i].second);
        }
        return ans;
    }
};