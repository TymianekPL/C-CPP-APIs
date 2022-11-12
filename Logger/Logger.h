#ifndef LOGGER_H
#define LOGGER_H

#ifdef __cplusplus

class Logger
{
private:
    const char* tag;
public:
    Logger(const char* tag);
    ~Logger();

    void Info(char* message);
    void Warn(char* message);
    void Error(char* message);
};

#else // ! C++

void logger_info(const char* tag, char* message);

void logger_warn(const char* tag, char* message);

void logger_error(const char* tag, char* message);
#endif // ! C++

#endif
