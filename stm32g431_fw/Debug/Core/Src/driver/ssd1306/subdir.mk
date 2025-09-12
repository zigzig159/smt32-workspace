################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/driver/ssd1306/ssd1306.c \
../Core/Src/driver/ssd1306/ssd1306_font.c 

OBJS += \
./Core/Src/driver/ssd1306/ssd1306.o \
./Core/Src/driver/ssd1306/ssd1306_font.o 

C_DEPS += \
./Core/Src/driver/ssd1306/ssd1306.d \
./Core/Src/driver/ssd1306/ssd1306_font.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/driver/ssd1306/%.o Core/Src/driver/ssd1306/%.su Core/Src/driver/ssd1306/%.cyclo: ../Core/Src/driver/ssd1306/%.c Core/Src/driver/ssd1306/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/stm32g431_fw/Core/Src/driver/ssd1306" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/stm32g431_fw/Core/Src/driver/ili9341" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/stm32g431_fw/Core/Src/driver/st7789" -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-driver-2f-ssd1306

clean-Core-2f-Src-2f-driver-2f-ssd1306:
	-$(RM) ./Core/Src/driver/ssd1306/ssd1306.cyclo ./Core/Src/driver/ssd1306/ssd1306.d ./Core/Src/driver/ssd1306/ssd1306.o ./Core/Src/driver/ssd1306/ssd1306.su ./Core/Src/driver/ssd1306/ssd1306_font.cyclo ./Core/Src/driver/ssd1306/ssd1306_font.d ./Core/Src/driver/ssd1306/ssd1306_font.o ./Core/Src/driver/ssd1306/ssd1306_font.su

.PHONY: clean-Core-2f-Src-2f-driver-2f-ssd1306

