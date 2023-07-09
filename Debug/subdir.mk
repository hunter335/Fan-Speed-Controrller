################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DC_motor.c \
../LCD.c \
../LM35_sensor.c \
../adc.c \
../gpio.c \
../main.c \
../pwm.c 

OBJS += \
./DC_motor.o \
./LCD.o \
./LM35_sensor.o \
./adc.o \
./gpio.o \
./main.o \
./pwm.o 

C_DEPS += \
./DC_motor.d \
./LCD.d \
./LM35_sensor.d \
./adc.d \
./gpio.d \
./main.d \
./pwm.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


