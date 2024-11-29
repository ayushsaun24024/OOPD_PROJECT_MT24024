// Constants.h
#ifndef CONSTANTS_H
#define CONSTANTS_H

// Constants for Wi-Fi 5 (802.11ac)
const double BANDWIDTH = 20e6;  // 20 MHz for simplicity (Wi-Fi 5 supports up to 160 MHz)
const int MODULATION = 8;       // 256-QAM (8 bits per symbol)
const double CODING_RATE = 5.0 / 6.0;
const double DATA_RATE = BANDWIDTH * MODULATION * CODING_RATE;  // bits per second
const int PACKET_SIZE = 8192;   // 1 KB in bits
const int CSI_PACKET_SIZE = 200 * 8; // 200 bytes in bits for CSI
const double TRANSMISSION_TIME = PACKET_SIZE / DATA_RATE;  // time for one packet transmission in seconds
const double CSI_TIME = CSI_PACKET_SIZE / DATA_RATE;  // time for one CSI packet transmission
const double MAX_BACKOFF = 10e-6;  // 10 µs backoff
const double PARALLEL_COMMUNICATION_TIME = 0.015;  // 15 ms of parallel communication
const int NUM_SPATIAL_STREAMS = 4; // Maximum spatial streams (MU-MIMO)

#endif
