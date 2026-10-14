class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin() , people.end());
        int low = 0 , high = people.size() - 1;
        int count = 0;
        while(low <= high) {
            if(people[high] + people[low] > limit) high--;
            else {
                high--;
                low++;
            }
            count++;
        }
        return count;
    }
};