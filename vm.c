#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


// instruction set
typedef enum {
    INST_PUSH,
    INST_POP,
    INST_ADD,
    INST_PRINT
} Inst_Set;


// Instruction
typedef struct {
    Inst_Set type;
    int value;
} Inst;


// program
Inst program[] = {
    {.type = INST_PUSH, .value = 15 },
    {.type = INST_PRINT},
};
// macro, will expand to the value whenever used
#define PROGRAM_SIZE (sizeof(program)/sizeof(program[0]))


// stack
#define MAX_STACK_SIZE 1024
int stack[MAX_STACK_SIZE];
int stack_size;

void push(int value){
    stack[stack_size] = value;
    stack_size++;
}

int pop(){
    return stack[--stack_size];
}

int main(){
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
                
                break;
            case INST_PRINT:
                printf("%d\n", pop());
                break;
            
            default:
                break;
        }
    }

    return 0;
}