#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
    
};

// Accepts double pointer to be able to modify head without return type being a node pointer
void append_list( struct node** head, int val )
{
    // Initialize head
    if (*head == NULL)
    {
        *head = malloc(sizeof(struct node));
        (*head)->value = val;
        (*head)->next = NULL;
    }
    
    // Append 
    else
    {
        // Iterator
        struct node* curr = *head;
        while ( curr != NULL  )
        {
            // Check if we are one before null
            if ( curr->next == NULL)
            {
                // Initialize new node
                struct node* new = malloc(sizeof(struct node));
                new->value = val;
                new->next = NULL;
                
                curr->next = new;
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


void reverse_linked_list(struct node** head)
{
    struct node* prev = NULL;
    struct node* curr = *head;
    
    while ( curr != NULL )
    {
        // Store next
        struct node* next = curr->next;
        
        // switch
        curr->next = prev;
        
        // move forward
        prev = curr;
        curr = next;

        
    }
    
    *head = prev;
    
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
        append_list(&head, input);
        count += 1;
        
    }
    
    printf("Data entered in the list are: \n");
    print_linked_list(head);
    
    printf("The list in reverse are: \n");
    reverse_linked_list(&head);
    print_linked_list(head);

    

    return 0;
}
