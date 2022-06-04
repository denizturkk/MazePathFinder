#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "maze.h"

int main()
{
    int sayac;
    mazeMetaData metaData;
    FILE *fileptr;
    int** matrix=NULL;

    fileptr =  fopen("maze.txt","r");

    if(fileptr==NULL){
        printf("file could not be opened!");

        exit(1);
    }

    getMetadataOfMaze(fileptr,&metaData);
    createMatrix(&matrix,&metaData);
    initializeMatrix(fileptr,matrix,&metaData);
    printBinaryMazeData(matrix,&metaData);

    return 0;
}
