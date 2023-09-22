#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<windows.h>
#include<time.h>

struct node{
    char ch;
    int x, y;
    struct node* link;
};
static int xCoord = 0, yCoord = 0, score = 0, miss = 0;

void gridView();
void createNode(struct node **head, char ch);
void gotoxy(int x, int y);

int main(){
    struct node *head = NULL;
    char userChar;
    char ch;
    srand(time(NULL));

    for(int i = 0; i < 100; i++){
        ch = (rand() % 9) + 97;
        createNode(&head, ch);
    }
    while(score != 60 && miss != 15){
        Sleep(200);
        system("cls");
        gridView();

        if(kbhit())
            userChar = getch();
        for(struct node *temp = head; temp != NULL; temp = temp->link){
            if (temp->y >= 4 && temp->y < 22 && temp->ch != '0'){

                gotoxy(temp->x, temp->y);
                printf("%c", temp->ch);
                if (userChar == temp->ch ) {
                    score++;
                    temp->ch = '0';
                    userChar = ' ';
                 }
            }
            else if (temp->y > 22 && temp->ch != '0') {
                miss++;
                temp->ch = '0';
            }
            temp->y++;
        }
    }
    gotoxy(10, 27);
    printf("\t\t\t\t");

    if (score == 60)
        printf(" Woohoo! you won !\n");
    else if (miss == 15)
        printf(" Oops, you lost !\n");

    Sleep(1000);
    return 0;
}

void gotoxy(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void gridView(){
    int x = 219;
    gotoxy(10,3);

    for (int i =0; i < 75; i++)
        printf("%c",x);
    for (int i = 0, j = 4; i < 20; i++, j++){
        gotoxy(10,j);
        printf("%c                                                                         %c", x, x);
    }
    gotoxy(10,23);
    for (int i = 0; i < 75; i++)
        printf("%c",x);
    gotoxy(35, 24);
    printf("HITS: %d", score);
    gotoxy(50, 24);
    printf("MISS: %d", miss);
    gotoxy(10,25);
}

void createNode(struct node **head, char ch){
    struct node *tail, *n;

    if(*head == NULL){
        xCoord = (rand() % (75-12)+12);
        yCoord = 4;
        *head = (struct node *)malloc(sizeof(struct node));
        (*head)->ch = ch;
        (*head)->x = xCoord;
        (*head)->y = yCoord;
        (*head)->link = NULL;
        tail = *head;
    }
    else{
        yCoord = yCoord - 2;
        xCoord = (rand() % (75-12)+12);

        n = (struct node *)malloc(sizeof(struct node));
        n->ch = ch;
        n->x = xCoord;
        n->y = yCoord;
        n->link = NULL;
        tail->link = n;
        tail = n;
    }
}
