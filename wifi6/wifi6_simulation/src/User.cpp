#include "User.h"
#include "Constants.h"

User::User(int id) : id(id) {}

double User::sendCSI(FrequencyChannel& channel) {
    // Sending CSI takes time, equivalent to the CSI packet size transmission
    return CSI_TIME;
}

double User::transmitPacket(FrequencyChannel& channel, int users, double subchannel_bandwidth) {
    double latency = 0.0;
    while (true) {
        if (channel.isChannelFree(users)) {
            // Transmission time depends on subchannel bandwidth
            double user_data_rate = subchannel_bandwidth * MODULATION * CODING_RATE;
            double packet_time = PACKET_SIZE / user_data_rate;
            latency += packet_time;
            return latency;
        } else {
            double backoff = channel.getBackoffTime(users);
            latency += backoff;
        }
    }
}
