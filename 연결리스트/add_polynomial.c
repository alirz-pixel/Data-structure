#include <stdio.h>
#include <stdlib.h>

typedef struct _PolyNode {
    int coef;
    int expon;
    struct _PolyNode* next;
} PolyNode;


// [사용자 정의 함수] :
void print_list(PolyNode* head);
PolyNode* create_node(int coef, int expon);
void push(PolyNode** head, PolyNode* new_node);
void input_poly(PolyNode** poly);
PolyNode* add_poly(PolyNode* a, PolyNode* b);
void free_list(PolyNode** head);

int main() {
    PolyNode *a = NULL, *b = NULL, *c = NULL;
    
    char command;
    int number;
    do {
        printf("\n=====[다항식의 덧셈]====\n");
        printf("i : input poly\n");
        printf("a : add\n");
        printf("p : print list\n");
        printf("============ input : ");
        scanf(" %c", &command);

        switch(command) {
        case 'i': case 'I':
            printf("\n입력할 다항식 종류를 선택해주세요.\n");
            printf("1. a                2. b\n");
            scanf(" %d", &number);

            if (number == 1) {
                input_poly(&a);
            }
            else if (number == 2) {
                input_poly(&b);
            }
            break;
        case 'a': case 'A':
            free_list(&c);
            c = add_poly(a, b);
            break;
        case 'p': case 'P':
            printf("\n출력할 다항식 종류를 선택해주세요. \n");
            printf("1. a        2. b        3. c\n");
            scanf("%d", &number);

            if (number == 1) {
                print_list(a);  
            }
            else if (number == 2) {
                print_list(b);
            }
            else if (number == 3) {
                print_list(c);
            }
            break;
        case 'q': case 'Q':
            free_list(&a);
            free_list(&b);
            free_list(&c);
            break;
        }

        printf("\n");
    } while(command != 'q' & command != 'Q');
    return 0;
}

void print_list(PolyNode* head) {
    if (head == NULL) {
        printf("해당 다항식이 비어있습니다.\n");
        return;
    }

    printf("-----[다항식 출력]-----\n");
    while (head) {
        printf("[%d, %d]  ->  ", head->coef, head->expon);
        head = head->next;
    }
    printf("\n-----------------------\n\n");
}

PolyNode* create_node(int coef, int expon) {
    PolyNode* new_node = (PolyNode*)malloc(sizeof(PolyNode));

    new_node->next = NULL;
    new_node->coef = coef;
    new_node->expon = expon;

    return new_node;
}

void push(PolyNode** head, PolyNode* new_node) {
    PolyNode* searchNode = (*head);
    PolyNode* preNode = NULL;

    while (searchNode) {
        if (searchNode->expon < new_node->expon) {
            break;
        }

        preNode = searchNode;
        searchNode = searchNode->next;
    }

    if (preNode == NULL) {
        new_node->next = (*head);
        (*head) = new_node;
    }
    else {
        preNode->next = new_node;
        new_node->next = searchNode;
    }
}

void input_poly(PolyNode** poly) {
    free_list(poly);

    int coef;
    int expon;

    printf("\n-----[다항식을 입력해주세요]-----\n");
    printf(" coef, expon 순으로 입력해주세요 (종료 : [expon = -1])\n");
    while (1) {
        scanf(" %d %d", &coef, &expon);

        if (expon == -1) {
            break;
        }

        push(poly, create_node(coef, expon));
    }
    printf("\n다항식 입력이 완료되었습니다.\n\n");

    print_list((*poly));
}

PolyNode* add_poly(PolyNode* a, PolyNode* b) {
    PolyNode* c = (PolyNode*)malloc(sizeof(PolyNode));
    PolyNode* tail = c;

    c->next = NULL;
    while (a && b) {
        if (a->expon == b->expon) {
            tail->next = create_node(a->coef + b->coef, a->expon);
            
            tail = tail->next;
            a = a->next;
            b = b->next; 
        }
        else if (a->expon < b->expon) {
            tail->next = create_node(b->coef, b->expon);

            tail = tail->next;
            b = b->next;
        }
        else {
            tail->next = create_node(a->coef, a->expon);

            tail = tail->next;
            a = a->next;
        }
    }

    if (a != NULL) {
        tail->next = a;
    }
    else if (b != NULL) {
        tail->next = b;
    }

    printf("더하기 연산이 완료되었습니다.\n");    
    print_list(c->next);

    return c->next;
}

void free_list(PolyNode** head) {
    if ((*head) == NULL) {
        return;
    }

    PolyNode* preNode = NULL;
    while ((*head)) {
        preNode = (*head); 
        (*head) = (*head)->next;

        free(preNode);
    }

    (*head) = NULL;
}
