#ifndef USER_H
#define USER_H

#include "FrequencyChannel.h"

class User {
public:
    User(int id);
    double sendCSI(FrequencyChannel& channel);
    double transmitPacket(FrequencyChannel& channel, int users, double subchannel_bandwidth);

private:
    int id;
};

#endif  // USER_H
