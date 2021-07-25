SET PATH=C:\Keil_v5\ARM\ARMCC\Bin;C:\Program Files (x86)\CUBEMX\;C:\Program Files (x86)\Common Files\Oracle\Java\javapath;C:\WINDOWS\system32;C:\WINDOWS;C:\WINDOWS\System32\Wbem;C:\WINDOWS\System32\WindowsPowerShell\v1.0\;C:\WINDOWS\System32\OpenSSH\;C:\Program Files\Polyspace\R2020a\runtime\win64;C:\Program Files\Polyspace\R2020a\bin;C:\Program Files\Polyspace\R2020a\polyspace\bin;C:\Program Files\Git\cmd;C:\yagarto-20121222\bin;C:\Program Files (x86)\STMicroelectronics\STM32 ST-LINK Utility\ST-LINK Utility;C:\Users\USER\AppData\Local\Microsoft\WindowsApps;C:\Users\USER\AppData\Local\Programs\Microsoft VS Code\bin;C:\Users\USER\AppData\Local\Programs\MiKTeX\miktex\bin\x64\;C:\Users\USER\AppData\Local\GitHubDesktop\bin;C:\Program Files\Java\jre1.8.0_271\bin
SET CPU_TYPE=STM32F401RETx
SET CPU_VENDOR=STMicroelectronics
SET UV2_TARGET=VARIABLE_DUTY_CYCLE_TUTORIAL
SET CPU_CLOCK=0x0501BD00
"C:\Keil_v5\ARM\ARMCC\Bin\ArmAsm" --Via "variable_duty_cycle_tutorial\startup_stm32f401xe._ia"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "variable_duty_cycle_tutorial\main.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "variable_duty_cycle_tutorial\stm32f4xx_it.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "variable_duty_cycle_tutorial\stm32f4xx_hal_msp.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "variable_duty_cycle_tutorial\stm32f4xx_hal_adc.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "variable_duty_cycle_tutorial\stm32f4xx_hal_adc_ex.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "variable_duty_cycle_tutorial\stm32f4xx_hal_rcc.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "variable_duty_cycle_tutorial\stm32f4xx_hal_rcc_ex.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "variable_duty_cycle_tutorial\stm32f4xx_hal_flash.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "variable_duty_cycle_tutorial\stm32f4xx_hal_flash_ex.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "variable_duty_cycle_tutorial\stm32f4xx_hal_flash_ramfunc.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "variable_duty_cycle_tutorial\stm32f4xx_hal_gpio.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "variable_duty_cycle_tutorial\stm32f4xx_hal_dma_ex.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "variable_duty_cycle_tutorial\stm32f4xx_hal_dma.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "variable_duty_cycle_tutorial\stm32f4xx_hal_pwr.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "variable_duty_cycle_tutorial\stm32f4xx_hal_pwr_ex.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "variable_duty_cycle_tutorial\stm32f4xx_hal_cortex.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "variable_duty_cycle_tutorial\stm32f4xx_hal.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "variable_duty_cycle_tutorial\stm32f4xx_hal_exti.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "variable_duty_cycle_tutorial\stm32f4xx_hal_tim.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "variable_duty_cycle_tutorial\stm32f4xx_hal_tim_ex.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "variable_duty_cycle_tutorial\system_stm32f4xx.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmLink" --Via "VARIABLE_DUTY_CYCLE_TUTORIAL\VARIABLE_DUTY_CYCLE_TUTORIAL.lnp"
"C:\Keil_v5\ARM\ARMCC\Bin\fromelf.exe" "VARIABLE_DUTY_CYCLE_TUTORIAL\VARIABLE_DUTY_CYCLE_TUTORIAL.axf" --i32combined --output "VARIABLE_DUTY_CYCLE_TUTORIAL\VARIABLE_DUTY_CYCLE_TUTORIAL.hex"
