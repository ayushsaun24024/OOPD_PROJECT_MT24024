#ifndef FREQUENCYCHANNEL_H
#define FREQUENCYCHANNEL_H

class FrequencyChannel {
public:
    bool isChannelFree(int users);
    double getBackoffTime();
};

#endif // FREQUENCYCHANNEL_H
