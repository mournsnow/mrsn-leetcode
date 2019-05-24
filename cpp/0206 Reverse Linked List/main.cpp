#include "cpp_util.h"

class Solution
{
public:
    ListNode* reverseList(ListNode* head)
    {
        if (nullptr == head)
        {
            return nullptr;
        }

        ListNode *current = head;
        ListNode *next = head->next;
        ListNode *nextNext = nullptr;

        while (nullptr != next)
        {
            nextNext = next->next;

            if (current == head)
            {
                current->next = nullptr;
            }
            next->next = current;

            current = next;
            next = nextNext;
        }

        return current;
    }
};

int main()
{
    Solution solution;

    vector<int> intList1 = {1, 2, 4};
    ListNode* list1 = ListNode::createList(intList1);

    vector<int> intList2 = {1, 3, 4};
    ListNode* list2 = ListNode::createList(intList2);

    printf("List 1 = [%s]\n", cpp_util::toString(list1).c_str());
    printf("List 2 = [%s]\n", cpp_util::toString(list2).c_str());

    ListNode *reversed1 = solution.reverseList(list1);
    ListNode *reversed2 = solution.reverseList(list2);

    printf("Reversed list 1 = [%s]\n", cpp_util::toString(reversed1).c_str());
    printf("Reversed list 2 = [%s]\n", cpp_util::toString(reversed2).c_str());

    reversed1 = solution.reverseList(reversed1);

    printf("Reversed reversed list 1 = [%s]\n", cpp_util::toString(reversed1).c_str());

    return 0;
}

