// User.cpp
#include "User.h"
#include "Constants.h"

User::User(int id) : id(id) {}

double User::sendCSI(FrequencyChannel& channel) {
    // Sending CSI takes time, equivalent to the CSI packet size transmission
    double latency = CSI_TIME;
    return latency;
}

double User::transmitPacket(FrequencyChannel& channel, int users) {
    double latency = 0.0;
    while (true) {
        if (channel.isChannelFree(users)) {
            latency += TRANSMISSION_TIME;
            return latency;
        } else {
            double backoff = channel.getBackoffTime(users);  // Increased backoff with more users
            latency += backoff;
        }
    }
}
