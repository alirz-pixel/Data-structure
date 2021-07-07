#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _listNode {
    int data;
    struct _listNode* link;
} listNode;


void inputAscending(bool* Ascending);
void printMenu();
void initialize(listNode** head);
void printList(listNode* head);
void insertNode(listNode* head, int data, bool Ascending);
void insertLast(listNode* head, int data);
void insertFirst(listNode* head, int data);
void deleteNode(listNode* head, int data);
void deleteLast(listNode* head);
void deleteFirst(listNode* head);
void invertList(listNode* head);
void freeNode(listNode* head);

int main(void)
{
    bool Ascending = false; // ������������ ����Ʈ�� ������ ������ ���� ����
    char command;  int data;
    listNode* headNode;


    inputAscending(&Ascending);
    do {
        printMenu(&command);

        switch(command) {
            case 'z':
                initialize(&headNode);
                break;

            case 'p':
                printList(headNode);
                break;

            case 'i':
                printf("�����Ϸ��� �����͸� �Է����ּ���. : ");
                scanf("%d", &data);
                insertNode(headNode, data, Ascending);
                break;

            case 'n':
                printf("�����Ϸ��� �����͸� �Է����ּ���. : ");
                scanf("%d", &data);
                insertLast(headNode, data);
                break;

            case 'f':
                printf("�����Ϸ��� �����͸� �Է����ּ��� : ");
                scanf("%d", &data);
                insertFirst(headNode, data);
                break;
                
            case 'd':
                printf("�����Ϸ��� �����͸� �Է����ּ���. : ");
                scanf("%d", &data);
                deleteNode(headNode, data);
                break;

            case 'e':
                deleteLast(headNode);
                break;

            case 't':
                deleteFirst(headNode);
                break;

            case 'r':
                invertList(headNode);
                break;

            case 'q':
                freeNode(headNode);
        }
    } while(command != 'q');

    return 0;
}

void inputAscending(bool* Ascending)
{
    printf("������������ �����Ͻðڽ��ϱ�?\n");
    printf("0. No   1. Yes\n");
    printf("---------------\n");
    printf("�Է� : ");
    scanf("%d", &Ascending);
}

void printMenu(char *command)
{  
	printf("\n----------------------------------------------------------------\n");
	printf("                     Singly Linked List                         \n");
	printf("----------------------------------------------------------------\n");
	printf(" Initialize    = z           Print         = p \n");
	printf(" Insert Node   = i           Delete Node   = d \n");
	printf(" Insert Last   = n           Delete Last   = e\n");
	printf(" Insert First  = f           Delete First  = t\n");
	printf(" Invert List   = r           Quit          = q\n");
	printf("----------------------------------------------------------------\n");

	printf("Command = ");
	scanf(" %c", command);

    printf("\n");
}

void initialize(listNode** head)
{
    if((*head) != NULL)
        freeNode(*head);

    (*head) = (listNode*)malloc(sizeof(listNode));
    (*head)->link = NULL;
    (*head)->data = 0;
}

void printList(listNode* head)
{
    if (head == NULL)
    {
        printf("error! : initialize�� �������ּ���.\n\n");
        return;
    }

    if (head->link == NULL)
    {
        printf("error! : ����Ʈ�� ����ֽ��ϴ�.\n\n");
        return;
    }


    int cnt = 0;
    listNode* searchNode = head->link;
    while(searchNode != NULL)
    {
        printf(" [%d] ->", searchNode->data);
        searchNode = searchNode->link;
        cnt++;
    }
    printf("\n == ������ �� : %d\n\n", cnt);
}

void insertNode(listNode* head, int data, bool Ascending)
{
    if (head == NULL)
    {
        printf("error! : initialize�� �������ּ���.\n\n");
        return;
    }


    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = data;
    newNode->link = NULL;
    // ����Ʈ�� ����ִٸ�
    if (head->link == NULL)
        head->link = newNode;

    // �ϳ� �̻��� �����Ͱ� ����ִٸ�
    else
    {
        listNode* previous = head;
        listNode* searchNode = head->link;
        while(searchNode != NULL)
        {
            if (Ascending && searchNode->data > newNode->data)
                break;

            else if (!Ascending && searchNode->data < newNode->data)
                break;
 
            previous = searchNode;
            searchNode = searchNode->link;
        }

        previous->link = newNode;
        newNode->link = searchNode;
    }
}

void insertLast(listNode* head, int data)
{
    if (head == NULL)
    {
        printf("error! : initialize�� �������ּ���.\n\n");
        return;
    }


    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = data;
    newNode->link = NULL;

    listNode* searchNode = head;
    while(searchNode->link != NULL)
        searchNode = searchNode->link;
    
    searchNode->link = newNode;
    return;
}

void insertFirst(listNode* head, int data)
{
    if (head == NULL)
    {
        printf("error! : initialize�� �������ּ���.\n\n");
        return;
    }

    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = data;
    newNode->link = head->link;

    head->link = newNode;
    return;
}

void deleteNode(listNode* head, int data)
{
    if (head == NULL)
    {
        printf("error! : initialize�� �������ּ���.\n\n");
        return;
    }

    listNode* previous = head;
    listNode* searchNode = head->link;
    while(searchNode != NULL)
    {
        if (searchNode->data == data)
        {  
            previous->link = searchNode->link;
            free(searchNode);

            printf("ã�����ϴ� �����͸� �����Ͽ����ϴ�.\n\n");
            return;
        }

        previous = searchNode;
        searchNode = searchNode->link;
    }

    printf("�����ϰ��� �ϴ� �����Ͱ� �����ϴ�.\n\n");
    return;
}

void deleteLast(listNode* head)
{
    if (head == NULL)
    {
        printf("error! : initialize�� �������ּ���.\n\n");
        return;
    }

    if (head->link == NULL)
    {
        printf("error! : ����Ʈ�� ����ֽ��ϴ�.\n\n");
        return;
    }


    listNode* previous = head;
    listNode* searchNode = head->link;
    while(searchNode->link != NULL)
    {
        previous = searchNode;
        searchNode = searchNode->link;
    }
    previous->link = searchNode->link;
    free(searchNode);
    return;
}

void deleteFirst(listNode* head)
{
    if (head == NULL)
    {
        printf("error! : initialize�� �������ּ���.\n\n");
        return;
    }

    if (head->link == NULL)
    {
        printf("error! : ����Ʈ�� ����ֽ��ϴ�.\n\n");
        return;
    }


    listNode* delNode = head->link;
    head->link = delNode->link;
    free(delNode);
}

void invertList(listNode* head)
{
    if (head == NULL)
    {
        printf("error! : initialize�� �������ּ���.\n\n");
        return;
    }

    if (head->link == NULL)
    {
        printf("error! : ����Ʈ�� ����ֽ��ϴ�.\n\n");
        return;
    }


    listNode* trail = NULL;
    listNode* mid = NULL;
    listNode* front = head->link;
    while(front != NULL)
    {
        trail = mid;
        mid = front;
        front = front->link;

        mid->link = trail;
    }
    head->link = mid;
    return;
}

void freeNode(listNode* head)
{
    if (head == NULL)
        return;

    listNode* previous = head;
    listNode* searchNode = head->link;

    printf("\n");
    while(searchNode != NULL)
    {
        printf("[%d] ��带 �����߽��ϴ�.\n", previous->data);
        free(previous);

        previous = searchNode;
        searchNode = searchNode->link;
    }
    printf("[%d] ��带 �����߽��ϴ�.", previous->data);
    free(previous);
}