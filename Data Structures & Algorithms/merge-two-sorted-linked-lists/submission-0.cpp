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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyNode = new ListNode(0);
        ListNode* temp_one = list1;
        ListNode* temp_second = list2;
        ListNode* temp_third = dummyNode;

        while(temp_one and temp_second){
            if(temp_one->val < temp_second->val){
                temp_third->next = temp_one;
                temp_one = temp_one->next;
                temp_third=temp_third->next;
                temp_third->next = NULL;
            }else{
                temp_third->next = temp_second;
                temp_second = temp_second->next;
                temp_third=temp_third->next;
                temp_third->next = NULL;
            }
        }

        while(temp_one){
            temp_third->next = temp_one;
            temp_one = temp_one->next;
            temp_third=temp_third->next;
            temp_third->next = NULL;
        }

        while(temp_second){
            temp_third->next = temp_second;
            temp_second = temp_second->next;
            temp_third=temp_third->next;
            temp_third->next = NULL;
        }

        return dummyNode->next;
    }
};
