#include <stdio.h>
#include <stdlib.h>
#define null NULL
typedef struct linklistHarry
{
    int data;
    struct linklistHarry *next; // this is self refrencing structure
} node;
node *head, *temp;

void createFirst(int val)
{
    head = (node *)malloc(sizeof(node));
    head->data = val;
    head->next = null;
}
// ------------------------INSERT AT FIRST------------------------------
node *insertAtFirst(int data)
{
    temp = (node *)malloc(sizeof(node));
    temp->next = head;
    temp->data = data;
    head = temp;
    return temp;
}
// -----------------------INSERT AT BETWEEN-----------------//
node *insertAtIndex(int data, int index)
{
    temp = (node *)malloc(sizeof(node));
    node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    temp->data = data;
    temp->next = p->next;
    p->next = temp;

    return head;
}

// ------------------------INSERT AT END-----------------------------//
node *insertAtEnd(int data)
{
    temp = (node *)malloc(sizeof(node));
    node *p = head;
    while (p->next != null)
    {
        p = p->next;
    }
    p->next = temp;
    temp->next = null;
    temp->data = data;
    return head;
}
//---------------------------INSERT AFTER THE NODE----------------------------
// here we will get the address of the previous node of the linked list

node *insertAfterNode(int data, node *prevnode)
{
    temp = (node *)malloc(sizeof(node));
    temp->next = prevnode->next;
    temp->data = data;
    prevnode->next = temp;

    return head;
}
// --------------------------Delete the first----------------------------------
void deletefirst()
{
    temp = head;
    head = head->next;
    free(temp);
}

// --------------------------Delete at index----------------------------------
void deleteAtIndex(int index)
{
    if (index == 0)// if index is 0 than we need to delete the first node
    {
        deletefirst();// this function delete the first node
    }
    else
    {

        node *ttemp;
        ttemp = temp = head->next;// here we start from head -> next because the we want to start from index 1 (for index 0 above condition is applied)
        int i = 1;
        while (i < index)
        {
            ttemp = temp;
            temp = temp->next;
            i++;
        }
        ttemp->next = temp->next;
        free(temp);
    }
}
//-----------------------delete at key-------------------------------------
void deleteAtKey(int key){
    node *ttemp;
    ttemp = temp = head->next;// here we start from head -> next because the we do not want to delete the first node(we should use other methode to delete first node)
    while (temp->data != key)
    {
        ttemp = temp;
        temp = temp->next;
    }
    ttemp->next = temp->next;
    free(temp);
}
// --------------------------terversal----------------------------------------
void terversal()
{
    temp = head;
    while (temp != null)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    // head = (node*)malloc(sizeof(node));
    // head->data = 34;
    // head->next = NULL;
    createFirst(34);
    // -----------------Insertion-------------------------//
    insertAtFirst(45);
    insertAtIndex(85, 1);
    insertAtEnd(67);
    insertAtEnd(56);
    insertAtEnd(90);
    insertAfterNode(34, head);
    terversal();

    // ------------------Deletion-------------------------//
    deletefirst();
    printf("After deleting first :\n");
    terversal();

    deleteAtIndex(2);
    printf("After deleting at index: ");
    terversal();

    deleteAtKey(67);
    printf("After deleting at key : ");
    terversal();
    return 0;
    
}