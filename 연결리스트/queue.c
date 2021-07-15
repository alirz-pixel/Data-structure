/*
 �� �ڵ��� ��� �Լ���(initialize ����) initialize�� ������ �Ŀ�
 ����ȴٴ� ���� �������� �Ͽ� ���۵Ǿ����ϴ�.

 �̿��Ͻ÷��� initialize���� �����Ͻ� �Ŀ� �ٸ� �Լ��� ȣ���ϼž�
 �����ϰ� �̿밡���մϴ�.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node* next;
} Node;

typedef struct _Queue {
    Node* front;
    Node* rear;

    int size;
} Queue;


void printMenu(char *command);
void initialize(Queue** queue);
void printQueue(Queue* queue);
void push(Queue* queue, int data);
void pop(Queue* queue);
int size(Queue* queue);
int empty(Queue* queue);
int front(Queue* queue);
int rear(Queue* queue);
void freeQueue(Queue* queue);

int main(void)
{
    Queue* queue = NULL;
    char command;
    int data;


    do {
        printMenu(&command);

        switch(command)
        {
            case 'z':
                initialize(&queue);
                break;

            case 'u':
                printQueue(queue);
                break;

            case 'p':
                printf(" ���ÿ� ������ �����͸� �����ּ���. : ");
                scanf("%d", &data);
                push(queue, data);
                break;

            case 'o':
                pop(queue);
                break;

            case 's':
                printf("\n Queue size is  :  [%d]\n\n", size(queue));
                break;

            case 'e':
                if (empty(queue))
                    printf("\n ť�� ����ֽ��ϴ�.\n\n");
                else
                    printf("\n ť�� �����Ͱ� �ֽ��ϴ�.\n\n");
                break;

            case 'f':
                front(queue);
                break;

            case 'r':
                rear(queue);
                break;
                
            case 'q':
                freeQueue(queue);
                break;
        }
    } while(command != 'q');
}


void printMenu(char *command)
{  
	printf("\n----------------------------------------------------------------\n");
	printf("                         Queue                         \n");
	printf("----------------------------------------------------------------\n");
	printf(" Initialize    = z           Print Queue   = u \n");
	printf(" Push          = p           Pop           = o \n");
	printf(" Size          = s           Empty         = e \n");
    printf(" Front         = f           Rear          = r \n");
    printf(" Quit          = q                             \n");
	printf("----------------------------------------------------------------\n");

	printf("Command = ");
	scanf(" %c", command);

    printf("\n");
}

void initialize(Queue** queue)
{
    if ((*queue) != NULL)
        freeQueue(*queue);


    (*queue) = (Queue*)malloc(sizeof(Queue));

    (*queue)->front = NULL;
    (*queue)->rear = NULL;
    (*queue)->size = 0;
}

void printQueue(Queue* queue)
{
    Node* searchNode = queue->front;

    printf("Print Queue : \n");
    while(searchNode != NULL)
    {
        printf(" [%d] -> ", searchNode->data);
        searchNode = searchNode->next;
    }
    printf("\n------------\n");
}

void push(Queue* queue, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;


    if (queue->rear == NULL)
    {
        queue->front = newNode;   
        queue->rear = newNode;
    }
    
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    queue->size++;
}

void pop(Queue* queue)
{
    if (empty(queue) == 1)
        return;


    Node* popNode = queue->front;

    if (size(queue) == 1)
    {
        queue->rear = NULL;
        queue->front = NULL;
    }

    else
        queue->front = queue->front->next;

    queue->size--;
    free(popNode);
}

int size(Queue* queue)
{
    return queue->size;
}

int empty(Queue* queue)
{
    if (queue->size)
        return 0;

    else
        return 1;
}

int front(Queue* queue)
{
    if (empty(queue) == 1)
        return -1;

    printf("\n Queue front is  :  [%d]\n\n", queue->front->data);
    return queue->front->data;
}

int rear(Queue* queue)
{
    if (empty(queue) == 1)
        return -1;

    printf("\n Queue rear is  :  [%d]\n\n", queue->rear->data);
    return queue->rear->data;
}

void freeQueue(Queue* queue)
{
    Node* freeNode = NULL;
    Node* nextNode = queue->front;

    printf("\n queue delete Node\n");
    while(nextNode != NULL)
    {
        freeNode = nextNode;
        nextNode = nextNode->next;

        printf("  [%d] \n", freeNode->data);
        free(freeNode);
    }
    free(queue);
}