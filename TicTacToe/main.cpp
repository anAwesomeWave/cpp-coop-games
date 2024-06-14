/*! \file main.cpp
\brief A Documented file.

	Details.
*/

#include <iostream>
#include "server.h"
#include "client.h"


/**
* @brief Entry point
*
* Execution of the TicTacToe game program starts here.
*
* @return Program exit status
*/
int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    char typeOfConnection;
    cout << "Enter type of connection. ";
    cin >> typeOfConnection;
    if (typeOfConnection == 's') {
    	// server's logic
    	server(55001, "127.0.0.1", 55002);
    } else if (typeOfConnection == 'c') {
    	// client's logic
    	client(55002, "127.0.0.1", 55001);
    } else {
        cout << endl << "Incorrect input.";
    }
    return 0;
}
