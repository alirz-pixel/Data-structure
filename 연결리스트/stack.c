#include <stdio.h>
#include <stdlib.h>


typedef struct _Node{
    int data;
    struct _Node* next;
} Node;

typedef struct _Stack{
    struct _Node* top;
    int size;
} Stack;
     

void printMenu(char *command);
void initialize(Stack** st);
void push(Stack* st, int data);
int pop(Stack* st);
int top(Stack* st);
int size(Stack* st);
int empty(Stack* st);
void printStack(Stack* st);
void freeStack(Stack* st);

int main(void)
{
    Stack* st = NULL;
    int data, temp;
    char command;

    do {
        printMenu(&command);

        switch(command)
        {
            case 'z':
                initialize(&st);
                break;

            case 't':
                temp = top(st);
                if (temp != -1)
                    printf(" stack top = [%d]\n", temp);
                break;

            case 'p':
                printf(" 스택에 삽입할 데이터를 적어주세요. : ");
                scanf("%d", &data);
                push(st, data);
                break;

            case 'o':
                pop(st);
                break;

            case 's':
                temp = size(st);
                if (temp != -1)
                    printf(" Stack size = [%d] \n", size(st));
                break;

            case 'e':
                temp = empty(st);
                if (temp == 0)
                    printf(" stack is empty\n");
                else if (temp == 1)
                    printf(" stack is not empty\n");

                break;

            case 'r':
                printStack(st);
                break;

            case 'q':
                freeStack(st);
                break;
        }
    } while(command != 'q');

    return 0;
}

void printMenu(char *command)
{  
	printf("\n----------------------------------------------------------------\n");
	printf("                         Stack                         \n");
	printf("----------------------------------------------------------------\n");
	printf(" Initialize    = z           Top           = t \n");
	printf(" Push          = p           Pop           = o \n");
	printf(" Size          = s           Empty         = e \n");
    printf(" Print Stack   = r           Quit          = q \n");
	printf("----------------------------------------------------------------\n");

	printf("Command = ");
	scanf(" %c", command);

    printf("\n");
}

void initialize(Stack** st)
{
    if ((*st) != NULL)
        freeStack(*st);

    (*st) = (Stack*)malloc(sizeof(Stack));
    (*st)->top = NULL;
    (*st)->size = 0;
}

void push(Stack* st, int data)
{
    if (st == NULL)
    {
        printf("error! : initialize를 진행해주세요.\n\n");
        return;
    }


    Node* pushNode = (Node*)malloc(sizeof(Node));
    pushNode->data = data;

    pushNode->next = st->top;
    st->top = pushNode;
    st->size++;
}

int pop(Stack* st)
{
    if (st == NULL)
    {
        printf("error! : initialize를 진행해주세요.\n\n");
        return -1;
    }

    if (empty(st) == 0)
    {
        printf("error! : 스택이 비어있습니다.\n\n");
        return -1;
    }


    Node* popNode = st->top;
    int popData = popNode->data;

    st->size--;
    st->top = st->top->next;
    free(popNode);
    return popData;
}

int top(Stack* st)
{
    if (st == NULL)
    {
        printf("error! : initialize를 진행해주세요.\n\n");
        return -1;
    }

    if (empty(st) == 0)
    {
        printf("error! : 스택이 비어있습니다.\n\n");
        return -1;
    }

    return st->top->data;
}

int size(Stack* st)
{
    if (st == NULL)
    {
        printf("error! : initialize를 진행해주세요.\n\n");
        return -1;
    }


    return st->size;
}

int empty(Stack* st)
{
    if (st == NULL)
    {
        printf("error! : initialize를 진행해주세요.\n\n");
        return -1;
    }


    if (st->top == NULL)
        return 0;
    else
        return 1;
}

void printStack(Stack* st)
{
    if (st == NULL)
    {
        printf("error! : initialize를 진행해주세요.\n\n");
        return;
    }

    if (empty(st) == 0)
    {
        printf("error! : 스택이 비어있습니다.\n\n");
        return;
    }


    Node* searchNode = st->top;

    printf(" Stack \n");
    while (searchNode != NULL)
    {
        printf("  [%d]\n", searchNode->data);
        searchNode = searchNode->next;
    }
    printf("== size : [%d]", size(st));

    return;
}

void freeStack(Stack* st)
{
    if (st == NULL)
        return;


    Node* previous = NULL;
    Node* searchNode = st->top;
    while(searchNode != NULL)
    {
        previous = searchNode;
        searchNode = searchNode->next;

        printf(" [%d] 노드를 제거하였습니다.\n", previous->data);
        free(previous);
    }
    free(st);
}