cmake_minimum_required(VERSION 3.9)
project(FdF C)

set(CMAKE_C_STANDARD 99)

add_executable(
        libft.h
        fdf.h
        main.c
        parse_map.c
        draw_map.c
        rotate.c
        shift.c
        del_copy_scale_center.c
        bonus.c
)