//
// Created by linzhichen on 25-5-17.
//

#ifndef VBE_H
#define VBE_H
#define VBE_DISPI_IOPORT_INDEX 0x01CE
#define VBE_DISPI_IOPORT_DATA  0x01CF

#include <stdint.h>
enum VBEIndex {
    VBE_DISPI_INDEX_ID       = 0,
    VBE_DISPI_INDEX_XRES     = 1,
    VBE_DISPI_INDEX_YRES     = 2,
    VBE_DISPI_INDEX_BPP      = 3,
    VBE_DISPI_INDEX_ENABLE   = 4,
    VBE_DISPI_INDEX_VSYNC    = 5
};

extern void outw(uint16_t port, uint16_t value);
extern uint16_t inw(uint16_t port);
#endif //VBE_H