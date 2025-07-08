################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/usbd_cdc.c 

OBJS += \
./src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/usbd_cdc.o 

C_DEPS += \
./src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/usbd_cdc.d 


# Each subdirectory must supply rules for building sources it contributes
src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/%.o src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/%.su src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/%.cyclo: ../src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/%.c src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xB -c -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/f103_fw_ex/src/lib/f103_fw_ex/Core/Inc" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/f103_fw_ex/src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/f103_fw_ex/src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/f103_fw_ex/src/lib/f103_fw_ex/USB_DEVICE/App" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/f103_fw_ex/src/lib/f103_fw_ex/USB_DEVICE/Target" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/f103_fw_ex/src/hw/include" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/f103_fw_ex/src/lib/f103_fw_ex/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/f103_fw_ex/src/lib/f103_fw_ex/Drivers/STM32F1xx_HAL_Driver/Inc" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/f103_fw_ex/src/lib/f103_fw_ex/Drivers/CMSIS/Include" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/f103_fw_ex/src" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/f103_fw_ex/src/ap" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/f103_fw_ex/src/bsp" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/f103_fw_ex/src/common" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/f103_fw_ex/src/hw" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/f103_fw_ex/src/lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-src-2f-lib-2f-f103_fw_ex-2f-Middlewares-2f-ST-2f-STM32_USB_Device_Library-2f-Class-2f-CDC-2f-Src

clean-src-2f-lib-2f-f103_fw_ex-2f-Middlewares-2f-ST-2f-STM32_USB_Device_Library-2f-Class-2f-CDC-2f-Src:
	-$(RM) ./src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/usbd_cdc.cyclo ./src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/usbd_cdc.d ./src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/usbd_cdc.o ./src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/usbd_cdc.su

.PHONY: clean-src-2f-lib-2f-f103_fw_ex-2f-Middlewares-2f-ST-2f-STM32_USB_Device_Library-2f-Class-2f-CDC-2f-Src

