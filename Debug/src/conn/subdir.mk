################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/conn/PracticalSocket.cpp \
../src/conn/TCPConnection.cpp 

OBJS += \
./src/conn/PracticalSocket.o \
./src/conn/TCPConnection.o 

CPP_DEPS += \
./src/conn/PracticalSocket.d \
./src/conn/TCPConnection.d 


# Each subdirectory must supply rules for building sources it contributes
src/conn/%.o: ../src/conn/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/cem/workspace-ccpp/MessageDistributor/src/conn" -I"/home/cem/workspace-ccpp/MessageDistributor/src/main" -I"/home/cem/workspace-ccpp/MessageDistributor/src/utils" -I"/home/cem/workspace-ccpp/MessageDistributor/src/json" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


