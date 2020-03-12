//stack_ll_driver.c
// Created by Alamin Momin on 2/23/20.
//This is the driver file the Flood Fill program

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "stack_ll.h"
#define  MAX_ROWS 25                //we know the max size of the grid
char *grid[MAX_ROWS];

int main (int argc, char *argv[]){
    char *fName = argv[1];
    int numCols=0;                    //initialize globals that will be used throughout the program
    int numRows=0;
    int userRow;
    int userCol;
    char color;

    FILE *fptr;
    fptr = fopen(fName, "r");

                                                            //if-else statement is to open and store the text file from which the colored grid comes from
    if (fptr == NULL) {
        printf("you screwed up!\n");
        exit(-1);
    }
    else {
        char buf[BUFSIZ];
        while (fgets(buf,sizeof(buf),fptr)){
            numCols = strlen(buf);
            grid[numRows] = malloc((numCols*sizeof(char)));
            strcpy(grid[numRows],buf);
            (numRows)++;
        }
    }

    Stack312 *stack = (Stack312 *) malloc(sizeof(Stack312));                //create space for new stack
    makeStack(stack);                                                       //create the stack itself

    showWorld(grid, numRows, numCols);                                      //display the initial grid created
    printf("Enter a row: ");                                                //prompt the user to enter desired row, column, and color
    scanf("%d", &userRow);
    printf("Enter a column: ");
    scanf("%d", &userCol);
    printf("Enter a color: ");
    scanf(" %c", &color);
    printf("\n");

    while(!validCheck(userRow, numRows, userCol, numCols, color)){          //check validity of coordinates and print return statement for invalid inputs
        showWorld(grid, numRows, numCols);                                  //if conditions are invalid, print the grid again and ask user to type valid inputs
        printf("Enter a row: ");
        scanf("%d", &userRow);
        printf("Enter a column: ");
        scanf("%d", &userCol);
        printf("Enter a color: ");
        scanf(" %c", &color);
        printf("\n");
    }


    while (userRow != -1 && userCol != -1) {                                //until user inputs a -1 for either coordinate, continue running the program
        updateGrid(userRow, userCol, grid, color, stack, numCols, numRows); //change all the spots on the grid corresponding to the user inputs
        showWorld(grid, numRows, numCols);                                  //display the changes made
        printf("Enter a row: ");                                            //prompt user to enter new inputs
        scanf("%d", &userRow);
        printf("Enter a column: ");
        scanf("%d", &userCol);
        printf("Enter a color: ");
        scanf(" %c", &color);
        printf("\n");
        while (!validCheck(userRow, numRows, userCol, numCols, color)){     //prompt the user to input a new color, check if valid conditions
            showWorld(grid, numRows, numCols);
            printf("Enter a row: ");
            scanf("%d", &userRow);
            printf("Enter a column: ");
            scanf("%d", &userCol);
            printf("Enter a color: ");
            scanf(" %c", &color);
            printf("\n");
        }

    }

    for(int i =0; i<numRows; i++) {
        free(grid[i]);
    }

    free(stack);
    fclose(fptr);
    return 0;
}
