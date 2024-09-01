#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char PLAYER = 'x';
const char COMPUTER = 'O';

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

int main(){
    char winner = ' ';
    resetBoard();
    //keep updating the playboard with the latest board data
    while(winner == ' ' && checkFreeSpaces() != 0){
        printBoard();
        playerMove();
        winner = checkWinner();
        if(winner != ' ' || checkFreeSpaces == 0){
            break;
        }
        computerMove();
        winner = checkWinner();
        if(winner != ' ' || checkFreeSpaces == 0){
            break;
        }
    }
    printBoard();
    printWinner(winner);
    return 0;
}

void resetBoard(){
    //runs over each row
    for(int i = 0; i < 3; i++){
        //runs over each collumn in a specific row
        for(int j = 0; j < 3; j++){
            board[i][j] = ' ';
        }
    }
}

void printBoard(){
    //create a board structure and fill with data
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n --------- \n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n --------- \n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
}

int checkFreeSpaces(){
    int freeSpaces = 9;
    //run over each space and check if its empty, if not remove a free space
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (board[i][j] != ' ')
            {
                freeSpaces--;
            }
        }   
    }
    return freeSpaces;
}

void playerMove(){
    int x;
    int y;
    do{
        //accept two userinputs, one for rows other for collumns
        printf("enter row 1/2/3");
        scanf("%d", &x);
        x--;
        printf("enter col 1/2/3");
        scanf("%d", &y);
        y--;
        //if the spot is open fill the spot else try again and give a warning
        if(board[x][y] == ' '){
            board[x][y] = PLAYER;
            break;
        }else{
            printf("spot is not available\n");

        }
    }while (board[x][y] != ' ');
}

void computerMove(){
    //randomise x and y of computer placements
    srand(time(0));
    int x;  
    int y;

    if(checkFreeSpaces() > 0){
        do
        {
          x = rand() % 3;
          y = rand() % 3;
        } while (board[x][y] != ' ');
        board[x][y] = COMPUTER;
    }else{
        printWinner(' ');
    }
}

char checkWinner(){
    //check for 3 in a row
    for (int i = 0; i < 3; i++){
        if(board[i][0] == board[i][1]&& board[i][1] == board[i][2]){
            return(board[i][1]);
        }
    }

    //check for 3 in a collumn
    for (int j = 0; j < 3; j++){
        if(board[0][j] == board[1][j]&& board[1][j] == board[2][j]){
            return(board[1][j]);
        }
    }

    //check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] ||
      board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        return(board[1][1]);
    }
    return ' ';
}

void printWinner(char winner){
    //if there is a winner print it else its a tie
    if(winner == ' '){
        printf("its a tie");
    }else if(winner == PLAYER){
        printf("Congratulations you are the winner playing as %c", winner);
    }else{
        printf("Better luck next time! Computer won as %c", winner);
    }
}


