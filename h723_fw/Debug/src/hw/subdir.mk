################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/hw/hw.c 

OBJS += \
./src/hw/hw.o 

C_DEPS += \
./src/hw/hw.d 


# Each subdirectory must supply rules for building sources it contributes
src/hw/%.o src/hw/%.su src/hw/%.cyclo: ../src/hw/%.c src/hw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32H723xx -c -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/h723_fw/src" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/h723_fw/src/lib/h723_mx/Core/Inc" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/h723_fw/src/lib/h723_mx/Drivers/CMSIS/Device/ST/STM32H7xx/Include" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/h723_fw/src/lib/h723_mx/Drivers/CMSIS/Include" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/h723_fw/src/lib/h723_mx/Drivers/STM32H7xx_HAL_Driver/Inc" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/h723_fw/src/ap" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/h723_fw/src/bsp" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/h723_fw/src/common" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/h723_fw/src/hw" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/h723_fw/src/lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-src-2f-hw

clean-src-2f-hw:
	-$(RM) ./src/hw/hw.cyclo ./src/hw/hw.d ./src/hw/hw.o ./src/hw/hw.su

.PHONY: clean-src-2f-hw

