################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/driver/button.c 

OBJS += \
./Core/Src/driver/button.o 

C_DEPS += \
./Core/Src/driver/button.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/driver/%.o Core/Src/driver/%.su Core/Src/driver/%.cyclo: ../Core/Src/driver/%.c Core/Src/driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/f401ccu_fw/Core/Src/driver" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-driver

clean-Core-2f-Src-2f-driver:
	-$(RM) ./Core/Src/driver/button.cyclo ./Core/Src/driver/button.d ./Core/Src/driver/button.o ./Core/Src/driver/button.su

.PHONY: clean-Core-2f-Src-2f-driver

