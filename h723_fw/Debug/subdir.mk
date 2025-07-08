################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../main.c 

OBJS += \
./main.o 

C_DEPS += \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o %.su %.cyclo: ../%.c subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32H723xx -c -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/h723_fw/src" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/h723_fw/src/lib/h723_mx/Core/Inc" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/h723_fw/src/lib/h723_mx/Drivers/CMSIS/Device/ST/STM32H7xx/Include" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/h723_fw/src/lib/h723_mx/Drivers/CMSIS/Include" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/h723_fw/src/lib/h723_mx/Drivers/STM32H7xx_HAL_Driver/Inc" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/h723_fw/src/ap" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/h723_fw/src/bsp" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/h723_fw/src/common" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/h723_fw/src/hw" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/h723_fw/src/lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean--2e-

clean--2e-:
	-$(RM) ./main.cyclo ./main.d ./main.o ./main.su

.PHONY: clean--2e-

