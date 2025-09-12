################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/driver/ili9341/ili9341_GFX.c \
../Core/Src/driver/ili9341/ili9341_STM32_Driver.c 

OBJS += \
./Core/Src/driver/ili9341/ili9341_GFX.o \
./Core/Src/driver/ili9341/ili9341_STM32_Driver.o 

C_DEPS += \
./Core/Src/driver/ili9341/ili9341_GFX.d \
./Core/Src/driver/ili9341/ili9341_STM32_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/driver/ili9341/%.o Core/Src/driver/ili9341/%.su Core/Src/driver/ili9341/%.cyclo: ../Core/Src/driver/ili9341/%.c Core/Src/driver/ili9341/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/stm32g431_fw/Core/Src/driver/ssd1306" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/stm32g431_fw/Core/Src/driver/ili9341" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/stm32g431_fw/Core/Src/driver/st7789" -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-driver-2f-ili9341

clean-Core-2f-Src-2f-driver-2f-ili9341:
	-$(RM) ./Core/Src/driver/ili9341/ili9341_GFX.cyclo ./Core/Src/driver/ili9341/ili9341_GFX.d ./Core/Src/driver/ili9341/ili9341_GFX.o ./Core/Src/driver/ili9341/ili9341_GFX.su ./Core/Src/driver/ili9341/ili9341_STM32_Driver.cyclo ./Core/Src/driver/ili9341/ili9341_STM32_Driver.d ./Core/Src/driver/ili9341/ili9341_STM32_Driver.o ./Core/Src/driver/ili9341/ili9341_STM32_Driver.su

.PHONY: clean-Core-2f-Src-2f-driver-2f-ili9341

