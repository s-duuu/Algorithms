#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK 100

typedef enum {false , true} bool;
typedef struct {
    char small;
    char large;
    // *Variable "operator"
    // used in ConvInfixToPostfix function
    char operator;
}Hexa_num;

typedef struct {
    Hexa_num items[MAX_STACK];
    int top;
}Stack;
/* Modify from here */
int GetPriority(char op);
bool ComPriority(char op1, char op2);
/* Modify to here */

Hexa_num add(Hexa_num b1,Hexa_num b2);
Hexa_num subtract(Hexa_num b1,Hexa_num b2);
Hexa_num multiply(Hexa_num b1,Hexa_num b2);
Hexa_num division(Hexa_num b1,Hexa_num b2);

void InitStack (Stack *pstack);
bool IsFull(Stack *pstack);
bool IsEmpty(Stack *pstack);
Hexa_num Peek(Stack *pstack);
void Push(Stack *pstack,Hexa_num item);
void Pop(Stack *pstack);
void ConvInfixToPostfix(char* exp,char* convExp, int len);
Hexa_num EvalPostfix(char* exp,int len);
void print_Hexa_num(Hexa_num result);
int main() {
    char infix_exp[100];
    char postfix_exp[100];
    Hexa_num result;

    scanf("%s",infix_exp);

    ConvInfixToPostfix(infix_exp,postfix_exp,strlen(infix_exp));
    printf("%s\n",postfix_exp);
    result = EvalPostfix(postfix_exp,strlen(postfix_exp));
    print_Hexa_num(result);
    return 0;
}
/* Modify from here */
void InitStack (Stack *pstack)
{
    pstack->top = -1;
}

bool IsFull(Stack *pstack)
{
    return pstack->top == MAX_STACK - 1;
}

bool IsEmpty(Stack *pstack)
{
    return pstack->top == -1;
}

Hexa_num Peek(Stack *pstack)
{
    if (IsEmpty(pstack))
        exit(1);
    return pstack->items[pstack->top];
}

void Push(Stack *pstack, Hexa_num item)
{
    if (IsFull(pstack))
        exit(1);
    pstack->items[++(pstack->top)] = item;
}

void Pop(Stack *pstack)
{
    if (IsEmpty(pstack))
        exit(1);
    --(pstack->top);
}

int GetPriority(char op)
{
    if (op == '*' || op == '/'){
        return 2;
    }
    else if (op == '+' || op == '-'){
        return 1;
    }
    else {
        return 0;
    }
}

bool ComPriority(char op1, char op2)
{
    int op1_pr = GetPriority(op1);
    int op2_pr = GetPriority(op2);
    if (op1_pr >= op2_pr){
        return true;
    }
    else {
        return false;
    }
}

Hexa_num add (Hexa_num b1, Hexa_num b2)
{
    int sum = 0;
    int decimal_add[2];
    Hexa_num addition;
    if ((b1.large) >= 48 && (b1.large) <= 57){
        sum += ((b1.large)-48)*16;
    }
    else {
        sum += ((b1.large)-55)*16;
    }
    if ((b1.small) >= 48 && (b1.small) <= 57){
        sum += ((b1.small)-48);
    }
    else {
        sum += ((b1.small)-55);
    }
    if ((b2.large) >= 48 && (b2.large) <= 57){
        sum += ((b2.large)-48)*16;
    }
    else {
        sum += ((b2.large)-55)*16;
    }
    if ((b2.small) >= 48 && (b2.small) <= 57){
        sum += ((b2.small)-48);
    }
    else {
        sum += ((b2.small)-55);
    }
    decimal_add[0] = (sum) / 16;
    decimal_add[1] = (sum) % 16;

    if (decimal_add[0] > 9){
        (addition.large) = decimal_add[0] + 55;
    }
    else {
        (addition.large) = decimal_add[0] + 48;
    }
    if (decimal_add[1] > 9){
        (addition.small) = decimal_add[1] + 55;
    }
    else {
        (addition.small) = decimal_add[1] + 48;
    }
    return addition;
}

Hexa_num subtract(Hexa_num b1, Hexa_num b2)
{
    int sum = 0;
    int decimal_subtract[2];
    Hexa_num subtraction;
    if ((b1.large) >= 48 && (b1.large) <= 57){
        sum += ((b1.large)-48)*16;
    }
    else {
        sum += ((b1.large)-55)*16;
    }
    if ((b1.small) >= 48 && (b1.small) <= 57){
        sum += ((b1.small)-48);
    }
    else {
        sum += ((b1.small)-55);
    }
    if ((b2.large) >= 48 && (b2.large) <= 57){
        sum -= ((b2.large)-48)*16;
    }
    else {
        sum -= ((b2.large)-55)*16;
    }
    if ((b2.small) >= 48 && (b2.small) <= 57){
        sum -= ((b2.small)-48);
    }
    else {
        sum -= ((b2.small)-55);
    }
    decimal_subtract[0] = (sum) / 16;
    decimal_subtract[1] = (sum) % 16;

    if (decimal_subtract[0] > 9){
        (subtraction.large) = decimal_subtract[0] + 55;
    }
    else {
        (subtraction.large) = decimal_subtract[0] + 48;
    }
    if (decimal_subtract[1] > 9){
        (subtraction.small) = decimal_subtract[1] + 55;
    }
    else {
        (subtraction.small) = decimal_subtract[1] + 48;
    }
    return subtraction;
}

