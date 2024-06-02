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
    	server();
    } else if(typeOfConnection == 'c') {
    	// client's logic
    	client();
    } else {
        std::cout << std::endl << "Incorrect input.";
    }
    return 0;
}
