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

void delete_node(Alpha **, char data);
void insert_node(Alpha **, char data);
void print_list(Alpha *);
void print_node(Alpha *, char data);

Alpha *search_list(Alpha **, char data);

void display_menu(Alpha **head_ptr);

int main()
{
    // Where the list starts
    // The head will point to the first node of the list when the first node
    // exits
    Alpha *head = NULL;
    Alpha **head_ptr = &head;
    
    while (1)
    {
        display_menu(head_ptr);
    }//END WHILE

    return 0;
}//END main()

void delete_node(Alpha **head_ptr, char data)
{
    if (*head_ptr == NULL)
    {
        printf("List is empty\n\n");
    }
    else
    {
        Alpha *previous_node = NULL;
        Alpha *temp_node = NULL;

        previous_node = search_list(head_ptr, data);
        temp_node = previous_node->next_node;
        previous_node->next_node = previous_node->next_node->next_node;

        free(temp_node);
    }//END IF
}//END delete_node()

/*
 * Will insert a node into the beginning of the list or
 * at the position appropriate to it's data.
 * For example if the list is [a, c] and the data is b.
 * It will insert it inbetween a anc c to get [a, b, c].
 */
void insert_node(Alpha **head_ptr, char data)
{ 
    //Declarations
    Alpha *previous_node;
    Alpha *current_node;

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
    
    previous_node = NULL;
    current_node = *head_ptr;

    //Walk through list
    while (current_node != NULL && current_node->data < data)
    {
        previous_node = current_node;
        current_node = current_node->next_node;
    }//END WHILE

    if (previous_node == NULL)
    {
        new_node->next_node = NULL;
        *head_ptr = new_node;
    }
    else
    {
        new_node->next_node = current_node;
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

    printf("------------------------------------------\n\n");
}//END print_list()

void print_node(Alpha *head_ptr, char data)
{
    Alpha *current_node = NULL;
    
    if (data == head_ptr->data)
    {
        current_node = search_list(&head_ptr, data);
    }
    else
    {
        current_node = (search_list(&head_ptr, data))->next_node;
    }

    printf("Address of current node: %p\n", current_node);
    printf("Data -> %c\n", current_node->data);
    printf("Next_node -> %p\n\n", current_node->next_node);
    printf("------------------------------------------\n\n");
}//END print_node()

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
     * or the next node it is looking for is NULL ie there is only node
     * as current_node at this point is the head
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

    if (current_node->next_node == NULL)
    {
        return previous_node;
    }

    return previous_node;
}//END search_list()

void display_menu(Alpha **head_ptr)
{
    char user_input;
    
    printf("Enter 1: Insert new node\n");
    printf("Enter 2: Delete a node\n");
    printf("Enter 3: Display list\n");
    printf("Enter 4: Display node details\n");
    printf("Enter 5: Exit\n\n");

    printf("Enter: ");
    scanf("%[^\n]%*c", &user_input);
    printf("\n");

    switch (user_input)
    {
        case '1':
            printf("Enter the data you wish to insert: ");
            scanf("%[^\n]%*c", &user_input);
            printf("\n");

            insert_node(head_ptr, user_input);

            break;
        //END CASE

        case '2':
            printf("Enter the data you wish to delete: ");
            scanf("%[^\n]%*c", &user_input);
            printf("\n");

            delete_node(head_ptr, user_input);

            break;
        //END CASE
        
        case '3':
            print_list(*head_ptr);

            break;
        //END CASE
        
        case '4':
            printf("Enter the data you wish to display: ");
            scanf("%[^\n]%*c", &user_input);
            printf("\n");

            print_node(*head_ptr, user_input);

            break;
        //END CASE

        case '5':
            printf("Exiting....\n\n");
            
            exit(0);
            break;
        //END CASE
        
        default:
            printf("ERROR: not a valid menu option\n\n");
    }//END switch()
}//END display_menu()
