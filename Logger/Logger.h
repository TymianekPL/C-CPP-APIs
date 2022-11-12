#ifndef LOGGER_H
#define LOGGER_H

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

#endif
