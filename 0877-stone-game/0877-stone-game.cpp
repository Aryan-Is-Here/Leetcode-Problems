class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int start = 0 , end = piles.size() - 1;
        long a1 = 0 , a2 = 0;

        while(start < end) {
            int x = max(piles[start] , piles[end]);
            a1 += x;
            a2 += ((piles[start] + piles[end]) - x);
            start++;
            end--;
        }
        return (a1 > a2);
    }
};