#include <iostream>

using namespace std;

struct ListNode
{
    ~ListNode()
    {
        if (m_pNext)
            delete m_pNext;
    }

    int       val = 0;
    ListNode* m_pNext = nullptr;
};

int main()
{
    while (true)
    {
        int len = 0;
        cin >> len;
        if (cin.eof())
            break;
        ListNode* head = new ListNode();
        ListNode* node = head;
        for (int i = 0; i < len; ++i)
        {
            int val;
            cin >> val;
            node->val = val;
            if (i != len - 1)
            {
                node->m_pNext = new ListNode();
                node = node->m_pNext;
            }
        }

        int k;
        cin >> k;
        ListNode* kth_to_last = head;
        for (int i = 0; i < len - k; ++i)
            kth_to_last = kth_to_last->m_pNext;
        cout << kth_to_last->val << "\n";
    }
}