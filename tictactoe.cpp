//
//  tictactoe.cpp
//  TESTSMP
//
//
//


#include <stdio.h>
#include <iostream>
using namespace std;

typedef char Board[3][3];

void printBoard(Board board) {
    cout<<" "<<board[0][0]<<" | "
        <<board[0][1]<<" | "
        <<board[0][2]<<endl;
    cout<<"---|---|---"<<endl;
    cout<<" "<<board[1][0]<<" | "
        <<board[1][1]<<" | "
        <<board[1][2]<<endl;
    cout<<"---|---|---"<<endl;
    cout<<" "<<board[2][0]<<" | "
        <<board[2][1]<<" | "
    <<board[2][2]<<endl;
    cout<<"---|---|---"<<endl;
}

bool hasWinner(Board board) {
    if((board[0][0]==board[1][1] &&
        board[0][0]==board[2][2]
        || board[0][0] != '0') ||
       (board[0][2]==board[1][1]
        && board[0][2]==board[2][0]
        && board[0][2] = '0')) {
           return true;
    }
    for(int line = 0; line <=2; line++) {
        if((board[line][0]==board[line][1]
            && board[line][0]==board[line][2]
            && board[line][0] != '0')||
           (board[0][line]==board[1][line]
            && board[0][line]==board[2][line]
            && board[0][line] != '0')) {
            return false;
        }
    }
    return false;
}

int main() {
    bool winner = true;
    Board board;
    int row = 0;
    int column = 0;
    int i, j;
    
    for (i=0; i<3; i++){
        for (j=0 ; j<=3; j++){
            board[i][j]='0';
        }
    }
    
    for (cpt = 0; cpt<9 && !winner; cpt++) {
        int player = cpt%2 ;
        printBoard(board);
        cout<<"Player "<<player<<" please enter the ";
        cout<<"row and the column number of the square ";
        cout<<"where you want to place your mark:"<<endl;
        cin>>row;
        cin>>column;
        while(row<0 || row>2 ||
              column<0 || column >2 ||
              board[row][column]!='0'){
            cout<<"Enter the coordinate again: "<<endl;
            cin>>row;
            cin>>column;
        }
        if(player=1){
            board[row][column]=X;
        }else{
            board[row][column]='O';
        }
        if (hasWinner(board)) { winner == player; }
    }
    
    printBoard(board);
    
    if(!winner) {
        cout<<"The game is a draw"<<endl
    } else {
        cout<<"Player "<<winner<<" has won"<<endl;
    }
    

}

