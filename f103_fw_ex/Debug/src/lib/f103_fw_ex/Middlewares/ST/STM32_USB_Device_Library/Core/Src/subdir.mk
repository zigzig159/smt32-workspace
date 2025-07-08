################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.c \
../src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.c \
../src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.c 

OBJS += \
./src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.o \
./src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.o \
./src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.o 

C_DEPS += \
./src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.d \
./src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.d \
./src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.d 


# Each subdirectory must supply rules for building sources it contributes
src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Core/Src/%.o src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Core/Src/%.su src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Core/Src/%.cyclo: ../src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Core/Src/%.c src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xB -c -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/f103_fw_ex/src/lib/f103_fw_ex/Core/Inc" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/f103_fw_ex/src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/f103_fw_ex/src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/f103_fw_ex/src/lib/f103_fw_ex/USB_DEVICE/App" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/f103_fw_ex/src/lib/f103_fw_ex/USB_DEVICE/Target" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/f103_fw_ex/src/hw/include" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/f103_fw_ex/src/lib/f103_fw_ex/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/f103_fw_ex/src/lib/f103_fw_ex/Drivers/STM32F1xx_HAL_Driver/Inc" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/f103_fw_ex/src/lib/f103_fw_ex/Drivers/CMSIS/Include" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/f103_fw_ex/src" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/f103_fw_ex/src/ap" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/f103_fw_ex/src/bsp" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/f103_fw_ex/src/common" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/f103_fw_ex/src/hw" -I"C:/Users/RND1/STM32CubeIDE/workspace_1.16.1/f103_fw_ex/src/lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-src-2f-lib-2f-f103_fw_ex-2f-Middlewares-2f-ST-2f-STM32_USB_Device_Library-2f-Core-2f-Src

clean-src-2f-lib-2f-f103_fw_ex-2f-Middlewares-2f-ST-2f-STM32_USB_Device_Library-2f-Core-2f-Src:
	-$(RM) ./src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.cyclo ./src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.d ./src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.o ./src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.su ./src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.cyclo ./src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.d ./src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.o ./src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.su ./src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.cyclo ./src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.d ./src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.o ./src/lib/f103_fw_ex/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.su

.PHONY: clean-src-2f-lib-2f-f103_fw_ex-2f-Middlewares-2f-ST-2f-STM32_USB_Device_Library-2f-Core-2f-Src

