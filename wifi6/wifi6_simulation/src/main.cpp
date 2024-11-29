#include "AccessPoint.h"
#include "Constants.h"  // Include Constants.h to access SUBCHANNEL_SIZE
#include <iostream>

int main() {
    int packets = 1000;
    AccessPoint ap(100);

    for (int users : {1, 10, 100}) {
        std::cout << "Number of users: " << users << "\n";
        for (double subchannel_bandwidth : SUBCHANNEL_SIZE) {
            std::cout << "Subchannel Bandwidth: " << subchannel_bandwidth / 1e6 << " MHz\n";
            ap.simulateCommunication(users, packets, subchannel_bandwidth);
            std::cout << std::endl;
        }
    }

    return 0;
}
