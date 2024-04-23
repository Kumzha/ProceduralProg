
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define Attacked 1
#define Free 0
#define End 2
#define True 1
#define Karaliene 4

#define Karaliene1 9
#define Karaliene2 8
#define Karaliene3 7
#define Karaliene4 6
#define Karaliene5 5


// Pagalbine funkcija I console printina board
void printBoard(int size, int **board)
{
    printf("\n");
     for(int i = 0; i<size; i++){
          for(int j = 0; j<size; j++){
            printf("%d ", board[i][j] );
          }  
          printf("\n");
    }
    printf("\n");
}
//Ar langelis atakuotas
int checkAttack(int row, int collum, int size, int **board)
{
    //Ar tame langelyje yra karaliene
    if(board[row][collum] != Free)
    {
        // printf("%d %d - Attacked 1 \n", row, collum);
        return Attacked;
    }

    //Ar eilute/stulpelis atakuotas
    for(int i = 0; i < size; i++)
    {
        if(board[row][i] != Free ||board[i][collum] != Free)
        {   
            // printf("%d %d - Attacked 2 \n", row, collum);
            return Attacked;
        } 
    }

    // South/East ir North/West istrizanes
    int rowc, collumr;
    if(row-collum<0){rowc=0;}else{rowc=row-collum;}
    if(collum-row<0){collumr=0;}else{collumr=collum-row;}

    for(int i = 0; i < size; i++){
        if((rowc+i)==size||(collumr+i)==size){break;}
        if(board[rowc+i][collumr+i] != Free)
        {
            // printf("%d %d - Attacked 3 \n", row, collum);
            return Attacked;
        };
    }

    // South/West  North/East
    for(int i = 0; i < size; i++){
        if((row+i)==size||(collum-i)<0){break;}

        if(board[row+i][collum-i] != Free )
        {
            // printf("%d %d - Attacked 4 \n", row, collum);
            return Attacked;
        };
    }

    for(int i = 0; i < size; i++){
        if((row-i)<0||(collum+i)==size){break;}

        if(board[row-i][collum+i] != Free )
        {
            // printf("%d %d - Attacked 5 \n", row, collum);
            return Attacked;
        };
    }

    return Free;

}
//Ar lenta uzatakuota
int checkEverySquare(int size, int **board)
{
    for(int i = 0; i<size; i++)
    {
        for(int j = 0; j<size; j++){
            if(checkAttack(i, j, size, board) == Free)
            {
                return Free;
            }
        }  
    }

    return Attacked;
}
// Skaiciu sekos konvertavimas i matrica(Sahmatu lenta)
void combinationToBoard(int *combination, int combSize, int size, int **board) {

    for(int i = 0; i < size; i++)
    {
    for(int j = 0; j < size; j++)
        {
            board[i][j] = Free;
        }
    }

  int index = 0;

    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            board[i][j] = combination[index++];
            if (index >= combSize) {return;}
        } 
    } 

}
// Pasitikrinimui printinimas skaiciu sekos i konsole
void printCombination(int *combination, int combSize) {
    printf("\n");
        for (int i = 0; i < combSize; i++) {
            printf("%d", combination[i]);
        }
    printf("\n");
}
//Kombinacijos printinimas i Faila
void fprintCombination(int *combination, int combSize, FILE *f)
{
    fprintf(f, "\n");
    for (int i = 0; i < combSize; i++) {
        fprintf(f, "%d", combination[i]);
    }
    fprintf(f, "\n");
}
//Matricos printinmas i Faila
void fprintBoard(int size, int **board, FILE *f) {

if(size==6){
    fprintf(f, "\n");
    fprintf(f,"y/\\------------------------------\n");
  for(int i = 0; i<size; i++){
    fprintf(f, "%d| ", size-i);
    for(int j = 0; j<size; j++){
        if(board[i][j]==Karaliene1){fprintf(f, " Q1 |");}
        if(board[i][j]==Karaliene2){fprintf(f, " Q2 |");}
        if(board[i][j]==Karaliene3){fprintf(f, " Q3 |");}
        if(board[i][j]==Karaliene4){fprintf(f, " Q4 |");}
        if(board[i][j]==Karaliene5){fprintf(f, " Q5 |");}
        if(board[i][j]==0){fprintf(f, "    |");}
      }
      fprintf(f, "\n");
      if(i<size-1){fprintf(f," |-------------------------------\n");}
      if(i==size-1){fprintf(f,"  ------------------------------->x\n");}
  }
  fprintf(f,"    1    2    3    4    5    6  \n");
  fprintf(f, "\n");
}
if(size==7){
    fprintf(f, "\n");
    fprintf(f,"y/\\-----------------------------------\n");
  for(int i = 0; i<size; i++){
    fprintf(f, "%d| ", size-i);
    for(int j = 0; j<size; j++){
        if(board[i][j]==Karaliene1){fprintf(f, " Q1 |");}
        if(board[i][j]==Karaliene2){fprintf(f, " Q2 |");}
        if(board[i][j]==Karaliene3){fprintf(f, " Q3 |");}
        if(board[i][j]==Karaliene4){fprintf(f, " Q4 |");}
        if(board[i][j]==Karaliene5){fprintf(f, " Q5 |");}
        if(board[i][j]==0){fprintf(f, "    |");}
      }
      fprintf(f, "\n");
      if(i<size-1){fprintf(f," |------------------------------------\n");}
      if(i==size-1){fprintf(f,"  ------------------------------------>x\n");}
  }
  fprintf(f,"    1    2    3    4    5    6     7  \n");
  fprintf(f, "\n");
}
if(size==8){
    fprintf(f, "\n");
    fprintf(f,"y/\\----------------------------------------\n");
  for(int i = 0; i<size; i++){
    fprintf(f, "%d| ", size-i);
    for(int j = 0; j<size; j++){
        if(board[i][j]==Karaliene1){fprintf(f, " Q1 |");}
        if(board[i][j]==Karaliene2){fprintf(f, " Q2 |");}
        if(board[i][j]==Karaliene3){fprintf(f, " Q3 |");}
        if(board[i][j]==Karaliene4){fprintf(f, " Q4 |");}
        if(board[i][j]==Karaliene5){fprintf(f, " Q5 |");}
        if(board[i][j]==0){fprintf(f, "    |");}
      }
      fprintf(f, "\n");
      if(i<size-1){fprintf(f," |-----------------------------------------\n");}
      if(i==size-1){fprintf(f,"  ----------------------------------------->x\n");}
  }
  fprintf(f,"    1    2    3    4    5    6     7    8  \n");
  fprintf(f, "\n");
}
}

