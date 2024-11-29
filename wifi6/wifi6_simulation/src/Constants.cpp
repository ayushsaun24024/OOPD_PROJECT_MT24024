#include "Constants.h"

// Constants for Wi-Fi 6 (OFDMA) - Definitions only
const double BANDWIDTH = 20e6;  // 20 MHz for simplicity
const double SUBCHANNEL_SIZE[3] = {2e6, 4e6, 10e6};  // Define the 3 elements
const int MODULATION = 8;  // 256-QAM (8 bits per symbol)
const double CODING_RATE = 5.0 / 6.0;  // Coding rate (5/6)
const double DATA_RATE = BANDWIDTH * MODULATION * CODING_RATE;  // Data rate in bits per second
const int PACKET_SIZE = 8192;  // 1 KB in bits
const int CSI_PACKET_SIZE = 200 * 8;  // 200 bytes in bits for CSI
const double TRANSMISSION_TIME = PACKET_SIZE / DATA_RATE;  // Transmission time for one packet
const double CSI_TIME = CSI_PACKET_SIZE / DATA_RATE;  // Time for CSI packet
const double MAX_BACKOFF = 10e-6;  // Backoff time in seconds
const double PARALLEL_COMMUNICATION_TIME = 0.015;  // Parallel communication time (15 ms)
