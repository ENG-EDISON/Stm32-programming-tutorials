################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
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
EXECUTABLES += \
GPIO_READING_INPUT_BARE_METAL.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
GPIO_READING_INPUT_BARE_METAL.list \

OBJCOPY_BIN += \
GPIO_READING_INPUT_BARE_METAL.bin \


# All Target
all: GPIO_READING_INPUT_BARE_METAL.elf secondary-outputs

# Tool invocations
GPIO_READING_INPUT_BARE_METAL.elf: $(OBJS) $(USER_OBJS) C:\Users\USER\STM32CubeIDE\workspace_1.2.0\GPIO_READING_INPUT_BARE_METAL\STM32F446RETX_FLASH.ld
	arm-none-eabi-gcc -o "GPIO_READING_INPUT_BARE_METAL.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\USER\STM32CubeIDE\workspace_1.2.0\GPIO_READING_INPUT_BARE_METAL\STM32F446RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="GPIO_READING_INPUT_BARE_METAL.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

GPIO_READING_INPUT_BARE_METAL.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "GPIO_READING_INPUT_BARE_METAL.list"
	@echo 'Finished building: $@'
	@echo ' '

GPIO_READING_INPUT_BARE_METAL.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "GPIO_READING_INPUT_BARE_METAL.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
