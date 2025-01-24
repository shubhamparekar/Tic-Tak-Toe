
# Tic-Tac-Toe Project

This project is a simple implementation of the Tic-Tac-Toe game in C++ using object-oriented programming principles. The project is organized into multiple files to improve readability and maintainability. Here's a breakdown of the project structure and how to compile it.

```
project/
│
├── main.cpp
├── tic_tac_toe.hpp
└── tic_tac_toe.cpp
```

### File Descriptions
1. `tic_tac_toe.hpp`: This is the header file that contains the class declaration for the TicTacToe class along with the function prototypes. It defines the interface for the Tic-Tac-Toe game.

2. `tic_tac_toe.cpp`: This source file contains the definitions of the member functions declared in the header file. It implements the game logic for the Tic-Tac-Toe game.

3. `main.cpp`: This file contains the entry point of the program and starts the game by creating an instance of the TicTacToe class.

### Compilation
To compile the project, use the following command:

```sh
g++ -o tic_tac_toe main.cpp tic_tac_toe.cpp`.
```

This command compiles main.cpp and tic_tac_toe.cpp into an executable named tic_tac_toe.

### Running the Program
After compilation, you can run the program with:

```sh
./tic_tac_toe
```

This will start the Tic-Tac-Toe game, where you can choose to play against the computer or a friend.

### Summary
This project demonstrates a simple yet effective way to implement the Tic-Tac-Toe game in C++ using object-oriented programming principles. The code is organized into multiple files to enhance readability and maintainability. Enjoy playing the game and feel free to explore and modify the code!
