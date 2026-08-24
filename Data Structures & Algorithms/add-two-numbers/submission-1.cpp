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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newLLNodeHead = new ListNode(0);
        ListNode* newLLNode = newLLNodeHead;

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        int extra = 0;

        while(temp1 or temp2){
            
            int sum = extra;

            if(temp1){
                sum+=temp1->val;
                temp1=temp1->next;
            }

            if(temp2){
                sum+=temp2->val;
                temp2=temp2->next;
            }
            
            int temp_extra = 0;
            if(sum > 9){
                temp_extra = sum/10;
                sum = sum%10;
            }

            ListNode* newNode = new ListNode(sum);
            newLLNode->next = newNode;
            newLLNode = newNode;

            extra = temp_extra;
        }

        if(extra != 0){
            ListNode* newNode = new ListNode(extra);
            newLLNode->next = newNode;
        }

        return newLLNodeHead->next;

    }

    ListNode* reverse(ListNode* l){
        ListNode* prev = NULL;
        ListNode* temp = l;

        while(temp){
            ListNode* temp_second = temp->next;
            temp->next=prev;
            prev = temp;
            temp=temp_second;
        }

        return prev;
    }
};
