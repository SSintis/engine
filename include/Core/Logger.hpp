#include <iostream>

class Logger
{
private:
    /* data */
public:
    Logger(/* args */);
    void sayHello();
    ~Logger();
};

Logger::Logger(/* args */)
{
}

void Logger::sayHello(){
    std::cout<<"hello\n";
}

Logger::~Logger()
{
}