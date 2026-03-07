#include <iostream>
#include <iomanip>

enum Marker : char {
    START = 0x10,
    END = START + 5
};

struct Packet {
    Marker head;   // 1 byte
    // ? bytes padding
    int ID;        // 4 bytes
};

union RawData {
    Packet p;
    unsigned char stream[8];
};

int main() {
    RawData data = {0}; // Initialize all memory to 0
    
    data.p.head = END;
    data.p.ID = 0x04030201;

    // What are these three values?
    std::cout << (int)data.stream[0] << " " 
              << (int)data.stream[1] << " " 
              << (int)data.stream[4] << std::endl;

    return 0;
}