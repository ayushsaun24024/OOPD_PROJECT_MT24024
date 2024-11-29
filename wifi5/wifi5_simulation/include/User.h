// User.h
#ifndef USER_H
#define USER_H

#include "FrequencyChannel.h"

class User {
public:
    User(int id);
    double sendCSI(FrequencyChannel& channel);
    double transmitPacket(FrequencyChannel& channel, int users);

private:
    int id;
};

#endif
