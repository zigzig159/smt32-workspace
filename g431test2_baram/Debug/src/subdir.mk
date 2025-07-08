################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c 

OBJS += \
./src/main.o 

C_DEPS += \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o src/%.su src/%.cyclo: ../src/%.c src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -c -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/g431test2_baram/src" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/g431test2_baram/src/ap" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/g431test2_baram/src/bsp" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/g431test2_baram/src/common" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/g431test2_baram/src/hw" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/g431test2_baram/src/lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-src

clean-src:
	-$(RM) ./src/main.cyclo ./src/main.d ./src/main.o ./src/main.su

.PHONY: clean-src

