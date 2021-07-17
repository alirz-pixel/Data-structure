#include <stdio.h>
#include <stdlib.h>

typedef struct _listNode{
    int data;
    struct _listNode* next;
    struct _listNode* pre;
} listNode;


/*  ����� ���� �Լ�  */
void printMenu(char* command);
void initialize(listNode** headNode);
void listPrint(listNode* headNode);
void insertNode(listNode* headNode, int data);
void insertLast(listNode* headNode, int data);
void insertFirst(listNode* headNode, int data);
void deleteNode(listNode* headNode, int data);
void deleteLast(listNode* headNode);
void deleteFirst(listNode* headNode);
void invertList(listNode* headNode);
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
                printf("\n������ �����͸� �Է��� �ּ��� : ");
                scanf("%d", &data);
                insertNode(head, data);
                break;

            case 'n':
                printf("\n������ �����͸� �Է��� �ּ��� : ");
                scanf("%d", &data);
                insertLast(head, data);
                break;

            case 'f':
                printf("\n������ �����͸� �Է��� �ּ��� : ");
                scanf("%d", &data);
                insertFirst(head, data);
                break;

            case 'd':
                printf("\n������ �����͸� �Է��� �ּ��� : ");
                scanf("%d", &data);
                deleteNode(head, data);
                break;

            case 'e':
                deleteLast(head);
                break;

            case 't':
                deleteFirst(head);
                break;

            case 'r':
                invertList(head);
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
    (*headNode)->next = *headNode;
    (*headNode)->pre = *headNode;
    (*headNode)->data = 0;
}

void listPrint(listNode* headNode)
{
    if (headNode == NULL)
    {
        printf("Error! : initialize�� ������ �Ŀ� �ٽ� ������ �ּ���\n");
        return;
    }

    if (headNode == headNode->next)
    {
        printf("����Ʈ�� ����ֽ��ϴ�.\n");
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
    printf("\n == ������ �� : %d\n\n", cnt);
}

void insertNode(listNode* headNode, int data)
{
    if (headNode == NULL)
    {
        printf("Error! : initialize�� ������ �Ŀ� �ٽ� ������ �ּ���\n");
        return;
    }


    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    newNode->next = headNode;
    newNode->pre = headNode;
    newNode->data = data;

    // ���� ���Ḯ��Ʈ�� ����ִٸ�
    if (headNode->next == NULL)
    {
        headNode->next = newNode;
        headNode->pre = newNode;
    }

    else
    {
        // �� ���� ã��
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

void insertLast(listNode* headNode, int data)
{
    if (headNode == NULL)
    {
        printf("Error! : initialize�� ������ �Ŀ� �ٽ� ������ �ּ���\n");
        return;
    }


    // head->pre�� ������ ����� ��ġ�̹Ƿ� 
    // head->pre���ٰ� ��带 �����Ѵ�.
    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    newNode->pre = headNode->pre;
    newNode->next = headNode;
    newNode->data = data;

    headNode->pre->next = newNode;
    headNode->pre = newNode;

    return;
}

void insertFirst(listNode* headNode, int data)
{
    if (headNode == NULL)
    {
        printf("Error! : initialize�� ������ �Ŀ� �ٽ� ������ �ּ���\n");
        return;
    }


    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    newNode->pre = headNode;
    newNode->next = headNode->next;
    newNode->data = data;

    headNode->next->pre = newNode;
    headNode->next = newNode;

    return;
}

void deleteNode(listNode* headNode, int data)
{
    if (headNode == NULL)
    {
        printf("Error! : initialize�� ������ �Ŀ� �ٽ� ������ �ּ���\n");
        return;
    }

    if (headNode == headNode->next)
    {
        printf("Error! : ����Ʈ�� ����ֽ��ϴ�.\n");
        return;
    }


    listNode* searchNode = headNode->next;
    
    while(searchNode != headNode)
    {
        if (searchNode->data == data)
        {
            searchNode->pre->next = searchNode->next;
            searchNode->next->pre = searchNode->pre;

            free(searchNode);
            return;
        }

        searchNode = searchNode->next;
    }

    printf("�����ϰ��� �ϴ� ��尡 ����Ʈ�� �����ϴ�.");
    return;
}

void deleteLast(listNode* headNode)
{
    if (headNode == NULL)
    {
        printf("Error! : initialize�� ������ �Ŀ� �ٽ� ������ �ּ���\n");
        return;
    }

    if (headNode == headNode->next)
    {
        printf("Error! : ����Ʈ�� ����ֽ��ϴ�.\n");
        return;
    }


    listNode* delNode = headNode->pre;
    
    delNode->pre->next = headNode;
    headNode->pre = delNode->pre;

    free(delNode);
    return;
}

void deleteFirst(listNode* headNode)
{
    if (headNode == NULL)
    {
        printf("Error! : initialize�� ������ �Ŀ� �ٽ� ������ �ּ���\n");
        return;
    }

    if (headNode == headNode->next)
    {
        printf("Error! : ����Ʈ�� ����ֽ��ϴ�.\n");
        return;
    }


    listNode* delNode = headNode->next;

    delNode->next->pre = headNode;
    headNode->next = delNode->next;

    free(delNode);
    return;
}

void invertList(listNode* headNode)
{
    if (headNode == NULL)
    {
        printf("Error! : initialize�� ������ �Ŀ� �ٽ� ������ �ּ���\n");
        return;
    }

    if (headNode == headNode->next)
    {
        printf("Error! : ����Ʈ�� ����ֽ��ϴ�.\n");
        return;
    }


    listNode* invertNode = headNode;
    listNode* nextNode = headNode->next;

    while(nextNode != headNode)
    {
        invertNode->next = invertNode->pre;
        invertNode->pre = nextNode; // = invertNode->next

        invertNode = nextNode;
        nextNode = nextNode->next;
    }

    invertNode->next = invertNode->pre;
    invertNode->pre = nextNode;

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
