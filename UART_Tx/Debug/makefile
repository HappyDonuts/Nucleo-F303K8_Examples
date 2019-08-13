################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include startup/subdir.mk
-include Src/subdir.mk
-include Drivers/STM32F3xx_HAL_Driver/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
UART_Tx.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
UART_Tx.list \


# All Target
all: UART_Tx.elf secondary-outputs

# Tool invocations
UART_Tx.elf: $(OBJS) $(USER_OBJS) ../STM32F303K8_FLASH.ld
	arm-none-eabi-gcc -o "UART_Tx.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"../STM32F303K8_FLASH.ld" --specs=nosys.specs -Wl,-Map="UART_Tx.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

UART_Tx.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "UART_Tx.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	arm-none-eabi-objcopy.exe -O ihex "UART_Tx.elf" "UART_Tx.hex"
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
