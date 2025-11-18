#ifndef LOGGER_H_
#define LOGGER_H_

#include "ulog.h"

#define LOG_INIT Logger_init
#define LOG_DEBUG ULOG_DEBUG
#define LOG_INFO ULOG_INFO
#define LOG_WARN ULOG_WARN
#define LOG_ERROR ULOG_ERROR

void Logger_init();

#endif  // LOGGER_H_
