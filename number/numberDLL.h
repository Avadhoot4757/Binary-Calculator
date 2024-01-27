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

void removeFromBeginning(Number* n);

void freeNumber(Number* n);

Number add(Number n1, Number n2);

void addIntegers(Number *answer, DllNode **t1, DllNode **t2, int *carry, DllNode* d);

void addDecimalTrailingDigits(Number *answer, DllNode **t, int *carry);

void addTrailingDigits(Number *answer, DllNode **t, int *carry, int count);

void subtractIntegers(Number* answer, DllNode** t1, DllNode** t2, DllNode* d);

void paddingZeroes(Number* n, int count);

Number subtract(Number n1, Number n2);

Number singleMultiply(Number n, int num, int stuffingZero);

Number multiply(Number n1, Number n2);

void displayNumber(Number n);