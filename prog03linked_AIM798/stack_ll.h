//stack_ll.h
//Add documentation including Pre and Post conditions for functions

#include <stdio.h>
#include <stdbool.h>

typedef struct Pixel {
   int row;
   int col;
   char color;
} Pixel;

typedef Pixel StackEntry;

typedef struct StackNode {
   StackEntry pixel;
   struct StackNode *next;
} StackNode;
   
typedef struct Stack312 {
   struct StackNode *top;
} Stack312;

void makeStack(Stack312 *s);

bool isFull(Stack312 s);

bool isEmpty(Stack312 s);

void push(StackEntry e,Stack312 *s);

StackEntry pop(Stack312 *s);

void showWorld(char *grid[], int numRows, int numCols);

void promptUser(int row, int col, char color);

int validCheck(int row, int numRows, int col, int numCols, char color);

int updateGrid(int row, int col, char *grid[], char color, Stack312 *s, int numCols, int numRows);