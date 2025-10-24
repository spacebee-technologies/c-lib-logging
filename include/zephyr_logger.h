#ifndef ZEPHYR_LOGGER_H_
#define ZEPHYR_LOGGER_H_

#include "ulog.h"

void ZephyrLogger_init();
void ZephyrLogger_send(ulog_level_t severity, char *msg);

#endif  // ZEPHYR_LOGGER_H_
