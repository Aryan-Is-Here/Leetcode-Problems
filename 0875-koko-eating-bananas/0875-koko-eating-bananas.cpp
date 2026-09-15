class Solution {
public:
    int helper(vector<int>& piles , int mid) {
        int count = 0 , n = piles.size();
        for(int i = 0 ; i < n ; i++) count += (piles[i] + mid - 1) / mid;
        return count;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1 , high = *max_element(piles.begin(), piles.end());
        while(low < high) {
            int mid = low + (high - low) / 2;
            int x = helper(piles , mid);
            if(x > h) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};