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
    pair<ListNode* , int> reverselist(ListNode* head) {
        ListNode* curr = head , *next , *prev = nullptr;
        int count = 0;
        while(curr) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        return {prev , count};
    }
    vector<int> nextLargerNodes(ListNode* head) {
        auto t = reverselist(head);
        int n = t.second;
        vector<int> ans(n , 0);
        int i = n - 1;
        stack<int>st;
        ListNode* curr = t.first;
        while(curr) {
            while(!st.empty() && st.top() <= curr -> val) st.pop();
            if(!st.empty()) ans[i] = st.top();
            st.push(curr -> val);
            curr = curr -> next;
            i--;
        }
        return ans;
    }
};