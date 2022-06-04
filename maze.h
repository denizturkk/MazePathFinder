#ifndef maze_h_
#define maze_h_
#include <stdio.h>

typedef struct mazeMetaData
{
    int rows;
    int columns;
    int startPoint[2];
    int endPoint[2];

}mazeMetaData;

void printBinaryMazeData(int** matrix, struct mazeMetaData* metaData);
void createMatrix(int*** matrix, struct mazeMetaData*);
void getMetadataOfMaze(FILE *fptr ,struct mazeMetaData*);
void initializeMatrix(FILE *fileptr, int** matrix, struct mazeMetaData* metaData);

#endif // maze_h_
