// main.cpp
#include "AccessPoint.h"
#include <iostream>

int main() {
    int packets = 1000;  // Number of packets per user
    AccessPoint ap(100);  // Maximum number of users in the system

    // Simulate for different number of users: 1, 10, 100
    for (int users : {1, 10, 100}) {
        std::cout << "Number of users: " << users << "\n";
        ap.simulateCommunication(users, packets);
        std::cout << std::endl;
    }

    return 0;
}
