#include "AccessPoint.h"
#include "Constants.h"
#include <iostream>
#include <thread>
#include <mutex>

AccessPoint::AccessPoint(int maxUsers) : maxUsers(maxUsers) {}

void AccessPoint::simulateCommunication(int users, int packets, double subchannel_bandwidth) {
    std::vector<double> latencies;
    double total_time = 0.0;
    FrequencyChannel channel;
    std::mutex latencies_mutex;

    double broadcast_time = TRANSMISSION_TIME;
    total_time += broadcast_time;

    double csi_time = 0.0;
    for (int j = 0; j < users; ++j) {
        User user(j);
        csi_time += user.sendCSI(channel);
    }
    total_time += csi_time;

    double round_robin_time = 0.0;
    std::vector<std::thread> threads;
    for (int i = 0; i < packets; ++i) {
        for (int j = 0; j < users; ++j) {
            threads.push_back(std::thread([&, j]() {
                User user(j);
                double packet_time = user.transmitPacket(channel, users, subchannel_bandwidth);
                std::lock_guard<std::mutex> lock(latencies_mutex);
                latencies.push_back(packet_time);
                round_robin_time += packet_time;
            }));
        }
        for (auto& t : threads) {
            t.join();
        }
        threads.clear();
    }

    total_time += round_robin_time;
    computeMetrics(latencies, total_time, packets);
}

void AccessPoint::computeMetrics(std::vector<double>& latencies, double total_time, int packets) {
    double total_data_bits = packets * PACKET_SIZE;
    double throughput = total_data_bits / total_time;
    throughput /= 1e6;

    double avg_latency = 0.0;
    double max_latency = 0.0;

    for (double l : latencies) {
        avg_latency += l;
        if (l > max_latency) {
            max_latency = l;
        }
    }
    avg_latency /= latencies.size();

    std::cout << "Throughput: " << throughput << " Mbps\n";
    std::cout << "Average Latency: " << avg_latency * 1e3 << " ms\n";
    std::cout << "Maximum Latency: " << max_latency * 1e3 << " ms\n";
}
