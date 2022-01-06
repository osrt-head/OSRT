

#ifndef OSRT_LINK_H
#define OSRT_LINK_H

typedef struct link {
    struct link *prev;
    struct link *next;
} LINK;


LINK *HeadElement( LINK **head );
LINK *InsertElement( LINK **head, LINK *elem);
LINK *RemoveElement( LINK **heed, LINK *elem);

#endif //OSRT_LINK_H
