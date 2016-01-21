################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/secondWay/MesDist.cpp 

OBJS += \
./src/secondWay/MesDist.o 

CPP_DEPS += \
./src/secondWay/MesDist.d 


# Each subdirectory must supply rules for building sources it contributes
src/secondWay/%.o: ../src/secondWay/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/cem/workspace-ccpp/MessageDistributor/src/conn" -I"/home/cem/workspace-ccpp/MessageDistributor/src/main" -I"/home/cem/workspace-ccpp/MessageDistributor/src/utils" -I"/home/cem/workspace-ccpp/MessageDistributor/src/json" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


