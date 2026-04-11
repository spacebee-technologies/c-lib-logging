#ifndef LOGGER_H_
#define LOGGER_H_

#include "ulog.h"

#define LOG_INIT Logger_init
#define LOG_DEBUG ULOG_DEBUG
#define LOG_INFO ULOG_INFO
#define LOG_WARN ULOG_WARN
#define LOG_ERROR ULOG_ERROR

typedef enum {
  LOGGER_LEVEL_DEBUG,
  LOGGER_LEVEL_INFO,
  LOGGER_LEVEL_WARN,
  LOGGER_LEVEL_ERROR,
} LoggerLevel_t;

void Logger_init(LoggerLevel_t level);

#endif  // LOGGER_H_
