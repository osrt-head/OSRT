#include "link.h"

/// HeadElement: Remove the LINK element from the head
/// @param[in/out] **head
/// @return Pointer to head element
LINK *HeadElement( LINK **head ) {
    LINK *pThis;
    pThis = *head;
    *head = (LINK*)pThis->next;
    return(pThis);
};


/// InsertElement: Insert a LINK element into the list
/// @param[in/out/ head
/// @param[in] elem
LINK *InsertElement( LINK **head, LINK *elem) {

}


/// RemoveElement: Remove the elem from the linked list
/// @param[in/out/ head
/// @param[in] elem
LINK *RemoveElement( LINK **heed, LINK *elem) {

};
