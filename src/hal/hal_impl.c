//
// Created by linzhichen on 25-5-18.
//
#include <hal/hal_impl.h>
#include <hal/hal_interface.h>
#include <hal/framebuffer.h>

// 隔离驱动符号
struct FrameBuffer fb __attribute__((section(".driver_data")));
const HAL_Driver qemu_hal __attribute__((section(".driver_rodata"))) = {
    .init = hal_init,
    .put_pixel = fb_put_pixel,
    .flush = wait_vsync,
    .get_resolution = hal_get_resolution
};