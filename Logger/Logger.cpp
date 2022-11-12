#include "Logger.h"
#include <iostream>

Logger::Logger(const char* tag)
{
    this->tag = tag;
}

Logger::~Logger()
{
}

void Logger::Info(char *message)
{
    std::cout << "[\x1B[1m\x1B[36mInfo\x1B[22m\x1B[0m] " << message << std::endl;
}

void Logger::Warn(char *message)
{
    std::cout << "[\x1B[1m\x1B[33mWarn\x1B[22m\x1B[0m] " << message << std::endl;
}

void Logger::Error(char *message)
{
    std::cout << "[\x1B[1m\x1B[31mError\x1B[22m\x1B[0m] " << message << std::endl;
}
