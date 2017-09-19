#ifndef TICTACTOE_H_INCLUDED
#define TICTACTOE_H_INCLUDED

class TicTacToe
{
public:
    TicTacToe();
    ~TicTacToe();
    void welcome();
    const  void getInput();
private:
    char blockEntries[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int checkStatus() const;
    int turns = 10;
    void printBoard() const;
    const void resetBoard();
 };

#endif
