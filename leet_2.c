/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 /*基本思路: 按位相加*/
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int val, res, num1, num2;
    struct ListNode *tmp1, *tmp2, *temp;
    struct ListNode *result;
    struct ListNode *tail;
    res = 0;
    tmp1 = l1;
    tmp2 = l2;
    result = malloc(sizeof(struct ListNode));
    if (result)
    {
        result->val = 0;
        tail = result;
        while (tmp1 || tmp2)
        {
            if (tmp1 && tmp2)
            {
                val = tmp1->val + tmp2->val + res;
                tmp1 = tmp1->next;
                tmp2 = tmp2->next;
            }
            else if (tmp1 == NULL && tmp2)
            {
                val = 0 + tmp2->val + res;
                tmp2 = tmp2->next;
            }
            else if (tmp2 == NULL && tmp1)
            {
                val = tmp1->val + 0 + res;
                tmp1 = tmp1->next;
            }
            res = val / 10;
            val = val % 10;
            tail->next = malloc(sizeof(struct ListNode));
            tail = tail->next;
            tail->val = val;
            tail->next = NULL;
        }
        if (res && !tmp1 && !tmp2)
        {
            tail->next = malloc(sizeof(struct ListNode));
            tail = tail->next;
            tail->val = res;
            tail->next = NULL;
        }
        return result->next;
    }
    return NULL;
}
