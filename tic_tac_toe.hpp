#include <array>

const int BOARD_SIZE = 9;

class TicTacToe {
public:
    TicTacToe();
    void DrawBoard() const;
    void PlayerMove(char currentPlayer);
    void ComputerMove();
    void Wait(int ms) const;
    bool CheckWinner(char currentPlayer) const;
    bool CheckTie() const;
    void GameLoop();
    void StartGame();

private:
    std::array<char, BOARD_SIZE> board;
    char player;
    char secondPlayer;
    bool running;
    int twoPlayers;

    int GetPlayerMode() const;
    void ResetGame();
};
