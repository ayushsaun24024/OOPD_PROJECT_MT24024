// Packet.cpp
#include "Packet.h"

Packet::Packet(int size) : size(size) {}

int Packet::getSize() const {
    return size;
}
