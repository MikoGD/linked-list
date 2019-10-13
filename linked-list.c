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

    insert_node(&head, 'a');
    insert_node(&head, 'c');
    insert_node(&head, 'b');
    print_list(head);    

    return 0;
}//END main()

/*
 * Will insert a node into the beginning of the list or
 * at the position appropriate to it's data.
 * For example if the list is [a, c] and the data is b.
 * It will insert it inbetween a anc c to get [a, b, c].
 */
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
    
    /* If the list is empty, Add the new node in at the beginning of the list.
     * Else create a pointer previous_node and go through the list until the 
     * current node it is on data is greater than the new node's data.
     * Insert the node before the current node.
     * Or if the the next_node member of the current node is NULL, insert it
     * after current node.
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
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }//END IF

    Alpha *current_node = head;

    do
    {
        printf("Address of current node: %p\n", current_node);
        printf("Data -> %c\n", current_node->data);
        printf("Next_node -> %p\n\n", current_node->next_node);

        //Make the current_node the next one
        current_node = current_node->next_node;
    }//END DO
    //Checks if the node it is on is empty
    while (current_node != NULL);
}//END print_list()

/*
 * Go through the list until you find the node that the value of data.
 * Return previous node pointing to the node with the value of data.
 * If it reaches the end of the list return the last node.
 */
Alpha *search_list(Alpha **head_ptr, char data)
{
    Alpha *previous_node = NULL;
    Alpha *current_node = *head_ptr;
    
    /*
     * Checks if the node it is on data is equal to what we are looking for
     * or the next node it is looking for is NULL ie current_node is at the
     * end of the list.
     * Return current_node
     */
    if (current_node->data == data || current_node->next_node == NULL)
    {
        return current_node;
    }
    
    /*
     * Goes through the linked list and checks if it is at the end 
     * i.e. current_node-> node == NULL
     * and if the data of the current node is greater then what we are looking for.
     * If they are both false move to the next node by making the current node the
     * previous node and the current node the next node that it was pointing to.
     */
    while (current_node->next_node != NULL && current_node->data < data)
    {
        previous_node = current_node;
        current_node = current_node->next_node;
    }//END WHILE

    if (current_node->data < data)
    {
        printf("Reached end of list\n");
        return current_node;
    }

    return previous_node;
}//END search_list()
