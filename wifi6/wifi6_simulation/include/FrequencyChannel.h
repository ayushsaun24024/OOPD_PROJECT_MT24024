#ifndef FREQUENCY_CHANNEL_H
#define FREQUENCY_CHANNEL_H

#include <random>

class FrequencyChannel {
public:
    bool isChannelFree(int users);
    double getBackoffTime(int users);
};

#endif  // FREQUENCY_CHANNEL_H
