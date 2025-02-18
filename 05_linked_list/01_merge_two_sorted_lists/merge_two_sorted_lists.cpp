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

struct ListNode
{
    int       val;
    ListNode* next;
    ListNode() : val(0), next(nullptr)
    {
    }
    ListNode(int x) : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode* next) : val(x), next(next)
    {
    }
};

class Solution
{
  public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if (!list1 && !list2)
            return nullptr;
        else if (!list1 && list2)
            return list2;
        else if (list1 && !list2)
            return list1;
        ListNode* merged;
        ListNode* last;
        if (list1->val < list2->val)
        {
            merged = list1;
            list1 = list1->next;
        }
        else
        {
            merged = list2;
            list2 = list2->next;
        }
        last = merged;
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                last->next = list1;
                list1 = list1->next;
            }
            else
            {
                last->next = list2;
                list2 = list2->next;
            }
            last = last->next;
        }
        if (list1)
            last->next = list1;
        else if (list2)
            last->next = list2;
        return merged;
    }
};