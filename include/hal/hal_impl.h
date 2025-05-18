//
// Created by linzhichen on 25-5-18.
//

#ifndef HAL_IMPL_H
#define HAL_IMPL_H
#include <hal/hal_interface.h>
#include <hal/framebuffer.h>  // 添加结构体定义

extern struct FrameBuffer fb;

extern const HAL_Driver qemu_hal;/* = {
    .init = hal_init,
    .put_pixel = fb_put_pixel,
    .flush = wait_vsync,
    .get_resolution = hal_get_resolution
};*/
#endif //HAL_IMPL_H