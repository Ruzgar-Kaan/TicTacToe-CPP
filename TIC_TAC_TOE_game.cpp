#include <iostream>
#include <ctime>

// Terminal-based Tic Tac Toe game (Player vs Computer)
// ----------------------------------------------------
// - Player uses 'X'
// - Computer uses 'O'
// - Includes win detection, draw detection, and replay option
// - Uses a 1D array to represent a 3x3 board

void drawBoard(char *spaces);                         // Prints the game board
void playerMove(char *spaces, char player);           // Handles player's move
void computerMove(char *spaces, char computer);       // Handles computer's random move
bool checkWinner(char *spaces, char player, char computer); // Checks all win conditions
bool checkTie(char *spaces);                          // Checks if board is full

int main(){

    char playAgain;

    do {
        // Empty 3x3 board
        char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

        char player = 'X';
        char computer = 'O';
        bool running = true;

        drawBoard(spaces);

        // Main match loop
        while(running){

            // Player turn
            playerMove(spaces, player);
            drawBoard(spaces);

            if(checkWinner(spaces, player, computer)){
                running = false;
                break;
            }
            else if(checkTie(spaces)){
                running = false;
                break;
            }

            // Computer turn
            computerMove(spaces, computer);
            drawBoard(spaces);

            if(checkWinner(spaces, player, computer)){
                running = false;
                break;
            }
            else if(checkTie(spaces)){
                running = false;
                break;
            }
        }

        // Ask to retry
        std::cout << "Do you wanna play again? (Y/N): ";
        std::cin >> playAgain;

        if (playAgain == 'n' || playAgain == 'N') {
            std::cout << "Game is closing\n";
            std::cout << "Thanks for playing\n";
            break;
        }
        else if (playAgain == 'y' || playAgain == 'Y') {
            std::cout << "Let's play again!\n";
        }
        else {
            std::cout << "It's not a valid character!\n";
        }

    } while(playAgain != 'n' && playAgain != 'N');

    return 0;
}

void drawBoard(char *spaces){
    // Prints board in classic tic-tac-toe layout
    std::cout << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << '\n';
}

void playerMove(char *spaces, char player){
    // Player manually selects a board position (1–9)
    int number;

    do{
        std::cout << "Enter a spot to place a marker (1-9): ";
        std::cin >> number;
        number--;

        // Valid spot
        if(spaces[number] == ' '){
            spaces[number] = player;
            break;
        }
    } while(!number > 0 || !number < 8);
}

void computerMove(char *spaces, char computer){
    // Computer randomly selects an empty spot
    int number;
    srand(time(NULL));

    while(true){
        number = rand() % 9;
        if(spaces[number] == ' '){
            spaces[number] = computer;
            break;
        }
    }
}

bool checkWinner(char *spaces, char player, char computer){
    // All winning combinations (rows, columns, diagonals)
    if((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1]== spaces[2])){
       player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4]== spaces[5])){
        player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7]== spaces[8])){
       player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3]== spaces[6])){
        player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4]== spaces[7])){
        player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5]== spaces[8])){
        player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4]== spaces[8])){
        player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4]== spaces[6])){
        player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else{
        return false;
    }
    return true;
}

bool checkTie(char *spaces){
    // If no spaces are empty, it's a draw
    for(int i = 0; i < 9; i++){
        if(spaces[i] == ' '){
            return false;
        }
    }
    std::cout << " IT'S A TIE!\n";
    return true;
}