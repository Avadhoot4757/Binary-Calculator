#include "numberDLL.h"

Number add(Number n1, Number n2);

void addIntegers(Number *answer, DllNode **t1, DllNode **t2, int *carry, DllNode* d);

void addDecimalTrailingDigits(Number *answer, DllNode **t, int *carry);

void addTrailingDigits(Number *answer, DllNode **t, int *carry, int count);

void subtractIntegers(Number* answer, DllNode** t1, DllNode** t2, DllNode* d);

void paddingZeroes(Number* n, int count);

Number subtract(Number n1, Number n2);

Number singleMultiply(Number n, int num, int stuffingZero);

Number multiply(Number n1, Number n2);

void dividePrecise(Number n1, Number n2, Number* quotient, Number dividend, int precision);

Number divide(Number n1, Number n2);