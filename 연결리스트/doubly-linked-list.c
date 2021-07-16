#include <stdio.h>
#include <stdlib.h>

typedef struct _listNode{
    int data;
    struct _listNode* next;
    struct _listNode* pre;
} listNode;


/*  사용자 정의 함수  */
void printMenu(char* command);
void initialize(listNode** headNode);
void freeNode(listNode* headNode);


int main(void)
{
    char command;
    listNode* head = NULL;

    do {
        printMenu(&command);

        switch(command)
        {
            case 'z':
                initialize(&head);
                break;

            case 'p':
                break;

            case 'i':
                break;

            case 'd':
                break;

            case 'n':
                break;

            case 'e':
                break;

            case 'f':
                break;

            case 't':
                break;

            case 'r':
                break;

            case 'q':
                freeNode(head);
                break;
        }
    } while(command != 'q');

    return 0;
}

void printMenu(char* command)
{
    printf("\n----------------------------------------------------------------\n");
    printf("                     Doubly Linked  List                        \n");
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


void initialize(listNode** headNode)
{
    if (*headNode != NULL)
        freeNode(*headNode);

    (*headNode) = (listNode*)malloc(sizeof(listNode));
    (*headNode)->next = NULL;
    (*headNode)->pre = NULL;
    (*headNode)->data = 0;
}

void freeNode(listNode* headNode)
{
    if (headNode == NULL)
        return;

    listNode* deleteNode = headNode;
    listNode* searchNode = headNode->next;

    while(searchNode != NULL)
    {
        free(deleteNode);

        deleteNode = searchNode;
        searchNode = searchNode->next;
    }
    free(deleteNode);

    return;
}
