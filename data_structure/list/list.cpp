typedef struct ListNode{
    struct ListNode *next;
    int              val;
};

//链表逆置

ListNode *ReverseList(ListNode *head) {
    ListNode *pre = NULL, *next;

    while (head != NULL) {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }

    return pre;
}

//判断链表有环

bool isCircle(ListNode *head) {
        
}
