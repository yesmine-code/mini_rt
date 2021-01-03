################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/mlx_linux/mlx_clear_window.c \
../src/mlx_linux/mlx_destroy_display.c \
../src/mlx_linux/mlx_destroy_image.c \
../src/mlx_linux/mlx_destroy_window.c \
../src/mlx_linux/mlx_expose_hook.c \
../src/mlx_linux/mlx_ext_randr.c \
../src/mlx_linux/mlx_flush_event.c \
../src/mlx_linux/mlx_get_color_value.c \
../src/mlx_linux/mlx_get_data_addr.c \
../src/mlx_linux/mlx_hook.c \
../src/mlx_linux/mlx_init.c \
../src/mlx_linux/mlx_int_anti_resize_win.c \
../src/mlx_linux/mlx_int_do_nothing.c \
../src/mlx_linux/mlx_int_get_visual.c \
../src/mlx_linux/mlx_int_param_event.c \
../src/mlx_linux/mlx_int_set_win_event_mask.c \
../src/mlx_linux/mlx_int_str_to_wordtab.c \
../src/mlx_linux/mlx_int_wait_first_expose.c \
../src/mlx_linux/mlx_key_hook.c \
../src/mlx_linux/mlx_lib_xpm.c \
../src/mlx_linux/mlx_loop.c \
../src/mlx_linux/mlx_loop_hook.c \
../src/mlx_linux/mlx_mouse.c \
../src/mlx_linux/mlx_mouse_hook.c \
../src/mlx_linux/mlx_new_image.c \
../src/mlx_linux/mlx_new_window.c \
../src/mlx_linux/mlx_pixel_put.c \
../src/mlx_linux/mlx_put_image_to_window.c \
../src/mlx_linux/mlx_rgb.c \
../src/mlx_linux/mlx_screen_size.c \
../src/mlx_linux/mlx_set_font.c \
../src/mlx_linux/mlx_string_put.c \
../src/mlx_linux/mlx_xpm.c 

OBJS += \
./src/mlx_linux/mlx_clear_window.o \
./src/mlx_linux/mlx_destroy_display.o \
./src/mlx_linux/mlx_destroy_image.o \
./src/mlx_linux/mlx_destroy_window.o \
./src/mlx_linux/mlx_expose_hook.o \
./src/mlx_linux/mlx_ext_randr.o \
./src/mlx_linux/mlx_flush_event.o \
./src/mlx_linux/mlx_get_color_value.o \
./src/mlx_linux/mlx_get_data_addr.o \
./src/mlx_linux/mlx_hook.o \
./src/mlx_linux/mlx_init.o \
./src/mlx_linux/mlx_int_anti_resize_win.o \
./src/mlx_linux/mlx_int_do_nothing.o \
./src/mlx_linux/mlx_int_get_visual.o \
./src/mlx_linux/mlx_int_param_event.o \
./src/mlx_linux/mlx_int_set_win_event_mask.o \
./src/mlx_linux/mlx_int_str_to_wordtab.o \
./src/mlx_linux/mlx_int_wait_first_expose.o \
./src/mlx_linux/mlx_key_hook.o \
./src/mlx_linux/mlx_lib_xpm.o \
./src/mlx_linux/mlx_loop.o \
./src/mlx_linux/mlx_loop_hook.o \
./src/mlx_linux/mlx_mouse.o \
./src/mlx_linux/mlx_mouse_hook.o \
./src/mlx_linux/mlx_new_image.o \
./src/mlx_linux/mlx_new_window.o \
./src/mlx_linux/mlx_pixel_put.o \
./src/mlx_linux/mlx_put_image_to_window.o \
./src/mlx_linux/mlx_rgb.o \
./src/mlx_linux/mlx_screen_size.o \
./src/mlx_linux/mlx_set_font.o \
./src/mlx_linux/mlx_string_put.o \
./src/mlx_linux/mlx_xpm.o 

C_DEPS += \
./src/mlx_linux/mlx_clear_window.d \
./src/mlx_linux/mlx_destroy_display.d \
./src/mlx_linux/mlx_destroy_image.d \
./src/mlx_linux/mlx_destroy_window.d \
./src/mlx_linux/mlx_expose_hook.d \
./src/mlx_linux/mlx_ext_randr.d \
./src/mlx_linux/mlx_flush_event.d \
./src/mlx_linux/mlx_get_color_value.d \
./src/mlx_linux/mlx_get_data_addr.d \
./src/mlx_linux/mlx_hook.d \
./src/mlx_linux/mlx_init.d \
./src/mlx_linux/mlx_int_anti_resize_win.d \
./src/mlx_linux/mlx_int_do_nothing.d \
./src/mlx_linux/mlx_int_get_visual.d \
./src/mlx_linux/mlx_int_param_event.d \
./src/mlx_linux/mlx_int_set_win_event_mask.d \
./src/mlx_linux/mlx_int_str_to_wordtab.d \
./src/mlx_linux/mlx_int_wait_first_expose.d \
./src/mlx_linux/mlx_key_hook.d \
./src/mlx_linux/mlx_lib_xpm.d \
./src/mlx_linux/mlx_loop.d \
./src/mlx_linux/mlx_loop_hook.d \
./src/mlx_linux/mlx_mouse.d \
./src/mlx_linux/mlx_mouse_hook.d \
./src/mlx_linux/mlx_new_image.d \
./src/mlx_linux/mlx_new_window.d \
./src/mlx_linux/mlx_pixel_put.d \
./src/mlx_linux/mlx_put_image_to_window.d \
./src/mlx_linux/mlx_rgb.d \
./src/mlx_linux/mlx_screen_size.d \
./src/mlx_linux/mlx_set_font.d \
./src/mlx_linux/mlx_string_put.d \
./src/mlx_linux/mlx_xpm.d 


# Each subdirectory must supply rules for building sources it contributes
src/mlx_linux/%.o: ../src/mlx_linux/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


