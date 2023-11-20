#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


// instruction set
typedef enum {
    INST_PUSH,
    INST_POP,
    INST_ADD,
    INST_SUB,
    INST_MUL,
    INST_DIV,
    INST_PRINT
} Inst_Set;


// Instruction
typedef struct {
    Inst_Set type;
    int value;
} Inst;

// macros for instructions
#define DEF_INST_PUSH(x) {.type = INST_PUSH, .value = x}
#define DEF_INST_POP() {.type = INST_POP }
#define DEF_INST_ADD() {.type = INST_ADD }
#define DEF_INST_SUB() {.type = INST_SUB }
#define DEF_INST_MUL() {.type = INST_MUL }
#define DEF_INST_DIV() {.type = INST_DIV }

// program
Inst program[] = {
    DEF_INST_PUSH(5),
    DEF_INST_PUSH(4),
    DEF_INST_PUSH(3),
    DEF_INST_PUSH(2),
    // DEF_INST_ADD(),
    {.type = INST_PRINT},
};
// macro, will expand to the value whenever used
#define PROGRAM_SIZE (sizeof(program)/sizeof(program[0]))


// stack
#define MAX_STACK_SIZE 1024
int stack[MAX_STACK_SIZE];
int stack_size;

void push(int value){
    if(stack_size >= MAX_STACK_SIZE){
        fprintf(stderr, "ERROR: Stack Overflow\n");
    }
    stack[stack_size] = value;
    stack_size++;
}

int pop(){
    if(stack_size <= 0){
        fprintf(stderr, "ERROR: Stack Underflow\n");
        exit(1);
    }
    return stack[--stack_size];
}

void print_stack(){
    for(int i = stack_size - 1; i >= 0; i--){
        printf("%d\n", stack[i]);
    }
}

int main(){
    int a, b;

    for(size_t ip = 0; ip < PROGRAM_SIZE; ip++){
        switch (program[ip].type)
        {
            case INST_PUSH:
                push(program[ip].value);
                break;
            case INST_POP:
                pop();
                break;
            case INST_ADD:
                a = pop();
                b = pop();
                push(a + b);
                break;
            case INST_SUB:
                a = pop();
                b = pop();
                push(b - a);
                break;
            case INST_MUL:
                a = pop();
                b = pop();
                push(a * b);
                break;
            case INST_DIV:
                a = pop();
                b = pop();
                push(a / b);
                break;
            case INST_PRINT:
                printf("%d\n", pop());
                break;
            
            default:
                break;
        }
    }
    print_stack();

    return 0;
}