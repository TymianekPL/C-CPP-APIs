#include "Logger.h"
#include <stdio.h>

void logger_info(const char* tag, char *message)
{
    printf("[\x1B[1m\x1B[36m%s/Info\x1B[22m\x1B[0m] %s", tag, message);
}

void logger_warn(const char* tag, char* message)
{
    printf("[\x1B[1m\x1B[33m%s/Warn\x1B[22m\x1B[0m] %s\n", tag, message);
}

void logger_error(const char* tag, char* message)
{
    printf("[\x1B[1m\x1B[31m%s/Error\x1B[22m\x1B[0m] %s\n", tag, message);
}
