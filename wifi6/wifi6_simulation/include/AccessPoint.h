#ifndef ACCESSPOINT_H
#define ACCESSPOINT_H

#include "User.h"
#include "FrequencyChannel.h"
#include <vector>

class AccessPoint {
public:
    AccessPoint(int maxUsers);
    void simulateCommunication(int users, int packets, double subchannel_bandwidth);

private:
    int maxUsers;
    void computeMetrics(std::vector<double>& latencies, double total_time, int packets);
};

#endif  // ACCESSPOINT_H
