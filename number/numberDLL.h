typedef struct DllNode{
    int data;
    struct DllNode* next;
    struct DllNode* prev;
}DllNode;

typedef struct Number{
    int length;
    DllNode* head;
    DllNode* tail;
}Number;

void initDllNode(DllNode* m, int data);

void initNumber(Number* n);

void append(Number* n, int data);

void insertAtBeginning(Number* n, int data);

void removeFromBeginning(Number* n);

void freeNumber(Number* n);

Number add(Number n1, Number n2);

Number subtract(Number n1, Number n2);

void displayNumber(Number n);