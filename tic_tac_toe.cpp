#include "tic_tac_toe.hpp"
#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>

TicTacToe::TicTacToe() : board{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, player('X'), secondPlayer('O'), running(true) {}

void TicTacToe::DrawBoard() const
{
    system("cls");
    std::cout << "\n"
              << std::endl;
    std::cout << "1    |2    |3    " << std::endl;
    std::cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  " << std::endl;
    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "4    |5    |6    " << std::endl;
    std::cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  " << std::endl;
    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "7    |8    |9    " << std::endl;
    std::cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  " << std::endl;
    std::cout << "     |     |     " << std::endl;
}

void TicTacToe::PlayerMove(char currentPlayer)
{
    int number;
    while (true)
    {
        std::cout << "\nEnter a spot to place the marker (1-9): ";
        std::cin >> number;
        number--;
        if (number >= 0 && number < BOARD_SIZE && board[number] == ' ')
        {
            board[number] = currentPlayer;
            break;
        }
        else
        {
            std::cout << "Invalid input or spot already taken. Please try again.\n";
        }
    }
}

void TicTacToe::ComputerMove()
{
    int number;
    srand(static_cast<unsigned int>(time(0)));

    while (true)
    {
        number = rand() % BOARD_SIZE;
        if (board[number] == ' ')
        {
            board[number] = secondPlayer;
            break;
        }
    }
}

void TicTacToe::Wait(int ms) const
{
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

bool TicTacToe::CheckWinner(char currentPlayer) const
{
    const int winningCombinations[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}};

    for (int i = 0; i < 8; ++i)
    {
        int a = winningCombinations[i][0];
        int b = winningCombinations[i][1];
        int c = winningCombinations[i][2];

        if ((board[a] != ' ') && (board[a] == board[b]) && (board[b] == board[c]))
        {
            if (board[a] == player)
            {
                std::cout << "YOU WIN!\n";
            }
            else if (board[a] == secondPlayer)
            {
                if (twoPlayers == 1)
                {
                    std::cout << "THE SECOND PLAYER WINS!\n";
                }
                else if (twoPlayers == 0)
                {
                    std::cout << "YOU LOST!\n";
                }
            }
            return true;
        }
    }
    return false;
}

bool TicTacToe::CheckTie() const
{
    for (const char &spot : board)
    {
        if (spot == ' ')
        {
            return false;
        }
    }
    std::cout << "It is a Tie!\n"
              << std::endl;
    return true;
}

void TicTacToe::GameLoop()
{
    DrawBoard();

    while (running)
    {
        PlayerMove(player);
        DrawBoard();
        if (CheckWinner(player) || CheckTie())
        {
            running = false;
            break;
        }

        if (twoPlayers == 0)
        {
            std::cout << "\nComputer is thinking" << std::endl;
            Wait(2000);
            ComputerMove();
        }
        else if (twoPlayers == 1)
        {
            PlayerMove(secondPlayer);
        }
        DrawBoard();
        if (CheckWinner(secondPlayer) || CheckTie())
        {
            running = false;
            break;
        }
    }
}

void TicTacToe::StartGame()
{
    while (true)
    {
        twoPlayers = GetPlayerMode();
        GameLoop();

        char choice;
        Wait(1000);
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> choice;

        if ((choice == 'N') || (choice == 'n'))
        {
            std::cout << "Thank you for playing" << std::endl;
            break;
        }
        else if ((choice == 'Y') || (choice == 'y'))
        {
            std::cout << "The game is starting" << std::endl;
            Wait(2000);
            ResetGame();
        }
        else
        {
            std::cout << "Invalid input. Please try again.\n"
                      << std::endl;
        }
    }
}

int TicTacToe::GetPlayerMode() const
{
    int mode;
    std::cout << "Play with Computer. Press 0" << std::endl;
    std::cout << "Play with Friend. Press 1" << std::endl;

    while (true)
    {
        std::cin >> mode;
        if (mode == 0)
        {
            std::cout << "Play with Computer\n"
                      << std::endl;
            break;
        }
        else if (mode == 1)
        {
            std::cout << "Play with Friend\n"
                      << std::endl;
            break;
        }
        else
        {
            std::cout << "Invalid input. Please try again.\n"
                      << std::endl;
        }
    }
    return mode;
}

void TicTacToe::ResetGame()
{
    board.fill(' ');
    running = true;
}
