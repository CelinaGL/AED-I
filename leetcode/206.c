struct ListNode* reverseList(struct ListNode* head) {
    if ( head == NULL || head->next == NULL ) {
        return head;
    }

    struct ListNode *cabeca = head, *prox = cabeca->next;
    head->next = NULL;

    
    while ( cabeca != NULL && prox != NULL ) {
        struct ListNode *pos = prox->next;
        prox->next = cabeca;
        cabeca = prox; 
        prox = pos;
    }

    return cabeca;
}