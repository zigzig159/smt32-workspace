################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/driver/button.c 

OBJS += \
./Core/driver/button.o 

C_DEPS += \
./Core/driver/button.d 


# Each subdirectory must supply rules for building sources it contributes
Core/driver/%.o Core/driver/%.su Core/driver/%.cyclo: ../Core/driver/%.c Core/driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H723xx -c -I../Core/Inc -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/stm32h723zg_fw/Core/driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-driver

clean-Core-2f-driver:
	-$(RM) ./Core/driver/button.cyclo ./Core/driver/button.d ./Core/driver/button.o ./Core/driver/button.su

.PHONY: clean-Core-2f-driver

