// AccessPoint.cpp
#include "AccessPoint.h"
#include "Constants.h"
#include <iostream>
#include <iomanip>
#include <thread>
#include <mutex>

AccessPoint::AccessPoint(int maxUsers) : maxUsers(maxUsers) {}

void AccessPoint::simulateCommunication(int users, int packets) {
    std::vector<double> latencies;
    double total_time = 0.0;
    FrequencyChannel channel;

    // Mutex for thread safety
    std::mutex latencies_mutex;

    // Phase 1: Broadcast Packet from AP (1-time broadcast)
    double broadcast_time = TRANSMISSION_TIME;
    total_time += broadcast_time;

    // Phase 2: Collect CSI from all users
    double csi_time = 0.0;
    for (int j = 0; j < users; ++j) {
        User user(j);
        csi_time += user.sendCSI(channel);  // Collect CSI for each user
    }
    total_time += csi_time;

    // Phase 3: Parallel Communication (Round-Robin + MU-MIMO Scheduling)
    double round_robin_time = 0.0;
    std::vector<std::thread> threads;
    int groups = (users + NUM_SPATIAL_STREAMS - 1) / NUM_SPATIAL_STREAMS; // Divide users into groups based on MU-MIMO

    for (int i = 0; i < packets; ++i) {
        for (int g = 0; g < groups; ++g) {
            // Round Robin Scheduling (users are processed sequentially in each group)
            for (int j = 0; j < NUM_SPATIAL_STREAMS; ++j) {
                int user_id = g * NUM_SPATIAL_STREAMS + j;
                if (user_id >= users) break; // Skip if no more users in this group

                threads.push_back(std::thread([&, user_id]() {
                    User user(user_id);
                    double packet_time = user.transmitPacket(channel, users);

                    // Lock the mutex when updating the shared resource
                    std::lock_guard<std::mutex> lock(latencies_mutex);
                    latencies.push_back(packet_time);
                    round_robin_time += packet_time;
                }));
            }

            // Wait for all threads in this group to finish before continuing
            for (auto& t : threads) {
                t.join();
            }
            threads.clear();
        }
    }

    // Total communication time = Broadcast + CSI + parallel communication
    total_time += round_robin_time;

    computeMetrics(latencies, total_time, packets);
}

void AccessPoint::computeMetrics(std::vector<double>& latencies, double total_time, int packets) {
    // Total data transmitted in bits
    double total_data_bits = packets * PACKET_SIZE;  // total bits transmitted

    // Throughput in bits per second
    double throughput = total_data_bits / total_time;

    // Convert to Mbps for easier reading
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

    // Output the results
    std::cout << "Throughput: " << std::fixed << std::setprecision(2) << throughput << " Mbps\n";
    std::cout << "Average Latency: " << std::fixed << std::setprecision(6) << (avg_latency * 1e3) << " ms\n";
    std::cout << "Maximum Latency: " << std::fixed << std::setprecision(6) << (max_latency * 1e3) << " ms\n";
}
