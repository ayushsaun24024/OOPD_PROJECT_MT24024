# 📡 WiFi Evolution Simulator

A comprehensive simulation framework for analyzing the evolution of WiFi protocols (WiFi 4, 5, and 6) with focus on throughput, latency, and multi-user capabilities. This project provides detailed insights into the performance characteristics of different WiFi generations.

## 🏗️ Project Structure

```
wifi-simulator/
.
├── Readme.md
├── wifi4
│   ├── setup.sh
│   └── wifi4_simulation
│       ├── bin
│       │   ├── simulation
│       │   └── simulation_debug
│       ├── build
│       │   ├── AccessPoint.o
│       │   ├── AccessPoint_shared.o
│       │   ├── FrequencyChannel.o
│       │   ├── FrequencyChannel_shared.o
│       │   ├── main.o
│       │   ├── main_shared.o
│       │   ├── Packet.o
│       │   ├── Packet_shared.o
│       │   ├── User.o
│       │   └── User_shared.o
│       ├── include
│       │   ├── AccessPoint.h
│       │   ├── FrequencyChannel.h
│       │   ├── Packet.h
│       │   └── User.h
│       ├── lib
│       │   └── libsimulation.so
│       ├── Makefile
│       └── src
│           ├── AccessPoint.cpp
│           ├── FrequencyChannel.cpp
│           ├── main.cpp
│           ├── Packet.cpp
│           └── User.cpp
├── wifi5
│   ├── setup.sh
│   └── wifi5_simulation
│       ├── bin
│       ├── build
│       ├── include
│       │   ├── AccessPoint.h
│       │   ├── Constants.h
│       │   ├── FrequencyChannel.h
│       │   ├── Packet.h
│       │   └── User.h
│       ├── lib
│       ├── Makefile
│       └── src
│           ├── AccessPoint.cpp
│           ├── FrequencyChannel.cpp
│           ├── main.cpp
│           ├── Packet.cpp
│           └── User.cpp
└── wifi6
    ├── setup.sh
    └── wifi6_simulation
        ├── bin
        │   ├── simulation
        │   └── simulation_debug
        ├── build
        │   ├── AccessPoint.o
        │   ├── AccessPoint_shared.o
        │   ├── Constants.o
        │   ├── Constants_shared.o
        │   ├── FrequencyChannel.o
        │   ├── FrequencyChannel_shared.o
        │   ├── main.o
        │   ├── main_shared.o
        │   ├── Packet.o
        │   ├── Packet_shared.o
        │   ├── User.o
        │   └── User_shared.o
        ├── include
        │   ├── AccessPoint.h
        │   ├── Constants.h
        │   ├── FrequencyChannel.h
        │   ├── Packet.h
        │   └── User.h
        ├── lib
        │   └── libsimulation.so
        ├── Makefile
        └── src
            ├── AccessPoint.cpp
            ├── Constants.cpp
            ├── FrequencyChannel.cpp
            ├── main.cpp
            ├── Packet.cpp
            └── User.cpp
```

## 🌟 Features

### WiFi 4 (802.11n) Implementation
- 🔹 Basic CSMA/CA mechanism with exponential backoff
- 🔹 20 MHz bandwidth utilization
- 🔹 256-QAM modulation (8 bits per symbol)
- 🔹 Single-user communication
- 🔹 Random backoff mechanism for collision avoidance
- 🔹 Detailed performance metrics collection
- 🔹 Coding rate: 5/6 for error correction
- 🔹 Maximum theoretical throughput: 133.3 Mbps

### WiFi 5 (802.11ac) Implementation
- 🔹 Enhanced MU-MIMO support (up to 4 spatial streams)
- 🔹 CSI (Channel State Information) collection and processing
- 🔹 Parallel communication capabilities with thread safety
- 🔹 Thread-safe operations with mutex locks
- 🔹 Round-robin scheduling with MU-MIMO grouping
- 🔹 Dynamic user grouping based on spatial streams
- 🔹 CSI feedback mechanism for channel optimization
- 🔹 Maximum theoretical throughput: 533.2 Mbps (4 streams)

