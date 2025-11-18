#include "logger.h"

#include "zephyr_logger.h"

void Logger_init() {
  ZephyrLogger_init();
  ULOG_INIT();
  ULOG_SUBSCRIBE(ZephyrLogger_send, ULOG_DEBUG_LEVEL);
}
