#include <iostream>
#include "server.h"
#include "client.h"

int main()
{
    char typeOfConnection;
    std::cout << "Enter type of connection. ";
    std::cin >> typeOfConnection;
    if(typeOfConnection == 's') {
    	// server's logic
    	server(55001, "127.0.0.1", 55002);
    } else if(typeOfConnection == 'c') {
    	// client's logic
    	client();
    } else {
        std::cout << std::endl << "Incorrect input.";
    }
    return 0;
}
