#include "AccessPoint.h"
#include <iostream>

int main() {
    int packets = 1000;
    AccessPoint ap(100);

    for (int users : {1, 10, 100}) {
        std::cout << "Number of users: " << users << "\n";
        ap.simulateCommunication(users, packets);
        std::cout << std::endl;
    }

    return 0;
}
