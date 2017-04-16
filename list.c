#include "list.h"
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int Element;
    Node_pos Next;
};

int main(int argc, char *argv[])
{
    List L= NULL;
    Create( L );

    Node_pos test;
    test = malloc ( sizeof ( struct Node ) );
    Insert( 2 , L , test);
    printf("%d\n",Retrieve(test) );
}

List Create( List L )
{
    L = ( List ) malloc ( sizeof ( struct Node ) );
    L->Element = -1;
    L->Next = NULL;
    return L;
}

int IsEmpty( List L)
{
    if ( L->Next ==  NULL ) return 1;
    return 0;
}

int IsLast( Node_pos P, List L )
{
    Node_pos P_temp;
    P_temp = L->Next;

    while( P_temp->Next !=  NULL )
    {

        P_temp = P_temp->Next;
    }

    if ( P_temp == P ) return 1;

    return 0;
}

Node_pos Find( int X, List L )
{
    Node_pos P;
    P = L->Next;
    while( P != NULL && P->Element !=X )
    {
        P = P->Next;
    }
    
    return P;
}

void Insert( int X, List L, Node_pos P )
{
    Node_pos Node_temp;

    Node_temp = ( Node_pos ) malloc (sizeof ( struct Node) );
    if( Node_temp == NULL ) printf( "No memory space\n" );

    Node_temp->Element = X;
    Node_temp->Next = P->Next;
    P->Next = Node_temp;
}

void DeleteList( List L )
{
    Node_pos P;
    Node_pos Node_temp;

    P=L->Next;

    while( P!=NULL )
    {
        Node_temp = P->Next;
        free(P);
        P = Node_temp;
    }
}

Node_pos FindPrevious( int X, List L)
{
    Node_pos P;

    P = L;

    while( P->Next != NULL && P->Next->Element != X )
    {
        P = P->Next;
    }
    
    return P;
}

Node_pos Header( List L )
{
    return L;
}

Node_pos First( List L )
{
    return L->Next;
}

Node_pos Advance( Node_pos P)
{
    return P->Next;
}

int Retrieve( Node_pos P )
{
    return P->Element;
}