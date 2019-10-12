/*
 * Program description: A program to impliment a simple alphabet linked list
 * Author: Mikael Escolin
 * Date started: 11/10/19
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct AlphaNode
{
    char data;
    struct AlphaNode *next_node;
} Alpha;

void insert_node(Alpha **, char data);
void delete_node(Alpha **, char data);
void print_list(Alpha *);
void print_node(Alpha *, char data);

Alpha *search_list(Alpha **, char data);

int main()
{
    // Where the list starts
    // The head will point to the first node of the list when the first node
    //  exits
    Alpha *head = NULL;

    print_list(head);    

    return 0;
}//END main()

void insert_node(Alpha **head_ptr, char data)
{ 
    // Create new node
    Alpha *new_node = (Alpha *) malloc(sizeof(Alpha));
    
    // Checks if memory was allcoated
    // If yes assign the member's values
    if (new_node != NULL)
    {
        new_node->data = data;
        new_node->next_node = NULL;
    }
    else
    {
        printf("ERROR: Not enough memory to create a new node\n\n");
        return;
    }
    
    /* If the list is empty
     *  Add the new node in at the beginning of the list.
     * Else create a pointer previous_node
     *  and go through the list until the current node it is on data is greater than the
     *  new node's data.
     * Insert the node before the current node.
     */

    if (*head_ptr == NULL)
    {
        *head_ptr = new_node;
        new_node->next_node = NULL;
    }
    else
    {
        Alpha *previous_node = NULL;

        previous_node = search_list(head_ptr, data);
        new_node->next_node = previous_node->next_node;
        previous_node->next_node = new_node;
    }//END IF
}//END insert_node()

// Print the list
void print_list(Alpha *head)
{
    Alpha *current_node = head->next_node;
    do
    {
        printf("Address of current node: %p\nData -> %c\nnext_node -> %p\n\n", current_node, current_node->data, current_node->next_node);
    }//END DO
    while (head != NULL);
}//END print_list()
