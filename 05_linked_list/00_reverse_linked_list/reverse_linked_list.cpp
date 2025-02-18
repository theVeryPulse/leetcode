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
    ListNode* reverseList(ListNode* head)
    {
        if (!head || !head->next)
            return head;
        ListNode* prev = head;
        ListNode* node = prev->next;
        ListNode* next = prev->next->next;
        head->next = nullptr;
        while (node)
        {
            node->next = prev;
            prev = node;
            node = next;
            if (node)
                next = node->next;
        }
        return prev;
    }
};

int main()
{
}
