#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
    int data;
    int exponent;
    char variable;
    struct node *link;
};

void createNode(struct node **head, int num, char variable, int pow);
void display(struct node **head);
void polyOperations(struct node **head1, struct node **head2, int choice);

struct node *head1 = NULL, *head2 = NULL, *head3, *tail, *n, *q, *temp;

int main(){
    createNode(&head1, 4, 'x', 3);
    createNode(&head1, 4, 'y', 3);
    createNode(&head1, 4, 'x', 4);

    printf("\nLink-List 1 : ");
    display(&head1);

    createNode(&head2, -6, 'x', 3);
    createNode(&head2, 3, 'x', 4);
    createNode(&head2, 12, 'y', 4);
    createNode(&head2, 32, 'y', 5);

    printf("\nLink-List 2 : ");
    display(&head2);

    int choice;
    printf("\n\nEnter 1 to Add : \n");
    printf("Enter 2 to Subtract :");
    scanf("%d", &choice);

    while(choice > 0 && choice < 3){
        switch(choice){
            case 1:
                printf("\nSum of Link-List : ");
                polyOperations(&head1, &head2, choice);
                display(&head3);
                break;
            case 2:
                printf("\nDifference of Link-List : ");
                polyOperations(&head1, &head2, choice);
                display(&head3);
                break;
            default:
                printf("You entered an Invalid choice : ");
        }
        printf("\n\nEnter 1 to Add : \n");
        printf("Enter 2 to Subtract :");
        scanf("%d", &choice);
    }
}

void createNode(struct node **head, int num, char variable, int pow){
    if(*head == NULL){
        *head = (struct node *)malloc(sizeof(struct node));
        (*head)->data = num;
        (*head)->variable = variable;
        (*head)->exponent = pow;
        (*head)->link = NULL;
        tail = *head;
    }
    else{
        n = (struct node *)malloc(sizeof(struct node));
        n->data = num;
        n->variable = variable;
        n->exponent = pow;
        n->link = NULL;
        tail->link = n;
        tail = n;
    }
}

void display(struct node **head){
    temp = *head;
    do{
        if(temp->data > 0)
            printf("+");
        printf("%d%c^%d ", temp->data, temp->variable, temp->exponent);
        temp = temp->link;
    }while(temp != NULL);
}

void polyOperations(struct node **head1, struct node **head2, int choice){
    head3 = NULL;
    temp = *head1;
    int flag = 0, value = 0;
    while(temp != NULL){
        q = *head2;
        while(q != NULL){
            if(temp->variable == q->variable && temp->exponent == q->exponent){
                if(choice == 1)
                    createNode(&head3, (temp->data + q->data), temp->variable, q->exponent);
                else
                    createNode(&head3, (temp->data - q->data), temp->variable, q->exponent);
                flag = 1;
            }
            q = q->link;
        }
        if(flag == 0)
            createNode(&head3, temp->data, temp->variable, temp->exponent);
        temp = temp->link;
        flag = 0;
    }

    temp = *head2;
    while(temp != NULL){
        flag = 0;
        n = head3;
        while(n != NULL){
            if(n->variable == temp->variable && n->exponent == temp->exponent)
                flag = 1;
            n = n->link;
        }
        if(flag == 0){
            if(choice == 2)
                value = temp->data * (-1);
            else
                value = temp->data;
            createNode(&head3, value, temp->variable, temp->exponent);
        }
        temp = temp->link;
    }
}
