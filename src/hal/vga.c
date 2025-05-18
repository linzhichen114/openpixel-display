//
// Created by linzhichen on 25-5-17.
//
#include <hal/vbe.h>
#include <hal/framebuffer.h>

/*static */extern struct FrameBuffer fb;

void hal_init(uint32_t width, uint32_t height) {
    // 禁用现有模式
    outw(VBE_DISPI_INDEX_ENABLE, 0);

    // 设置分辨率
    outw(VBE_DISPI_INDEX_XRES, width);
    outw(VBE_DISPI_INDEX_YRES, height);
    outw(VBE_DISPI_INDEX_BPP, 32);

    // 启用线性缓冲模式
    outw(VBE_DISPI_INDEX_ENABLE, 0x41); // LFB模式 + 启用

    // 映射QEMU标准帧缓冲地址
    fb.base = (uint32_t*)0xFD000000;
    fb.width = width;
    fb.height = height;
    fb.pitch = width * 4;
}

void fb_put_pixel(uint32_t x, uint32_t y, uint32_t color) {
    if(x >= fb.width || y >= fb.height) return;
    volatile uint32_t *pixel = fb.base + y * (fb.pitch / 4) + x;
    *pixel = (color & 0x00FFFFFF) | 0xFF000000; // 强制Alpha
}

void hal_get_resolution(uint32_t *w, uint32_t *h) {
    *w = fb.width;
    *h = fb.height;
}

void fb_flush() {
    asm volatile("mfence" ::: "memory"); // 内存屏障
}