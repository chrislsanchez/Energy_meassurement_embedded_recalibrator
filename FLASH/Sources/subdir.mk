################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/MCUinit.c" \
"../Sources/Teclado.c" \
"../Sources/UART_routines.c" \
"../Sources/Zigbee.c" \
"../Sources/funciones.c" \
"../Sources/main.c" \
"../Sources/menu.c" \
"../Sources/nokia1100_lcd_lib.c" \

C_SRCS += \
../Sources/MCUinit.c \
../Sources/Teclado.c \
../Sources/UART_routines.c \
../Sources/Zigbee.c \
../Sources/funciones.c \
../Sources/main.c \
../Sources/menu.c \
../Sources/nokia1100_lcd_lib.c \

OBJS += \
./Sources/MCUinit_c.obj \
./Sources/Teclado_c.obj \
./Sources/UART_routines_c.obj \
./Sources/Zigbee_c.obj \
./Sources/funciones_c.obj \
./Sources/main_c.obj \
./Sources/menu_c.obj \
./Sources/nokia1100_lcd_lib_c.obj \

OBJS_QUOTED += \
"./Sources/MCUinit_c.obj" \
"./Sources/Teclado_c.obj" \
"./Sources/UART_routines_c.obj" \
"./Sources/Zigbee_c.obj" \
"./Sources/funciones_c.obj" \
"./Sources/main_c.obj" \
"./Sources/menu_c.obj" \
"./Sources/nokia1100_lcd_lib_c.obj" \

C_DEPS += \
./Sources/MCUinit_c.d \
./Sources/Teclado_c.d \
./Sources/UART_routines_c.d \
./Sources/Zigbee_c.d \
./Sources/funciones_c.d \
./Sources/main_c.d \
./Sources/menu_c.d \
./Sources/nokia1100_lcd_lib_c.d \

C_DEPS_QUOTED += \
"./Sources/MCUinit_c.d" \
"./Sources/Teclado_c.d" \
"./Sources/UART_routines_c.d" \
"./Sources/Zigbee_c.d" \
"./Sources/funciones_c.d" \
"./Sources/main_c.d" \
"./Sources/menu_c.d" \
"./Sources/nokia1100_lcd_lib_c.d" \

OBJS_OS_FORMAT += \
./Sources/MCUinit_c.obj \
./Sources/Teclado_c.obj \
./Sources/UART_routines_c.obj \
./Sources/Zigbee_c.obj \
./Sources/funciones_c.obj \
./Sources/main_c.obj \
./Sources/menu_c.obj \
./Sources/nokia1100_lcd_lib_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/MCUinit_c.obj: ../Sources/MCUinit.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/MCUinit.args" -ObjN="Sources/MCUinit_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/Teclado_c.obj: ../Sources/Teclado.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/Teclado.args" -ObjN="Sources/Teclado_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/UART_routines_c.obj: ../Sources/UART_routines.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/UART_routines.args" -ObjN="Sources/UART_routines_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/Zigbee_c.obj: ../Sources/Zigbee.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/Zigbee.args" -ObjN="Sources/Zigbee_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/funciones_c.obj: ../Sources/funciones.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/funciones.args" -ObjN="Sources/funciones_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/main_c.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/main.args" -ObjN="Sources/main_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/menu_c.obj: ../Sources/menu.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/menu.args" -ObjN="Sources/menu_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/nokia1100_lcd_lib_c.obj: ../Sources/nokia1100_lcd_lib.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/nokia1100_lcd_lib.args" -ObjN="Sources/nokia1100_lcd_lib_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '


