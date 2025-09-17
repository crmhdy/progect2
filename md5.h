#pragma once
#define MD5_H

#include <string>

class MD5 {
public:
    MD5();
    void update(const unsigned char* input, size_t length);
    void update(const char* input, size_t length);
    std::string final();
    static std::string md5(const std::string str);

private:
    void transform(const uint8_t block[64]);
    void encode(const uint32_t* input, uint8_t* output, size_t length);
    void decode(const uint8_t* input, uint32_t* output, size_t length);

    bool finished;
    uint32_t state[4];   // A, B, C, D
    uint32_t count[2];   // number of bits, modulo 2^64
    uint8_t buffer[64];  // input buffer
    uint8_t digest[16];  // result
};



