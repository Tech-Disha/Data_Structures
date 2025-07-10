    #include<stdio.h>
    #include<stdlib.h>
    struct node
    {
        int data;
        struct node *next;
    };
    struct node *head;

    void beginsert ();
    void lastinsert ();
    void randominsert();
    void begin_delete();
    void last_delete();
    void random_delete();
    void display();
    void search();
    void main ()
    {
        int choice =0;
            printf("\nCircular Linked List\n");
            printf("\nChoose Option: \n");
        while(choice != 7)
        {
            printf("\n1.Insert in begining\n"
            "2.Insert at last\n"
            "3.Delete from Beginning\n"
            "4.Delete from last\n"
            "5.Search for an element\n"
            "6.Show\n"
            "7.Exit\n");
            printf("\nEnter your choice\n");
            scanf("\n%d",&choice);
            switch(choice)
            {
                case 1:
                beginsert();
                break;
                case 2:
                lastinsert();
                break;
                case 3:
                begin_delete();
                break;
                case 4:
                last_delete();
                break;
                case 5:
                search();
                break;
                case 6:
                display();
                break;
                case 7:
                exit(0);
                break;
                default:
                printf("Invalid Option");
            }
        }
    }
    void beginsert()
    {
        struct node *ptr,*temp;
        int item;
        ptr = (struct node *)malloc(sizeof(struct node));
        if(ptr == NULL)
        {
            printf("\nOVERFLOW\n");
        }
        else
        {
            printf("\nEnter the node data\n");
            scanf("%d",&item);
            ptr -> data = item;
            if(head == NULL)
            {
                head = ptr;
                ptr -> next = head;
            }
            else
            {
                temp = head;
                while(temp->next != head)
                    temp = temp->next;
                ptr->next = head;
                temp -> next = ptr;
                head = ptr;
            }
            printf("\nnode inserted\n");
        }

    }
    void lastinsert()
    {
        struct node *ptr,*temp;
        int item;
        ptr = (struct node *)malloc(sizeof(struct node));
        if(ptr == NULL)
        {
            printf("\nOVERFLOW\n");
        }
        else
        {
            printf("\nEnter Data");
            scanf("%d",&item);
            ptr->data = item;
            if(head == NULL)
            {
                head = ptr;
                ptr -> next = head;
            }
            else
            {
                temp = head;
                while(temp -> next != head)
                {
                    temp = temp -> next;
                }
                temp -> next = ptr;
                ptr -> next = head;
            }

            printf("\nnode inserted\n");
        }

    }

    void begin_delete()
    {
        struct node *ptr;
        if(head == NULL)
        {
            printf("\nUNDERFLOW\n");
        }
        else if(head->next == head)
        {
            head = NULL;
            free(head);
            printf("\nnode deleted\n");
        }

        else
        {   ptr = head;
            while(ptr -> next != head)
                ptr = ptr -> next;
            ptr->next = head->next;
            free(head);
            head = ptr->next;
            printf("\nnode deleted\n");

        }
    }
    void last_delete()
    {
        struct node *ptr, *preptr;
        if(head==NULL)
        {
            printf("\nUNDERFLOW\n");
        }
        else if (head ->next == head)
        {
            head = NULL;
            free(head);
            printf("\nnode deleted\n");

        }
        else
        {
            ptr = head;
            while(ptr ->next != head)
            {
                preptr=ptr;
                ptr = ptr->next;
            }
            preptr->next = ptr -> next;
            free(ptr);
            printf("\nnode deleted\n");

        }
    }

    void search()
    {
        struct node *ptr;
        int item,i=0,flag=1;
        ptr = head;
        if(ptr == NULL)
        {
            printf("\nEmpty List\n");
        }
        else
        {
            printf("\nEnter item which you want to search\n");
            scanf("%d",&item);
            if(head ->data == item)
            {
            printf("Item found at location %d",i+1);
            flag=0;
            }
            else
            {
            while (ptr->next != head)
            {
                if(ptr->data == item)
                {
                    printf("Item found at location %d ",i+1);
                    flag=0;
                    break;
                }
                else
                {
                    flag=1;
                }
                i++;
                ptr = ptr -> next;
            }
            }
            if(flag != 0)
            {
                printf("Item not found\n");
            }
        }

    }

    void display()
    {
        struct node *ptr;
        ptr=head;
        if(head == NULL)
        {
            printf("\nothing to print");
        }
        else
        {
            printf("\n printing values \n");

            while(ptr -> next != head)
            {

                printf("%d\n", ptr -> data);
                ptr = ptr -> next;
            }
            printf("%d\n", ptr -> data);
        }

    }
