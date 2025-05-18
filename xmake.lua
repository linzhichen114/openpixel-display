set_project("OpenPixel")
set_warnings("all", "extra")
set_policy("run.autobuild", true)
set_policy("check.auto_ignore_flags", false)

target("hal")
    set_kind("binary")
    set_default(false)
    add_files("src/hal/*.c", "src/hal/io.S")
    add_files("src/hal/hal_impl.c")
    set_arch("x86_64")  -- 强制amd64
    --add_includedirs("include")
    add_includedirs("include/hal", {public = true})
    add_includedirs("include", {public = true})
    --add_defines("HAL_IMPLEMENTATION")
    add_defines("HAL_IMPL", {public = true})  -- 添加编译宏
    add_cflags("-fuse-ld=lld -nostdlib -ffreestanding -O2 -Iinclude")
    add_ldflags("-nostdlib -T linker.ld -Wl,--build-id=none")
    add_ldflags("-Wl,--gc-sections")  -- 启用GC
    set_toolchains("clang")

    add_cflags("-fuse-ld=lld -nostdlib -ffreestanding -O2 -Iinclude")
    add_ldflags("-nostdlib")

    -- 添加缺失的链接符号
    add_ldflags("-u _start")
