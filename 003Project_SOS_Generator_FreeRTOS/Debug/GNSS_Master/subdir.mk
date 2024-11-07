################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GNSS_Master/GNSS.c 

OBJS += \
./GNSS_Master/GNSS.o 

C_DEPS += \
./GNSS_Master/GNSS.d 


# Each subdirectory must supply rules for building sources it contributes
GNSS_Master/%.o GNSS_Master/%.su GNSS_Master/%.cyclo: ../GNSS_Master/%.c GNSS_Master/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/Users/ILKER KESER/STM32CubeIDE/Target Projects/003Project_SOS_Generator_FreeRTOS/GNSS_Master" -I"C:/Users/ILKER KESER/STM32CubeIDE/Target Projects/003Project_SOS_Generator_FreeRTOS/Morse_Alphabet" -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-GNSS_Master

clean-GNSS_Master:
	-$(RM) ./GNSS_Master/GNSS.cyclo ./GNSS_Master/GNSS.d ./GNSS_Master/GNSS.o ./GNSS_Master/GNSS.su

.PHONY: clean-GNSS_Master

