// FrequencyChannel.h
#ifndef FREQUENCYCHANNEL_H
#define FREQUENCYCHANNEL_H

#include "Constants.h"

class FrequencyChannel {
public:
    bool isChannelFree(int users);
    double getBackoffTime(int users);
};

#endif
