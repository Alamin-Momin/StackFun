//stack_ll.c
// Created by Alamin Momin on 2/21/20.
//The purpose of this file is to write the declarations of all the functions fund in the stack_ll.h file

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack_ll.h"

void makeStack(Stack312 *s){
    s->top = NULL;
}

bool isFull(Stack312 s){
    return false;
}

bool isEmpty(Stack312 s){
    return s.top==NULL;
}

void push(StackEntry e,Stack312 *s){
    StackNode *temp = (StackNode *) malloc(sizeof(StackNode));
    if(temp == NULL) {
        printf("Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    temp -> pixel = e;
    temp -> next = s->top;
    s->top = temp;

}

StackEntry pop(Stack312 *s){
    StackNode *temp = s->top;
    StackEntry poppedPixel = {temp->pixel.row,temp->pixel.col,temp->pixel.color};
    s->top = temp -> next;
    free(temp);
    return poppedPixel;
}

void showWorld(char *grid[], int numRows, int numCols){       //print the grid
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            printf("%c",grid[i][j]);
        }
        printf("\n");
    }
}

void promptUser(int row, int col, char color){               //prompt the user to enter coordinates and color, prints back what user inputted, without checking for errors
    printf("Enter a row: ");
    scanf("%d", &row);
    printf("Enter a column: ");
    scanf("%d", &col);
    printf("Enter a color: ");
    scanf(" %c", &color);
    printf("\n");
}

int validCheck(int row, int numRows, int col, int numCols, char color){        //checks of what the user inputs are valid per program requirement
    if (row == -1){                                                            //a -1 for row or column takes priority over all other conditions so check for those first
        return 1;
    }
    if (col == -1) {
        return 1;
    }
    if (row >= numRows || row <-1 ){                                                       //return a 0 for an invalid input for the three elements requested
        printf("Invalid row!\n");
        return 0;
    }
    if (col>=numCols || col<-1){
        printf("Invalid column!\n");
        return 0;
    }
    if (!(((color -'A'>=0) && (color - 'A' <=25)) || ((color -'a'>=0) && (color - 'a' <=25)))) {
        printf("Invalid color!\n");
        return 0;
    }
    return 1;
}

int updateGrid(int row, int col, char *grid[], char color, Stack312 *s, int numCols, int numRows){
    char desiredColor = grid[row][col];                                     //create a variable that keeps track of the color at the pixel prior to change
    if (desiredColor == color){
        return 0;
    }

    StackEntry enteredPixel = {row, col, color};                            //create a Pixel struct for the user inputs

    push(enteredPixel, s);                                                  //push this struct onto the stack

    while (!isEmpty(*s)){                                                   //if there are pixels on the stack, then pop and check neighbors to see if they need to be pushed
        StackEntry popped = pop(s);                                         //pop last element off the stack
        grid[popped.row][popped.col] = popped.color;                        //update the element of the popped pixel
        char currentColor;

        if((popped.row-1)>=0 && (popped.col-1)>=0) {                                                //check if top left neighbor is valid and same color as original color of entered pixel
            currentColor = grid[popped.row-1][popped.col-1];
            if (currentColor == desiredColor) {
                StackEntry newPixel = {(popped.row-1), (popped.col-1), (color)};         //create new struct with neighbor location and new color
                push(newPixel, s);                                                                  //push onto stack
            }
        }

        if((popped.row-1)>=0) {                                                                     //top middle
            currentColor = grid[popped.row-1][popped.col];
            if (currentColor == desiredColor) {
                StackEntry newPixel = {(popped.row-1), (popped.col), (color)};
                push(newPixel, s);
            }
        }

        if((popped.row-1)>=0 && (popped.col+1)<numCols) {                                            //top right
            currentColor = grid[popped.row-1][popped.col+1];
            if (currentColor == desiredColor) {
                StackEntry newPixel = {(popped.row-1), (popped.col+1), (color)};
                push(newPixel, s);
            }
        }

        if((popped.col-1)>=0) {                                                                      //middle left
            currentColor = grid[popped.row][popped.col-1];
            if (currentColor == desiredColor) {
                StackEntry newPixel = {(popped.row), (popped.col-1), (color)};
                push(newPixel, s);
            }
        }

        if((popped.col+1)<numCols) {                                                                //middle right
            currentColor = grid[popped.row][popped.col+1];
            if (currentColor == desiredColor) {
                StackEntry newPixel = {(popped.row), (popped.col+1), (color)};
                push(newPixel, s);
            }
        }

        if((popped.row+1)< numRows && (popped.col-1)>=0) {                                           //bottom left
            currentColor = grid[popped.row+1][popped.col-1];
            if (currentColor == desiredColor) {
                StackEntry newPixel = {(popped.row+1), (popped.col-1), (color)};
                push(newPixel, s);
            }
        }

        if((popped.row+1)<numRows) {                                                                //bottom middle
            currentColor = grid[popped.row+1][popped.col];
            if (currentColor == desiredColor) {
                StackEntry newPixel = {(popped.row+1), (popped.col), (color)};
                push(newPixel, s);
            }
        }

        if((popped.row+1)<numRows && (popped.col+1)<numCols) {                                           //bottom right
            currentColor = grid[popped.row+1][popped.col+1];
            if (currentColor == desiredColor) {
                StackEntry newPixel = {(popped.row+1), (popped.col+1), color};
                push(newPixel, s);
            }
        }

    }
    return 0;
}
