#include "FrequencyChannel.h"
#include "Constants.h"  // Include Constants.h to access MAX_BACKOFF

bool FrequencyChannel::isChannelFree(int users) {
    // Simulate channel contention: The more users, the lower the chance the channel is free
    double probability = 1.0 / (users + 1);
    return (rand() / (double)RAND_MAX) < probability;
}

double FrequencyChannel::getBackoffTime(int users) {
    // Simulate increasing backoff with more users
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(0, MAX_BACKOFF * users);  // Increase backoff with users
    return distribution(generator);
}
