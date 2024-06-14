/*! \file main.cpp
\brief Main file for project.
    All the games are called from here.
*/

#include <iostream>

#include "TicTacToe/server.h"
#include "TicTacToe/client.h"
#include "TronGame/game.h"

/**
* @brief Entry point
*
* Execution of the project starts here.
*
* @return Program exit status
*/
int main() {
    using std::cin;
    using std::cout;

    int game;
    cout << "choose game: (1 - TicTacToe, 2 - Tron)";
    cin >> game;
    if (game == 1) {
        char typeOfConnection;
        cout << "Enter type of connection. (s - server, c - client)";
        cin >> typeOfConnection;
        if(typeOfConnection == 's') {
            // server's logic
            server(55001, "127.0.0.1", 55002);
        } else if(typeOfConnection == 'c') {
            // client's logic
            client(55002, "127.0.0.1", 55001);
        }
    } else if (game == 2) {
        gameLoop();
    }
    return 0;
}
