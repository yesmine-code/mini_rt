################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Check.c \
../src/check2.c \
../src/check3.c \
../src/check4.c \
../src/color_utils.c \
../src/cylinder_equation.c \
../src/free_functions.c \
../src/get_num.c \
../src/get_structs.c \
../src/get_structs2.c \
../src/hook.c \
../src/inter_all_obj.c \
../src/intersection.c \
../src/list_functions.c \
../src/minirt.c \
../src/mymlx.c \
../src/obj_equation.c \
../src/printforms.c \
../src/vector1.c \
../src/vector2.c 

OBJS += \
./src/Check.o \
./src/check2.o \
./src/check3.o \
./src/check4.o \
./src/color_utils.o \
./src/cylinder_equation.o \
./src/free_functions.o \
./src/get_num.o \
./src/get_structs.o \
./src/get_structs2.o \
./src/hook.o \
./src/inter_all_obj.o \
./src/intersection.o \
./src/list_functions.o \
./src/minirt.o \
./src/mymlx.o \
./src/obj_equation.o \
./src/printforms.o \
./src/vector1.o \
./src/vector2.o 

C_DEPS += \
./src/Check.d \
./src/check2.d \
./src/check3.d \
./src/check4.d \
./src/color_utils.d \
./src/cylinder_equation.d \
./src/free_functions.d \
./src/get_num.d \
./src/get_structs.d \
./src/get_structs2.d \
./src/hook.d \
./src/inter_all_obj.d \
./src/intersection.d \
./src/list_functions.d \
./src/minirt.d \
./src/mymlx.d \
./src/obj_equation.d \
./src/printforms.d \
./src/vector1.d \
./src/vector2.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


