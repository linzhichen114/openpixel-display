//
// Created by linzhichen on 25-5-17.
//

#ifndef HAL_INTERFACE_H
#define HAL_INTERFACE_H
#include <stdint.h>
void hal_init(uint32_t width, uint32_t height);
void fb_put_pixel(uint32_t x, uint32_t y, uint32_t color);
void wait_vsync();
void hal_get_resolution(uint32_t* w, uint32_t* h);

typedef struct {
    void (*init)(uint32_t, uint32_t);
    void (*put_pixel)(uint32_t, uint32_t, uint32_t);
    void (*flush)(void);
    void (*get_resolution)(uint32_t*, uint32_t*);
} HAL_Driver;

extern const HAL_Driver qemu_hal;
#endif //HAL_INTERFACE_H