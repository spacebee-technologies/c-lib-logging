#include "logger.h"

#include "zephyr_logger.h"

void Logger_init(LoggerLevel_t level) {
  ZephyrLogger_init();
  ULOG_INIT();

  ulog_level_t ulogLevel;
  switch (level) {
    case LOGGER_LEVEL_DEBUG:
      ulogLevel = ULOG_DEBUG_LEVEL;
      break;
    case LOGGER_LEVEL_INFO:
      ulogLevel = ULOG_INFO_LEVEL;
      break;
    case LOGGER_LEVEL_WARN:
      ulogLevel = ULOG_WARNING_LEVEL;
      break;
    case LOGGER_LEVEL_ERROR:
      ulogLevel = ULOG_ERROR_LEVEL;
      break;
    default:
      ulogLevel = ULOG_DEBUG_LEVEL;
  }

  ULOG_SUBSCRIBE(ZephyrLogger_send, ulogLevel);
}
