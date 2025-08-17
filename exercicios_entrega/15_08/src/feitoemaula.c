/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void ordena( struct ListNode* head, struct ListNode* prox ) {
    if ( prox == NULL ) {
        return;
    }
    int temp;
    
    if ( head->val > prox->val ) {
        temp = head->val;
        head->val = prox->val;
        prox->val = temp;
        ordena( prox, prox->next );
    } else {
        ordena( prox, prox->next );
    }

}


struct ListNode* sortList(struct ListNode* head) {
    if ( head == NULL ) {
        return head;
    }

    ordena( head, head->next );

    return head;
}