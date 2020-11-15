/* Problem - https://leetcode.com/problems/merge-k-sorted-lists/ */
/* By Sanjeet Boora */

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
class Compare {
public:
    bool operator()(ListNode* x, ListNode* y) {
        return x->val > y->val;
    }
};

class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        ListNode* result = new ListNode();
        ListNode* temp = result;


        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;//min heap

        for (int i = 0; i < k; i++) {
            if (lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }

        while (!pq.empty()) {
            ListNode* t = pq.top();
            pq.pop();
            temp->next = t;
            temp = temp->next;
            t = t->next;
            if (t != NULL) {
                pq.push(t);
            }
        }

        return result->next;
    }
};










