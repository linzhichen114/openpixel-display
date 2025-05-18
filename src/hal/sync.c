//
// Created by linzhichen on 25-5-17.
//
#include <hal/vbe.h>

void wait_vsync() {
    outw(VBE_DISPI_INDEX_VSYNC, 0);
    while(!(inw(VBE_DISPI_INDEX_VSYNC) & 0x01));
}