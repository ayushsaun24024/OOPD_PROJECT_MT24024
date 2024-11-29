#include "FrequencyChannel.h"
#include <random>

bool FrequencyChannel::isChannelFree(int users) {
    return (rand() / (double)RAND_MAX) < (1.0 / users);
}

double FrequencyChannel::getBackoffTime() {
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(0, 10e-6);
    return distribution(generator);
}
