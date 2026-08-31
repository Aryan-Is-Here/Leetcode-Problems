/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans(2 , -1);
        vector<int> check;
        int count = 2;
        ListNode *curr = head -> next , *prev = head , *nex = head -> next -> next;
        while(nex) {
            if(curr -> val < prev -> val && curr -> val < nex -> val) check.push_back(count);
            else if(curr -> val > prev -> val && curr -> val > nex -> val) check.push_back(count);
            prev = curr;
            curr = nex;
            nex = nex -> next;
            count++;
        }
        if(check.size() < 2) return ans;
        ans[1] = check[check.size() - 1] - check[0];
        int x = check[1] - check[0];
        for(int i = 1 ; i < check.size() ; i++) x = min(x , check[i] - check[i - 1]);
        ans[0] = x;
        return ans;
    }
};