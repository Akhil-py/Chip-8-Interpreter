#include <cstdint>

class Chip8 {
    public:
        uint8_t memory[4096]{};
        uint32_t display[64 * 32]{}; // Monochrome display
        uint16_t pc{};
        uint16_t index{};
        uint16_t stack[16]{};
        uint8_t sp{}; // Stack pointer
        uint8_t delayTimer{}; // Decrements at 60Hz
        uint8_t soundTimer{}; // Decrements at 60Hz, buzzes when non-zero
        uint8_t registers[16]{}; // v0-vF
};