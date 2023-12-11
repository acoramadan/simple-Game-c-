#include<iostream>
#include<stdlib.h>
using namespace std;

char board [3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int pilihan;
int baris,kolom;
char turn = 'X';
bool draw = false;

void display_papan ();
void Player_turn();
bool gameover();


int main(){
    cout << "\t Selamat datang di permainan Tik tac toe " << endl << "\tmenggunakan 2 orang" << endl;
    while(gameover()){
        display_papan();
        Player_turn();
        gameover();
    }
    if (turn == 'O' && draw == false){
        cout << "Selamat player (X) memenangkan pertandingan" << endl;
    }
    else if (turn == 'X' && draw == false){
        cout << "Selamat player (O) memenangkan pertandingan" << endl;
    }
    else {
        cout << "tidak ada yang memenangkan pertandingan (DRAW)" << endl;
    }
    return 0;
}
void display_papan (){
    cout << "Player 1 = [X]\t  Player 2 = [O]\n";
    cout << "\t      |     |       \n";
    cout << "\t   "<< board[0][0]<< "  |  "<< board[0][1] <<"  |  "<<board[0][2] << "\n";
    cout << "\t______|_____|_______\n";
    cout << "\t      |     |       \n";
    cout << "\t   "<< board[1][0]<< "  |  "<< board[1][1] <<"  |  "<<board[1][2] << "\n";
    cout << "\t______|_____|_______\n";
    cout << "\t      |     |       \n";
    cout << "\t   "<< board[2][0]<< "  |  "<< board[2][1] <<"  |  "<<board[2][2] << "\n";
    cout << "\t      |     |       \n";
}
void Player_turn(){
    if (turn =='X'){
        cout << "ntPLayer 1 [x] turn :";
    }
    else if (turn=='O'){
        cout <<"ntPLayer 2 [O] turn :";
    }
    cin >> pilihan;
    switch (pilihan){
            case 1 : baris = 0;
                     kolom = 0;
                     break;
            case 2 : baris = 0;
                     kolom = 1;
                     break;
            case 3 : baris = 0;
                     kolom = 2;
                     break;
            case 4 : baris = 1;
                     kolom = 0;
                     break;
            case 5 : baris = 1;
                     kolom = 1;
                     break;
            case 6 : baris = 1;
                     kolom = 2;
                     break;
            case 7 : baris = 2;
                     kolom = 0;
                     break;
            case 8 : baris = 2;
                     kolom = 1;
                     break;
            case 9 : baris = 2;
                     kolom = 2;
                     break;
            default : cout << "invalid move";

    }
    if (turn == 'X' && board [baris][kolom] != 'X' && board[baris][kolom] != 'O' ){

        board [baris][kolom] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && board [baris][kolom] != 'X' && board[baris][kolom] !='O'){
        board [baris][kolom] = 'O';
        turn = 'X';
    }
    else {
        cout << "Baris telah di isi oleh player lain " << endl;
        Player_turn();
    }
    display_papan();
}
bool gameover(){
    for (int i = 0; i<3; i++)
    if (board [i][0] == board[i][1] && board [i][0] == board[i][2] || board [0][i] ==board[1][i] && board[0][i]==board[2][i])
    return false;

    if (board[0][0] == board [1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board [2][0])
    return false;

    for(int i = 0; i<3; i++)
    for(int j= 0; i <3; j++)
    if (board [i][j] !='X' && board [i][j] !='O')
    return true;

    draw = true;
    return false; 
}