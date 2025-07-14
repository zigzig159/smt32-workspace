################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/driver/button.c \
../Core/driver/ssd1306.c \
../Core/driver/ssd1306_font.c \
../Core/driver/stepmotor.c 

OBJS += \
./Core/driver/button.o \
./Core/driver/ssd1306.o \
./Core/driver/ssd1306_font.o \
./Core/driver/stepmotor.o 

C_DEPS += \
./Core/driver/button.d \
./Core/driver/ssd1306.d \
./Core/driver/ssd1306_font.d \
./Core/driver/stepmotor.d 


# Each subdirectory must supply rules for building sources it contributes
Core/driver/%.o Core/driver/%.su Core/driver/%.cyclo: ../Core/driver/%.c Core/driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/f103_ssd1603/Core/driver" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/f103_ssd1603/Drivers" -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-driver

clean-Core-2f-driver:
	-$(RM) ./Core/driver/button.cyclo ./Core/driver/button.d ./Core/driver/button.o ./Core/driver/button.su ./Core/driver/ssd1306.cyclo ./Core/driver/ssd1306.d ./Core/driver/ssd1306.o ./Core/driver/ssd1306.su ./Core/driver/ssd1306_font.cyclo ./Core/driver/ssd1306_font.d ./Core/driver/ssd1306_font.o ./Core/driver/ssd1306_font.su ./Core/driver/stepmotor.cyclo ./Core/driver/stepmotor.d ./Core/driver/stepmotor.o ./Core/driver/stepmotor.su

.PHONY: clean-Core-2f-driver

