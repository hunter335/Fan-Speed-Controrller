################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Fan_Speed_Controller.lss \

FLASH_IMAGE += \
Fan_Speed_Controller.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Fan_Speed_Controller.elf secondary-outputs

# Tool invocations
Fan_Speed_Controller.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Fan_Speed_Controller.map -mmcu=atmega16 -o "Fan_Speed_Controller.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Fan_Speed_Controller.lss: Fan_Speed_Controller.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Fan_Speed_Controller.elf  >"Fan_Speed_Controller.lss"
	@echo 'Finished building: $@'
	@echo ' '

Fan_Speed_Controller.hex: Fan_Speed_Controller.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Fan_Speed_Controller.elf  "Fan_Speed_Controller.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Fan_Speed_Controller.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 Fan_Speed_Controller.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Fan_Speed_Controller.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
