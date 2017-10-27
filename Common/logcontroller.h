#ifndef LOGCONTROLLER_H
#define LOGCONTROLLER_H


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

#endif // LOGCONTROLLER_H
