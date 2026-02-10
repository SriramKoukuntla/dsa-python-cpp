SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* dummy = new SinglyLinkedListNode(-1);
    dummy->next = llist;
    SinglyLinkedListNode* curr = dummy;
    for (int i = 0; i < position; ++i) curr = curr->next;
        
    SinglyLinkedListNode* temp = new SinglyLinkedListNode(data);
    temp->next = curr->next;
    curr->next = temp;
    
    SinglyLinkedListNode* res = dummy->next;
    delete dummy;
    
    return res;
}