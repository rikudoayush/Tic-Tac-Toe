 // TICTACTOE_H_INCLUDED

#include <iostream>
#include "TicTacToe.h"
#include <conio.h>
#include <iomanip>

TicTacToe::TicTacToe()      // Default Constructor
{
}
void TicTacToe::welcome()
{
    std::cout << "      ***********************************************************" << std::endl;
    std::cout << "      ***                                                     ***" << std::endl;
    std::cout << "      ***        Welcome to Tic Tac Toe (MultiPlayer)         ***" << std::endl;
    std::cout << "      ***                                                     ***" << std::endl;
    std::cout << "      ***********************************************************" << std::endl << std::endl;
    printBoard();           // print game board
}
TicTacToe::~TicTacToe()
{

}
const void TicTacToe::getInput()  // get input from user and find winner
{
    char sign = 'X';
    int input = 0;
    int player = 1;

    do
    {

        player = (player % 2) ? 1:2;   // Alternate user
        std::cout << "Player" << player << " turn: ";
        std::cin >> input;                   // input array numbers
        if((input >= 1 && input <= 9) && ( blockEntries[input - 1] != 'X' && blockEntries[input - 1] != 'O'))
        {
            std::cout << std::endl;
            sign = (player == 1) ? 'X' : 'O';
            blockEntries[input - 1] = sign;
            printBoard();
            if (checkStatus() == 1)
            {
                std::cout << "------------------------------------\n";
                std::cout << "==========> Player" << player << " Wins! <=========\n";
                std::cout << "------------------------------------\n\n\n\n";
                turns = 0;
                resetBoard();

            }

            turns = turns - 1;
            player++;
        }
        else if(input == 0)
            turns = 0;
        else
        {
            std::cout<<"Invalid move ";
            std::cin.ignore();
            std::cout << std::endl;

        }

    }

    while(turns > 1);
    if(turns == 1)
    {
        std::cout << "------------------------------------\n";
        std::cout << "====> Player1 and Player2 Tie <=====\n";
        std::cout << "------------------------------------\n\n\n\n";
        resetBoard();

    }


}
 void TicTacToe::printBoard() const
{
    std::cout << "                 player1 ---> X        Player2 ---> O" << std::endl << std::endl;
    std::cout << std::setw(70) << "Enter 0 to terminate it." << std::endl;
    std::cout << "        |     |        " << std::endl;
    std::cout << "     " << blockEntries[0] << "  |  " << blockEntries[1] << "  |  " << blockEntries[2] << std::endl;
    std::cout << "   _____|_____|_____   " << std::endl;
    std::cout << "        |     |        " << std::endl;
    std::cout << "     " << blockEntries[3] << "  |  " << blockEntries[4] << "  |  " << blockEntries[5] << std::endl;
    std::cout << "   _____|_____|_____   " << std::endl;
    std::cout << "        |     |        " << std::endl;
    std::cout << "     " << blockEntries[6] << "  |  " << blockEntries[7] << "  |  " << blockEntries[8] << std::endl << std::endl;

}
int TicTacToe::checkStatus() const
{
    if (((blockEntries[0] == blockEntries[1] && blockEntries[1] == blockEntries[2] ) ||
        (blockEntries[0] == blockEntries[3] && blockEntries[3] == blockEntries[6] ) ||
        (blockEntries[6] == blockEntries[7] && blockEntries[7] == blockEntries[8] ) ||
        (blockEntries[2] == blockEntries[5] && blockEntries[5] == blockEntries[8] ) ||
        (blockEntries[0] == blockEntries[4] && blockEntries[4] == blockEntries[8] ) ||
        (blockEntries[2] == blockEntries[4] && blockEntries[4] == blockEntries[6] ) ||
        (blockEntries[1] == blockEntries[4] && blockEntries[4] == blockEntries[7] ) ||
     (blockEntries[3] == blockEntries[4] && blockEntries[4] == blockEntries[5] )) &&
        (turns > 1)
       )
        {
            return 1;
        }
}
const void TicTacToe::resetBoard()
{
    int values = 49; // '1' has value 49
    for(int i = 0; i <=9; i++ )
    {
        blockEntries[i] = values;
        values += 1;
    }
}


#include <iostream>
#include "TicTacToe.h"

int main()
{
    char restart;
    TicTacToe game;
    game.welcome();
    game.getInput();
    std::cout << "Do you want to play again? Enter (y/n): ";
    std::cin >> restart;
    if (restart == 'y')
    {
        std::cout << "\n\n\n";
        game.welcome();
        game.getInput();
    }
    else if (restart == 'n')
        return 0;
}
