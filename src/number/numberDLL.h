typedef struct DllNode{
    int data;
    struct DllNode* next;
    struct DllNode* prev;
}DllNode;

typedef struct Number{
    int length;
    DllNode* head;
    DllNode* decimal;
    DllNode* tail;
}Number;

void initDllNode(DllNode* m, int data);

void initNumber(Number* n);

int findLength(DllNode* n1, DllNode* n2);

void append(Number* n, int data);

void insertAtBeginning(Number* n, int data);

int removeFromBeginning(Number* n);

void freeNumber(Number* n);

int isFirstGreater(Number n1, Number n2);

void displayNumber(Number n);