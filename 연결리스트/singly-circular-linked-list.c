#include <stdio.h>
#include <stdlib.h>

typedef struct _linked{
    int data;
    struct _linked* next;
} linked;

/* 사용자 정의 함수 */
void printMenu(char* command);

int main(void)
{
    int data;
    char command;
    linked* trail = NULL;


    do {
        printMenu(&command);

        switch (command){
        case 'z':
            // initialize();
            break;
        
        case 'p':
            // printList();
            break;
        
        case 'i':
            // insertNode();
            break;
        
        case 'n':
            // insertLast();
            break;
        
        case 'f':
            // insertFirst();
            break;
        
        case 'd':
            // deleteNode();
            break;
        
        case 'e':
            // deleteLast();
            break;
        
        case 't':
            // deleteFirst();
            break;
        
        case 'r':
            // invertList();
            break;
        
        case 'q':
            // freeList();
            break;
        }
    } while(command != 'q');

    return 0;
}

void printMenu(char* command)
{
    printf("\n----------------------------------------------------------------\n");
    printf("                  singly Circular Linked List                   \n");
    printf("----------------------------------------------------------------\n");
    printf(" Initialize    = z           Print         = p \n");
    printf(" Insert Node   = i           Delete Node   = d \n");
    printf(" Insert Last   = n           Delete Last   = e\n");
    printf(" Insert First  = f           Delete First  = t\n");
    printf(" Invert List   = r           Quit          = q\n");
    printf("----------------------------------------------------------------\n");

    printf("Command = ");
    scanf(" %c", command);
}