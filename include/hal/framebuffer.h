//
// Created by linzhichen on 25-5-18.
//
#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

extern struct FrameBuffer fb;

struct FrameBuffer {
    uint32_t* base;
    uint32_t width;
    uint32_t height;
    uint32_t pitch;
    uint32_t format;
};
#ifdef __cplusplus
}
#endif
#endif //FRAMEBUFFER_H