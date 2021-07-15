#include <stdio.h>

typedef struct _listNode{
    int data;
    struct _listNode* next;
} listNode;


/*  사용자 정의 함수  */
void printMenu(char* command);


int main(void)
{
    char command;
    listNode* head = NULL;

    do {
        printMenu(&command);

        switch(command)
        {
            case 'z':
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


