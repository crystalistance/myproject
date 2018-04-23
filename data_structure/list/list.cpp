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

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode fake(0);

    ListNode *head = &fake;

    while (l1 != NULL && l2 != NULL ) {
        if (l1->val <= l2->val) {
            head->next = l1;
            l1 = l1->next;
        } else {
            head->next = l2;
            l2 = l2->next;
        }
        head = head->next;
    }

    if (l1 != NULL) {
        head->next = l1;
    }

    if (l2 != NULL) {
        head->next = l2;
    }

    return (&fake)->next;
}

ListNode *mergeKLists(vector<ListNode *> &lists) {
    priority_queue<ListNode*, vector<ListNode *>, compare> q;

    for (auto l : lists) {
        if (l != NULL) {
            q.push(l);
        }
    }

    if (q.empty()) {
        return NULL;
    }


    ListNode fake(0);
    ListNode *result = &fake;

    while (!q.empty()) {
        result->next = q.top();
        q.pop();

        result = result->next;

        if (result->next != NULL) {
            q.push(result->next);
        }
    }

    return fake.next;
}
