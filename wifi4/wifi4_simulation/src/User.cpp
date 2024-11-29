#include "User.h"

User::User(int id) : id(id) {}

double User::transmitPacket(FrequencyChannel& channel, int users) {
    const double PACKET_SIZE = 8192;
    const double BANDWIDTH = 20e6;
    const int MODULATION = 8;
    const double CODING_RATE = 5.0 / 6.0;
    const double DATA_RATE = BANDWIDTH * MODULATION * CODING_RATE;
    const double TRANSMISSION_TIME = PACKET_SIZE / DATA_RATE;

    double latency = 0.0;
    while (true) {
        if (channel.isChannelFree(users)) {
            latency += TRANSMISSION_TIME;
            return latency;
        } else {
            double backoff = channel.getBackoffTime();
            latency += backoff;
        }
    }
}
