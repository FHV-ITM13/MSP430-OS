################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CMD_SRCS += \
../lnk_msp430g2553.cmd 

CFG_SRCS += \
../main.cfg 

C_SRCS += \
../main.c \
../scheduler.c 

OBJS += \
./main.obj \
./scheduler.obj 

C_DEPS += \
./main.pp \
./scheduler.pp 

GEN_MISC_DIRS += \
./configPkg/ 

GEN_CMDS += \
./configPkg/linker.cmd 

GEN_OPTS += \
./configPkg/compiler.opt 

GEN_FILES += \
./configPkg/linker.cmd \
./configPkg/compiler.opt 

GEN_FILES__QUOTED += \
"configPkg\linker.cmd" \
"configPkg\compiler.opt" 

GEN_MISC_DIRS__QUOTED += \
"configPkg\" 

C_DEPS__QUOTED += \
"main.pp" \
"scheduler.pp" 

OBJS__QUOTED += \
"main.obj" \
"scheduler.obj" 

C_SRCS__QUOTED += \
"../main.c" \
"../scheduler.c" 

GEN_CMDS__FLAG += \
-l"./configPkg/linker.cmd" 

GEN_OPTS__FLAG += \
--cmd_file="./configPkg/compiler.opt" 