### WiFi 6 (802.11ax) Implementation
- 🔹 OFDMA (Orthogonal Frequency Division Multiple Access)
- 🔹 Dynamic subchannel allocation (2 MHz, 4 MHz, 10 MHz)
- 🔹 Enhanced parallel transmission capabilities
- 🔹 Improved CSI feedback mechanism
- 🔹 Adaptive scheduling based on bandwidth requirements
- 🔹 Resource unit allocation algorithms
- 🔹 Multi-user concurrent transmission
- 🔹 BSS coloring for spatial reuse
- 🔹 Maximum theoretical throughput: varies by subchannel configuration

## 🚀 Getting Started

### Prerequisites
- C++ compiler with C++11 support (gcc 4.8.1 or higher)
- pthread library for multi-threading
- Make build system (GNU Make 3.81 or higher)
- At least 4GB RAM for larger simulations
- Linux/Unix-based operating system (tested on Ubuntu 20.04)

### Installation

1. Clone the repository:
```bash
git clone <repository-url>
cd wifi-simulator
```

2. Run the setup script:
```bash
chmod +x setup.sh
./setup.sh
```

The setup script performs the following:
- Checks system requirements
- Creates necessary directories
- Sets up build environment
- Configures compiler options
- Installs required dependencies

3. Build the project:
```bash
make all         # Build all simulations
make wifi4       # Build only WiFi 4 simulation
make wifi5       # Build only WiFi 5 simulation
make wifi6       # Build only WiFi 6 simulation
make clean       # Clean build artifacts
```

### Running Simulations

Execute individual simulations:
```bash
./bin/wifi4_sim [num_users] [num_packets]
./bin/wifi5_sim [num_users] [num_packets]
./bin/wifi6_sim [num_users] [num_packets] [subchannel_size]
```

Default values if not specified:
- num_users: 10
- num_packets: 1000
- subchannel_size: 2 (MHz) for WiFi 6

## 📊 Simulation Parameters

### Common Parameters
```cpp
const double BANDWIDTH = 20e6;           // 20 MHz
const int MODULATION = 8;                // 256-QAM (8 bits per symbol)
const double CODING_RATE = 5.0 / 6.0;    // Coding rate
const int PACKET_SIZE = 8192;            // 1 KB in bits
const double MAX_BACKOFF = 10e-6;        // 10 µs
const int CSI_PACKET_SIZE = 200 * 8;     // 200 bytes in bits
```

### Protocol-Specific Parameters
WiFi 6 Subchannel Sizes:
```cpp
const double SUBCHANNEL_SIZE[] = {2e6, 4e6, 10e6};  // 2 MHz, 4 MHz, 10 MHz
```

WiFi 5 MU-MIMO Configuration:
```cpp
const int NUM_SPATIAL_STREAMS = 4;  // Maximum spatial streams
```

## 📈 Output Metrics

Each simulation provides:
```
Number of users: [X]
Throughput: [Y] Mbps
Average Latency: [Z] ms
Maximum Latency: [W] ms
```

Additional metrics for WiFi 6:
- Per-subchannel utilization
- Resource unit efficiency
- User distribution across subchannels

## 🛠️ Implementation Details

### Key Classes and Methods

#### FrequencyChannel Class
```cpp
class FrequencyChannel {
    bool isChannelFree(int users);
    double getBackoffTime(int users);
    // Protocol-specific methods
};
```

#### User Class
```cpp
class User {
    double sendCSI(FrequencyChannel& channel);
    double transmitPacket(FrequencyChannel& channel, int users);
    // Additional methods per protocol
};
```

#### AccessPoint Class
```cpp
class AccessPoint {
    void simulateCommunication(int users, int packets);
    void computeMetrics(std::vector<double>& latencies, double total_time);
    // Protocol-specific scheduling methods
};
```

## 🧪 Testing Scenarios

### Basic Testing
- Single user (1 user)
- Medium load (10 users)
- Heavy load (100 users)

### Advanced Testing
WiFi 6 subchannel configurations:
- 2 MHz: Maximum granularity
- 4 MHz: Balanced approach
- 10 MHz: Maximum throughput

WiFi 5 MU-MIMO scenarios:
- 1-4 spatial streams
- Different user group sizes
- Various CSI feedback intervals

## 🤖 AI Assistance Acknowledgment

This project was developed with the assistance of various AI tools:

- **ChatGPT**: Helped with initial code structure and debugging
- **Claude**: Assisted in optimizing algorithms and documentation
- **GitHub Copilot**: Provided code suggestions and completion
- **Other AI Tools**: Various code review and optimization assistance

We believe in transparency and acknowledge that while AI tools provided valuable assistance, all code was verified, tested, and optimized by human developers.

## 📊 Simulation Results

### WiFi 4 (802.11n) Results
| Users | Throughput | Average Latency | Maximum Latency |
|-------|------------|-----------------|-----------------|
| 1     | 133.33 Mbps| 0.061440 ms    | 0.061440 ms    |
| 10    | 11.18 Mbps | 0.073288 ms    | 0.170616 ms    |
| 100   | 0.43 Mbps  | 0.192096 ms    | 1.517563 ms    |

Key Observations:
- Optimal performance with single user, achieving near-theoretical maximum throughput
- Significant throughput degradation with increased users
- Latency increases moderately with user count
- Maintains reasonable maximum latency even under heavy load

### WiFi 5 (802.11ac) Results
| Users | Throughput | Average Latency | Maximum Latency |
|-------|------------|-----------------|-----------------|
| 1     | 130.25 Mbps| 0.062821 ms    | 0.081171 ms    |
| 10    | 4.24 Mbps  | 0.193362 ms    | 1.653047 ms    |
| 100   | 0.01 Mbps  | 13.256452 ms   | 148.567602 ms  |

Key Observations:
- Single-user performance comparable to WiFi 4
- More sensitive to increased user count
- Significant latency impact under heavy load
- MU-MIMO benefits not fully realized in high-congestion scenarios

### WiFi 6 (802.11ax) Results with Variable Subchannel Bandwidth

#### Single User (1 User)
| Subchannel | Throughput | Average Latency | Maximum Latency |
|------------|------------|-----------------|-----------------|
| 2 MHz      | 13.30 Mbps | 0.615781 ms    | 0.634131 ms    |
| 4 MHz      | 26.55 Mbps | 0.308517 ms    | 0.321669 ms    |
| 10 MHz     | 65.93 Mbps | 0.124174 ms    | 0.136034 ms    |

#### Medium Load (10 Users)
| Subchannel | Throughput | Average Latency | Maximum Latency |
|------------|------------|-----------------|-----------------|
| 2 MHz      | 1.10 Mbps  | 0.745935 ms    | 2.20601 ms     |
| 4 MHz      | 1.86 Mbps  | 0.439905 ms    | 1.55681 ms     |
| 10 MHz     | 3.18 Mbps  | 0.257609 ms    | 1.53033 ms     |

#### Heavy Load (100 Users)
| Subchannel | Throughput | Average Latency | Maximum Latency |
|------------|------------|-----------------|-----------------|
| 2 MHz      | 0.0059 Mbps| 13.8004 ms     | 135.835 ms     |
| 4 MHz      | 0.0060 Mbps| 13.5580 ms     | 179.330 ms     |
| 10 MHz     | 0.0062 Mbps| 13.3146 ms     | 152.049 ms     |

Key Observations for WiFi 6:
- Clear correlation between subchannel bandwidth and performance
- Larger subchannels provide better throughput and lower latency
- Performance degradation with increased users, but more graceful than WiFi 5
- OFDMA benefits most apparent in medium-load scenarios
- High-load scenarios show similar challenges across all subchannel sizes

## 📈 Performance Analysis

Comparing across protocols:

1. **Single User Performance**
   - WiFi 4 shows best single-user throughput (133.33 Mbps)
   - WiFi 5 close second (130.25 Mbps)
   - WiFi 6 with 10 MHz subchannel achieves 65.93 Mbps

2. **Scalability**
   - All protocols show significant performance degradation with increased users
   - WiFi 4 handles medium load (10 users) best
   - WiFi 6 offers more consistent latency across different user loads
   - WiFi 5 shows most dramatic performance drop in high-load scenarios

3. **Latency Characteristics**
   - WiFi 4 maintains most consistent latency profile
   - WiFi 5 shows highest latency variation under load
   - WiFi 6 demonstrates predictable latency scaling with subchannel size

4. **Resource Utilization**
   - WiFi 6's subchannel approach shows clear throughput/latency tradeoffs
   - Larger subchannels consistently perform better in all scenarios
   - OFDMA's benefits are most apparent in medium-load scenarios

## 📚 References

- IEEE 802.11n Specification
- IEEE 802.11ac Specification
- IEEE 802.11ax Specification
- Various WiFi performance studies and research papers