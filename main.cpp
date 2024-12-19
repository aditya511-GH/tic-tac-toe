#include <iostream>
#include <ctime>
using namespace std;
void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player);
bool checkTie(char *spaces);
int main() {
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player;
    char computer;
    bool running = true;
    drawBoard(spaces);
    do{
    cout << "Enter your choice (X or O): ";
    cin >> player;
    if(toupper(player) == 'X'){
    while(running){
        computer = 'O';
        playerMove(spaces, player);
        drawBoard(spaces);
        if(checkWinner(spaces, player)){
            running = false;
            break;
        }
        else if(checkTie(spaces)){
            cout << "It is a Tie\n";
            running = false;
            break;
        }
        computerMove(spaces, computer);
        drawBoard(spaces);
        if(checkWinner(spaces, player)){
            running = false;
            break;
        }
        else if(checkTie(spaces)){
            cout << "It is a Tie\n";
            running = false;
            break;
        }
    }break;
    }
    else if(toupper(player) == 'O'){
        while(running){
        computer = 'X';
        computerMove(spaces, computer);
        drawBoard(spaces);
        if(checkWinner(spaces, player)){
            running = false;
            break;
        }
        else if(checkTie(spaces)){
            cout << "It is a Tie\n";
            running = false;
            break;
        }
        playerMove(spaces, player);
        drawBoard(spaces);
        if(checkWinner(spaces, player)){
            running = false;
            break;
        }
        else if(checkTie(spaces)){
            cout << "It is a Tie\n";
            running = false;
            break;
        }
    }break;
    }
    else{
        cout << "Not a Valid Choice!\n";
    }
    }while(toupper(player)!='O'||toupper(player)!='X');
    cout << "Thanks for playing!\n";
    return 0;
}

void drawBoard(char *spaces){
    cout << endl;
    cout << "     |     |     \n";
    cout << "  "<<spaces[0]<<"  |  "<<spaces[1]<<"  |  "<<spaces[2]<<"  \n";
    cout << "_____|_____|_____\n";
    
    cout << "     |     |     \n";
    cout << "  "<<spaces[3]<<"  |  "<<spaces[4]<<"  |  "<<spaces[5]<<"  \n";
    cout << "_____|_____|_____\n";
    
    cout << "     |     |     \n";
    cout << "  "<<spaces[6]<<"  |  "<<spaces[7]<<"  |  "<<spaces[8]<<"  \n";
    cout << "     |     |     \n";
}
void playerMove(char *spaces, char player){
    int guess;
    do{
    cout << "Enter the box you want to mark (1-9): ";
    cin >> guess;
    guess--;
    if(spaces[guess] == ' '){
        spaces[guess] = player;
        break;
        }
    }while(!guess > 0 || !guess < 8);
}
void computerMove(char *spaces, char computer){
    srand(time(0));
    int guess;
    while(true){
        guess = rand()%9;
        if(spaces[guess] == ' '){
            spaces[guess] = computer;
            break;
        }
    }
}
bool checkWinner(char *spaces, char player){
    if((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])){
        spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])){
        spaces[3] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])){
        spaces[6] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])){
        spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])){
        spaces[1] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])){
        spaces[2] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])){
        spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])){
        spaces[2] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else{
        return false;
    }

    return true;
}
bool checkTie(char *spaces){
    for(int i=0; i<9; i++){
        if(spaces[i]==' '){
            return false;
        }
    }
    return true;
}
