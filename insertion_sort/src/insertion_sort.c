#include <stdio.h>
#include <stdlib.h>

// Linked List implementation
struct node
{
    int value;
    struct node *next;
    
};

// This accepts a pointer
// It will be able to overwrite the head if its empty
void append_sorted_list( struct node** head, int val )
{
    struct node* insert_node = malloc(sizeof(struct node));
    insert_node->value = val;
    insert_node->next = NULL;
    
    
    // Initialize head if NULL
    if (*head == NULL)
    {
        *head = insert_node;
    }
    
    // Append 
    else
    {
        // 2 3 4 
        // 1
        // Iterator
        struct node* curr = *head;
        
        // Handle Head Special Case
        if  (val <= (*head)->value )
        {
            insert_node->next = *head;
            *head = insert_node;
        }
        
        
        while ( curr != NULL  )
        {   
            // Place to sort
            if ( (curr->value <= val) && (curr->next == NULL || curr->next->value >= val ))
            {
                insert_node->next = curr->next;
                curr->next = insert_node;

                break;
            }
            
            // Continue iterating
            else
            {
                curr = curr->next;
            }
        }
        
        
    }

    
};


void print_linked_list(struct node* head)
{
    struct node* curr = head;
    
    while (curr != NULL)
    {
        printf("Data = %d \n", curr->value);
        curr = curr->next;
    }
}






int main()
{
    printf("Building Linked List \n");
    int count = 1;
    struct node* head = NULL;
    
    int true_bool = 1;
    while ( true_bool )
    {   
        int input;
        // Get the input
        printf("Input data for node %d : ", count);
        int result = scanf("%d", &input);

        if (result == EOF)
        {
            true_bool=0;
            break;
        }
        append_sorted_list(&head, input);
        count += 1;
        
    }
    
    printf("Data entered in the list are: \n");
    print_linked_list(head);
    


    

    return 0;
}
