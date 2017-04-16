#ifndef _LIST_H

struct Node;
typedef struct Node* Node_ptr;
typedef Node_ptr List;
typedef Node_ptr Node_pos;

List Create( List L );
int IsEmpty( List L );
int IsLast( Node_pos P,List L );
Node_pos Find( int X, List L );
void Delete( int X, List L );
Node_pos FindPrevios( int X, List L );
void Insert( int X, List L, Node_pos P );
void DeleteList( List L );
Node_pos Header( List L );
Node_pos First( List L );
Node_pos Advance( Node_pos P );
int Retrieve( Node_pos P );

#endif