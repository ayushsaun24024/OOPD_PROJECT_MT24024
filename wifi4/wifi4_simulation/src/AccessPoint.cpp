#include "AccessPoint.h"
#include "User.h"
#include <iostream>
#include <iomanip>

AccessPoint::AccessPoint(int maxUsers) : maxUsers(maxUsers) {}

void AccessPoint::simulateCommunication(int users, int packets) {
    std::vector<double> latencies;
    double total_time = 0.0;
    FrequencyChannel channel;

    for (int i = 0; i < packets; ++i) {
        for (int j = 0; j < users; ++j) {
            User user(j);
            double packet_time = user.transmitPacket(channel, users);
            latencies.push_back(packet_time);
            total_time += packet_time;
        }
    }

    computeMetrics(latencies, total_time, packets);
}

void AccessPoint::computeMetrics(std::vector<double>& latencies, double total_time, int packets) {
    const double PACKET_SIZE = 8192;
    double total_data_bits = packets * PACKET_SIZE;
    double throughput = total_data_bits / total_time / 1e6;

    double avg_latency = 0.0;
    double max_latency = 0.0;

    for (double l : latencies) {
        avg_latency += l;
        if (l > max_latency) {
            max_latency = l;
        }
    }
    avg_latency /= latencies.size();

    std::cout << "Throughput: " << std::fixed << std::setprecision(2) << throughput << " Mbps\n";
    std::cout << "Average Latency: " << std::fixed << std::setprecision(6) << (avg_latency * 1e3) << " ms\n";
    std::cout << "Maximum Latency: " << std::fixed << std::setprecision(6) << (max_latency * 1e3) << " ms\n";
}
