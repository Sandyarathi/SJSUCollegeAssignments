################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../srcHugeInteger/HugeInteger.cpp \
../srcHugeInteger/testHugeInteger.cpp 

OBJS += \
./srcHugeInteger/HugeInteger.o \
./srcHugeInteger/testHugeInteger.o 

CPP_DEPS += \
./srcHugeInteger/HugeInteger.d \
./srcHugeInteger/testHugeInteger.d 


# Each subdirectory must supply rules for building sources it contributes
srcHugeInteger/%.o: ../srcHugeInteger/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Applications/Xcode.app/Contents/Developer/usr --with-gxx-include-dir=/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.9.sdk/usr/include/c++/4.2.1" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


