#ifndef GLOBALDEFINE_H
#define GLOBALDEFINE_H

#define INFO_NETWORK_RECIVE_SHOW_BYTES 10

class LogController
{
public:
    static LogController& GetLogController();

    int logLevel() const;
    void setLogLevel(int logLevel);

private:
    LogController();
    LogController(const LogController &other) = delete;
    LogController& operator=(const LogController &other) = delete;

    int m_logLevel;
};

#endif // GLOBALDEFINE_H
