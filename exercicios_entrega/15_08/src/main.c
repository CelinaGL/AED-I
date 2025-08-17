/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* ordena( struct ListNode* esq, struct ListNode* dir ) {
    struct ListNode molde;
    struct ListNode *r = &molde;
    molde.next = NULL;
    
    while ( esq != NULL && dir != NULL ) {
        if ( esq->val >= dir->val ) {
            r->next = dir;
            dir = dir->next;
        } else {
            r->next = esq;
            esq = esq->next;
        }
        r = r->next;
    }

    if ( esq != NULL ) {
        r->next = esq;
    } else {
        r->next = dir;
    }

    return molde.next;
}

struct ListNode* divide_merge( struct ListNode* head, struct ListNode* prox ) {
    if ( prox == NULL ) {
        return head;
    }
    
    struct ListNode *p1 = head;
    struct ListNode *p2 = prox;

    while ( p2 != NULL && p2->next != NULL ) {
        p1 = p1->next;
        p2 = p2->next->next;
    }

    struct ListNode *meio = p1->next;
    p1->next = NULL;

    struct ListNode *esq = divide_merge(head, head->next);
    struct ListNode *dir = divide_merge(meio, meio->next);

    return ordena( esq, dir );

}

struct ListNode* sortList(struct ListNode* head) {
    if ( head == NULL ) {
        return head;
    }

    return divide_merge( head, head->next );
}