Hexa_num multiply(Hexa_num b1, Hexa_num b2)
{
    int decimal1 = 0;
    int decimal2 = 0;
    int decimal_multiply[3];
    Hexa_num multiplication;
    if ((b1.large) >= 48 && (b1.large) <= 57){
        decimal1 += ((b1.large)-48)*16;
    }
    else {
        decimal1 += ((b1.large)-55)*16;
    }
    if ((b1.small) >= 48 && (b1.small) <= 57){
        decimal1 += (b1.small)-48;
    }
    else {
        decimal1 += (b1.small)-55;
    }
    if ((b2.large) >= 48 && (b2.large) <= 57){
        decimal2 += ((b2.large)-48)*16;
    }
    else {
        decimal2 += ((b2.large)-55)*16;
    }
    if ((b2.small) >= 48 && (b2.small) <= 57){
        decimal2 += (b2.small)-48;
    }
    else {
        decimal2 += (b2.small)-55;
    }


    decimal_multiply[0] = (decimal1 * decimal2) / 16;
    decimal_multiply[1] = (decimal1 * decimal2) % 16;

    if (decimal_multiply[0] > 9){
        (multiplication.large) = decimal_multiply[0] + 55;
    }
    else {
        (multiplication.large) = decimal_multiply[0] + 48;
    }
    if (decimal_multiply[1] > 9){
        (multiplication.small) = decimal_multiply[1] + 55;
    }
    else {
        (multiplication.small) = decimal_multiply[1] + 48;
    }

    return multiplication;
}

Hexa_num division(Hexa_num b1, Hexa_num b2)
{
    int decimal1 = 0;
    int decimal2 = 0;
    int decimal_division[2];
    Hexa_num divide;
    if ((b1.large) >= 48 && (b1.large) <= 57){
        decimal1 += ((b1.large)-48)*16;
    }
    else {
        decimal1 += ((b1.large)-55)*16;
    }
    if ((b1.small) >= 48 && (b1.small) <= 57){
        decimal1 += ((b1.small)-48);
    }
    else {
        decimal1 += ((b1.small)-55);
    }
    if ((b2.large) >= 48 && (b2.large) <= 57){
        decimal2 += ((b2.large)-48)*16;
    }
    else {
        decimal2 += ((b2.large)-55)*16;
    }
    if ((b2.small) >= 48 && (b2.small) <= 57){
        decimal2 += ((b2.small)-48);
    }
    else {
        decimal2 += ((b2.small)-55);
    }
    decimal_division[0] = (decimal1 / decimal2) / 16;
    decimal_division[1] = (decimal1 / decimal2) % 16;

    if (decimal_division[0] > 9){
        (divide.large) = decimal_division[0] + 55;
    }
    else {
        (divide.large) = decimal_division[0] + 48;
    }
    if (decimal_division[1] > 9){
        (divide.small) = decimal_division[1] + 55;
    }
    else {
        (divide.small) = decimal_division[1] + 48;
    }
    return divide;
}

void ConvInfixToPostfix(char* exp, char* convExp, int len)
{
    Stack stack;
    Hexa_num item;
    int idx = 0;
    InitStack(&stack);
    for (int i = 0; i < len; i++){
        if (exp[i] != '+' && exp[i] != '-' && exp[i] != '*' && exp[i] != '/'){
            convExp[idx++] = exp[i];
        }
        else {
            while (!IsEmpty(&stack) && ComPriority((Peek(&stack)).operator, exp[i])){
                convExp[idx++] = (Peek(&stack)).operator;
                Pop(&stack);
            }
            item.operator = exp[i];
            Push(&stack, item);
        }
    }
    while (!IsEmpty(&stack)){
        convExp[idx++] = (Peek(&stack)).operator;
        Pop(&stack);
    }
}

Hexa_num EvalPostfix(char* exp, int len)
{
    Stack stack;
    Hexa_num item;
    Hexa_num result;
    Hexa_num op1, op2;
    InitStack(&stack);
    for (int i = 0; i < len; i++){
        if (exp[i] != '+' && exp[i] != '-' && exp[i] != '*' && exp[i] !='/'){
            item.large = exp[i];
            i++;
            item.small = exp[i];
            Push(&stack,item);
        }
        else {
            op2 = Peek(&stack); Pop(&stack);
            op1 = Peek(&stack); Pop(&stack);
            if (exp[i] == '+'){
                Push(&stack, add(op1, op2));
            }
            else if (exp[i] == '-'){
                Push(&stack, subtract(op1, op2));
            }
            else if (exp[i] == '*'){
                Push(&stack, multiply(op1, op2));
            }
            else if (exp[i] == '/'){
                Push(&stack, division(op1, op2));
            }
        }
    }
    return Peek(&stack);
}

void print_Hexa_num(Hexa_num result)
{
    printf("%c%c", result.large, result.small);
}
/* Modify to here */
