#include "logcontroller.h"

LogController &LogController::GetLogController()
{
    static LogController logController;
    return logController;
}

LogController::LogController()
{
    m_logLevel = 0;
}

int LogController::logLevel() const
{
    return m_logLevel;
}

void LogController::setLogLevel(int logLevel)
{
    m_logLevel = logLevel;
}
