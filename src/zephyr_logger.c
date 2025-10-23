#include "zephyr_logger.h"

#include <stdio.h>
#include <string.h>

#include "zephyr_uart.h"
#include "zephyr_semaphore.h"

#define MAX_LOG_MSG_SIZE 128

ZephyrUart uart;
ZephyrSemaphore sem;

void ZephyrLogger_init() {
  ZephyrSemaphore_new(&sem);
  ZephyrUart_create(&uart, DEVICE_DT_GET(DT_CHOSEN(zephyr_shell_uart)),
                    ZephyrSemaphore_viewAsSemaphoreInterface(&sem));
  ZephyrUart_configure(&uart);
}

void ZephyrLogger_send(ulog_level_t severity, char *msg) {
  char logMsg[MAX_LOG_MSG_SIZE] = {0};
  sprintf(logMsg, "%lld [%s]: %s\n\r", k_uptime_get(), ulog_level_name(severity), msg);
  size_t messageLength = strlen(logMsg);
  uint8_t data[messageLength];
  for (int i = 0; i < messageLength; i++) {
    data[i] = logMsg[i];
  }
  data[messageLength] = 0;
  CommunicationInterface *interface = ZephyrUart_viewAsCommunicationInterface(&uart);
  CommunicationInterface_send(interface, data, messageLength);
}
