#include "maze.h";


void printBinaryMazeData(int** matrix, struct mazeMetaData* metaData){
    int *tmp;
    int* tmpArray;

     for(int i=0; i<metaData->rows;i++)
    {
        tmp=(matrix+i);
        tmpArray=*tmp;
       for(int j=0;j<metaData->columns;j++)
       {
           printf("%d",tmpArray[j]);
       }
        printf("\n");
    }
}

void getMetadataOfMaze(FILE* fileptr,struct mazeMetaData* structPointer){

    int counter1=0;
    int counter2=1;
    char character;
    struct mazeMetaData metaData;

    while(!feof(fileptr))
    {
            fscanf(fileptr, "%c", &character);
            if(character=='\n')
            {
                counter2++;
            }
            else
            {
               counter1++;
            }
    }
    structPointer->rows=counter2;
    structPointer->columns=counter1/counter2;
    rewind(fileptr);
}

void createMatrix(int*** matrix, struct mazeMetaData* metaData){
    int i;
    *matrix=(int*)malloc(sizeof(int*)*(metaData->rows));
    int* tmp;
    for(i=0; i<metaData->rows;i++)
    {
        tmp=((*matrix)+i);
        *tmp= malloc(sizeof(int)*(metaData->columns));
    }
}

void initializeMatrix(FILE* fileptr, int** matrix, struct mazeMetaData* metaData){

    int *tmp;
    int* tmpArray;
    char character;
    for(int i=0; i<metaData->rows;i++)
    {
        tmp=(matrix+i);
        tmpArray=*tmp;
       for(int j=0;j<metaData->columns;j++)
       {
            fscanf(fileptr,"%c",&character);
            if(character=='+'||character=='-'||character=='|')
            {
                tmpArray[j]=0;
            }
            else if(character==' ')
            {
                tmpArray[j]=1;
            }

       }
        fscanf(fileptr,"\n",&character);
    }
}
