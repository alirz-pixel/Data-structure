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
void listPrint(listNode* headNode);
void insertNode(listNode* headNode, int data);
void freeNode(listNode* headNode);


int main(void)
{
    int data;
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
                listPrint(head);
                break;

            case 'i':
                printf("\n삽입할 데이터를 입력해 주세요 : ");
                scanf("%d", &data);
                insertNode(head, data);
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

void listPrint(listNode* headNode)
{
    if (headNode == NULL)
    {
        printf("Error! : initialize를 진행한 후에 다시 진행해 주세요\n");
        return;
    }

    if (headNode == headNode->next)
    {
        printf("리스트가 비어있습니다.\n");
        return;
    }

    int cnt = 0;
    listNode* searchNode = headNode->next;
    while(searchNode != headNode)
    {
        printf(" [%d] ->", searchNode->data);
        searchNode = searchNode->next;
        cnt++;
    }
    printf("\n == 데이터 수 : %d\n\n", cnt);
}

void insertNode(listNode* headNode, int data)
{
    if (headNode == NULL)
    {
        printf("Error! : initialize를 진행한 후에 다시 진행해 주세요\n");
        return;
    }


    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    newNode->next = headNode;
    newNode->pre = headNode;
    newNode->data = data;

    // 이중 연결리스트가 비어있다면
    if (headNode->next == NULL)
    {
        headNode->next = newNode;
        headNode->pre = newNode;
    }

    else
    {
        // 들어갈 공간 찾기
        listNode* searchNode = headNode->next;

        while(searchNode != headNode)
        {
            if (data < searchNode->data)
                break;
            
            searchNode = searchNode->next;
        }

        newNode->next = searchNode;
        newNode->pre = searchNode->pre;

        searchNode->pre->next = newNode;
        searchNode->pre = newNode;
    }

    return;
}

void freeNode(listNode* headNode)
{
    if (headNode == NULL)
        return;

    listNode* deleteNode = headNode;
    listNode* searchNode = headNode->next;

    while(searchNode != headNode)
    {
        free(deleteNode);

        deleteNode = searchNode;
        searchNode = searchNode->next;
    }
    free(deleteNode);

    return;
}
