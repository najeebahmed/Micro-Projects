#include<iostream>
using namespace std;

char board[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int winner = 0;
string version = "1.0";

class Board
{
  public:
    void drawBoard();
    void replaceSpot(int * spotNum, int player);
    void checkForWinner();
    
    int turn;
};

void Board::drawBoard()
{
  cout << "\033[2J\033[1;1H";
  cout << "TIC TAC TOE v. " << version << "\n";
  cout << " ___________________________ \n";
  cout << "|                           |\n";
  cout << "|         |       |         |\n";
  cout << "|     " << board[1] << "   |   " << board[2] << "   |   " << board[3] << "     |\n";
  cout << "|         |       |         |\n";
  cout << "|  -------|-------|-------  |\n";
  cout << "|         |       |         |\n";
  cout << "|     " << board[4] << "   |   " << board[5] << "   |   " << board[6] << "     |\n";
  cout << "|         |       |         |\n";
  cout << "|  -------|-------|-------  |\n";
  cout << "|         |       |         |\n";
  cout << "|     " << board[7] << "   |   " << board[8] << "   |   " << board[9] << "     |\n";
  cout << "|         |       |         |\n";
  cout << "|___________________________|\n";

}

void Board::replaceSpot(int *spotNum, int player) 
{
  if (*spotNum < 10 && spotNum > 0 && board[*spotNum] != 'X' && board[*spotNum] != 'O')
    if (player == 1)
      board[*spotNum] = 'X';
    else
      board[*spotNum] = 'O';
  else
    *spotNum = 0;
}

void Board::checkForWinner()
{
  if (board[2] == board[1] && board[2] == board[3]) 
  {
    if (board[2] == 'X')
    { 
      winner = 1;
    }
    else
    {
      winner = 2;
    }
  } 
  else if (board[8] == board[7] && board[8] == board[9]) 
  {
    if (board[8] == 'X')
    { 
      winner = 1;
    }
    else
    {
      winner = 2;
    }
  }
  else if (board[4] == board[1] && board[4] == board[7]) 
  {
    if (board[4] == 'X')
    { 
      winner = 1;
    }
    else
    {
      winner = 2;
    }
  }
  else if (board[6] == board[3] && board[6] == board[9]) 
  {
    if (board[6] == 'X')
    { 
      winner = 1;
    }
    else
    {
      winner = 2;
    }
  }
  else if (board[5] == board[4] && board[5] == board[6]) 
  {
    if (board[5] == 'X')
    { 
      winner = 1;
    }
    else
    {
      winner = 2;
    }
  }
  else if (board[5] == board[2] && board[5] == board[8]) 
  {
    if (board[5] == 'X')
    { 
      winner = 1;
    }
    else
    {
      winner = 2;
    }
  }
  else if (board[5] == board[1] && board[5] == board[9]) 
  {
    if (board[5] == 'X')
    { 
      winner = 1;
    }
    else
    {
      winner = 2;
    }
  }
  else if (board[5] == board[3] && board[5] == board[7]) 
  {
    if (board[5] == 'X')
    { 
      winner = 1;
    }
    else
    {
      winner = 2;
    }
  }
}

int main() 
{
  Board myBoard;
  myBoard.drawBoard();
  int turn = 0;
  int player = 0; 
 
  while(!winner && ++turn < 10) {
    int spot = 0;
    while (!spot) 
    {
      cout << "Player " << player + 1 << ", please enter a valid spot: ";
      cin >> spot;
      if (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        spot = 0;
      }
      myBoard.replaceSpot(&spot, player + 1);
    } 
    myBoard.drawBoard();
    myBoard.checkForWinner();
    player = (++player) % 2;
  }

  if (winner)
    cout << "Player " << winner << " has won the game!\n";
  else
    cout << "Game has tied!\n";
 
}