int checkSuccess(int *combination, int combSize, int size, int **board, FILE *f, int count, int *Success) {
    combinationToBoard(combination, combSize, size, board);
    // fprintf(f, "\nKombinacija Nr. %d", count);
    //Isimta is ifo fprintBoard:)
    if(checkEverySquare(size, board) == Attacked){*Success=*Success+1; fprintf(f, " Sekme nr. %d", *Success); return Attacked;}
    // fprintBoard(size, board, f);
    return Free;
}

int* createCombination(int combSize){
    int *combination = (int*)malloc((combSize+1)*sizeof(int));   
    for(int i = 0; i<combSize; i++){combination[i]=0;} 
    combination[combSize] = 2;
    return combination;
}

int calculateX(int number, int size){
    return number % size;
}
int calculateY(int value, int size) {
    
    int x = value/size;
    return (size-x); 

}


void fprintCount(int count, FILE *f) {
    int countDiggits = floor(log10(abs(count))) + 1;
    fprintf(f, "\n");
    for(int i = 0; i<8-countDiggits; i++)
    {
    fprintf(f, " ");
    }
    fprintf(f, "%d) ", count);
}

//Funkcija atrasti visas galimas karalieniu kombinacijas ant sahmatu lentos
void findCombinations(int *combination, int combSize, int numOfQueens, int size, int **board, FILE *f)
{
    int count = 0;
    int Success = 0;
    int first = 0;
    int firstCount;
    int lastCount;

    int *combinationFirst = createCombination(combSize);
    int *combinationLast = createCombination(combSize);

    combination[0]=Karaliene5;
    combination[1]=Karaliene4;
    combination[2]=Karaliene3;
    combination[3]=Karaliene2;
    combination[4]=Karaliene1;
    
    fprintf(f, "\nStatomos valdovės pradinė pozicija:\n");
    combinationToBoard(combination, combSize, size, board);
    fprintBoard(size, board, f);

    count++;
    fprintCount(count, f);
    fprintf(f, "Pradine pozicija.");
    if(checkSuccess(combination, combSize, size, board, f, count, &Success)==Attacked)
    {
    for(int j = 0; j < combSize; j++) {
    if(first==0){
    firstCount = count;
    combinationFirst[j]=combination[j];
    }
    combinationLast[j]=combination[j];
    lastCount = count;
    }
    first = 1;
    } 


//!
//--------------------------------------------------------------------------------------------------------------
//Ciklas einantis pro eiles, dydzio = boardSize^2, visas imanomas kombinacijas ir perstatineja 5 objektus(karalienes)
//P(n,r)=(n!)/((n-r)!) P = kombinaciju skaicius, n = kombinacijos ilgis, r = objektu skaicius kuriuos perstatome
//
//Nesu tikras ar imanoma padaryti algoritma tokiom sitaucijomis nenaudojant Nestinimo, ChatGPT pasiule panaudoti
//nested for's, bet problema islieka ta pati.
//--------------------------------------------------------------------------------------------------------------
//!

while(1){
 for(int i = 0; i < combSize; i++) 
 {  
    if(combination[i]==Karaliene5)
    {
       if (combination[i+1]==Karaliene4)
       {   
            if(combination[i+2]==Karaliene3)
            {
                if(combination[i+3]==Karaliene2)
                {
                    if(combination[i+4]==Karaliene1)
                    {
                        if(combination[i+5]==2)
                        {  
                            // Pasiektas galas
                            break;
                        }
                        // if(combination[i+4]==Karaliene1)
                        combination[i+5]=Karaliene1;
                        combination[i+4]=0;
                        combination[i+3]=0;
                        combination[i+2]=0;
                        combination[i+1]=0;
                        combination[i]=0;

                        combination[0]=Karaliene5;
                        combination[1]=Karaliene4;
                        combination[2]=Karaliene3;
                        combination[3]=Karaliene2;

                        // 36/i

                        count++;
                        fprintCount(count, f);
                        fprintf(f, "Valdove1(Q1) statoma i x:%d y:%d pozicija.     Q2(x=4, y=%d), Q3(x=3, y=%d), Q4(x=2, y=%d) ir Q5(x=1, y=%d).", (calculateX((i+5), size)+1), (calculateY((i+5), size)), size, size, size, size);
                        if(checkSuccess(combination, combSize, size, board, f, count, &Success)==Attacked)
                        {
                        for(int j = 0; j < combSize; j++) {
                        if(first==0){
                            firstCount = count;
                            combinationFirst[j]=combination[j];
                        }
                            combinationLast[j]=combination[j];
                            lastCount = count;
                        }
                            first = 1;
                        }
                        continue;
                    
                    }
                    // if(combination[i+3]==Karaliene2)
                    combination[i+4]=Karaliene2;
                    combination[i+3]=0;
                    combination[i+2]=0;
                    combination[i+1]=0;
                    combination[i]=0;
                    combination[0]=Karaliene5;
                    combination[1]=Karaliene4;
                    combination[2]=Karaliene3;

                    count++;
                    fprintCount(count, f);
                    fprintf(f, "-Valdove2(Q2) statoma i x:%d y:%d pozicija.    Q3(x=3, y=%d),Q4(x=2, y=%d) ir Q5(x=1, y=%d).", (calculateX((i+4), size)+1), (calculateY((i+4), size)), size, size, size);
                    if(checkSuccess(combination, combSize, size, board, f, count, &Success)==Attacked)
                    {
                    for(int j = 0; j < combSize; j++) {
                    if(first==0){
                        firstCount = count;
                        combinationFirst[j]=combination[j];
                    }
                        combinationLast[j]=combination[j];
                        lastCount = count;
                    }
                        first = 1;
                    }
                    continue;
                }
                // if(combination[i+2]==Karaliene3)
                combination[i+3]=Karaliene3;
                combination[i+2]=0;
                combination[i+1]=0;
                combination[i]=0;
                combination[0]=Karaliene5;
                combination[1]=Karaliene4;

                count++;
                fprintCount(count, f);
                fprintf(f, "--Valdove3(Q3) statoma i x:%d y:%d pozicija.   Q4(x=2, y=%d) ir Q5(x=1, y=%d).", (calculateX((i+3), size)+1), (calculateY((i+3), size)), size, size);
                if(checkSuccess(combination, combSize, size, board, f, count, &Success)==Attacked)
                {
                for(int j = 0; j < combSize; j++) {
                if(first==0){
                    firstCount = count;
                    combinationFirst[j]=combination[j];
                }
                    combinationLast[j]=combination[j];
                    lastCount = count;
                }
                    first = 1;
                }
                continue;

            } 
            // if(combination[i+1]==Karaliene4)
            combination[i+2]=Karaliene4;
            combination[i+1]=0;
            combination[i]=0;
            combination[0]=Karaliene5;

            count++;
            fprintCount(count, f);
            fprintf(f, "---Valdove4(Q4) statoma i x:%d y:%d pozicija.  Q5(x=1, y=%d).", (calculateX((i+2), size)+1), (calculateY((i+2), size)), size);
            if(checkSuccess(combination, combSize, size, board, f, count, &Success)==Attacked)
            {
            for(int j = 0; j < combSize; j++) {
            if(first==0){
                firstCount = count;
                combinationFirst[j]=combination[j];
            }
                combinationLast[j]=combination[j];
                lastCount = count;
            }
                first = 1;
            }
            continue;
        }  
        // if(combination[i]==Karaliene5)
        combination[i+1]=Karaliene5;
        combination[i]=0;

        count++;
        fprintCount(count, f);
        fprintf(f, "----Valdove5(Q5) statoma i x:%d y:%d pozicija.", (calculateX((i+1), size)+1), (calculateY((i+1), size)));
        if(checkSuccess(combination, combSize, size, board, f, count, &Success)==Attacked)
        {
        for(int j = 0; j < combSize; j++) {
            if(first==0){
                firstCount = count;
                combinationFirst[j]=combination[j];
            }
                combinationLast[j]=combination[j];
                lastCount = count;
            }
            first = 1;
        }
        continue;
    }

    continue;

 }
 

    if(combination[combSize-1]==Karaliene1&&combination[combSize-2]==Karaliene2&&combination[combSize-3]==Karaliene3&&combination[combSize-4]==Karaliene4&&combination[combSize-5]==Karaliene5) 
    {

        printf("\n\tPasiekta pabaiga.)");
        printf("\n Kombinaciju, kuriose uzatakuoti visi langeliai: %d\n Kombinaciju skaicius: %d\n", Success, count);


        fprintf(f, "\n\n\n3 DALIS REZULTATAI");
        fprintf(f, "\n1) Kombinaciju skaicius: %d", count);
        fprintf(f, "\n2) Sekmingi atvejai: %d\n", Success);

        combinationToBoard(combinationFirst, combSize, size, board);
        fprintf(f, "\nPirmas sekmingas variantas, nr. %d:", firstCount);
        fprintBoard(size, board, f);

        combinationToBoard(combinationLast, combSize, size, board);
        fprintf(f, "\nPaskutinis sekmingas variantas, nr. %d:", lastCount);
        fprintBoard(size, board, f);

        free(combinationFirst);
        free(combinationLast);
        break;
    }
}
}