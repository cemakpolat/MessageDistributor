################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/main/ConnectionObserver.cpp \
../src/main/Main.cpp \
../src/main/Message.cpp \
../src/main/MessageCreator.cpp \
../src/main/MessageDistributor.cpp \
../src/main/MessageHandler.cpp \
../src/main/MessageListener.cpp \
../src/main/MessageSender.cpp \
../src/main/User.cpp \
../src/main/UserNew.cpp 

OBJS += \
./src/main/ConnectionObserver.o \
./src/main/Main.o \
./src/main/Message.o \
./src/main/MessageCreator.o \
./src/main/MessageDistributor.o \
./src/main/MessageHandler.o \
./src/main/MessageListener.o \
./src/main/MessageSender.o \
./src/main/User.o \
./src/main/UserNew.o 

CPP_DEPS += \
./src/main/ConnectionObserver.d \
./src/main/Main.d \
./src/main/Message.d \
./src/main/MessageCreator.d \
./src/main/MessageDistributor.d \
./src/main/MessageHandler.d \
./src/main/MessageListener.d \
./src/main/MessageSender.d \
./src/main/User.d \
./src/main/UserNew.d 


# Each subdirectory must supply rules for building sources it contributes
src/main/%.o: ../src/main/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/cem/workspace-ccpp/MessageDistributor/src/conn" -I"/home/cem/workspace-ccpp/MessageDistributor/src/main" -I"/home/cem/workspace-ccpp/MessageDistributor/src/utils" -I"/home/cem/workspace-ccpp/MessageDistributor/src/json" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


