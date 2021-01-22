#ifndef CHECKSERIALMESSAGE_H
#define CHECKSERIALMESSAGE_H

#include "stdint.h"

#ifndef UART_READ_TOTAL_SIZE //// 1 word Header (4 bytes) + 18 word Info (72 bytes) + 100 words 32 bits (400 bytes) + 1 word CRC (4 bytes)
#define UART_READ_TOTAL_SIZE 484
#endif

#define CHECK_CRC_SIZE 4
#define UART_READ_BUFFER_SIZE  UART_READ_TOTAL_SIZE - CHECK_CRC_SIZE //// 1 word Header (4 bytes) + 7 word Info (28 bytes) + 100 words 32 bits (400 bytes) - 1 word CRC (4 bytes)
#define UART_READ_DATA_FUNCTION_SIZE 50 ////100 words 32 bits (400 bytes)
#define HOLDING_BUFFERS_TO_WRITE_IN_FILE 10

#define UART_SEND_TO_ARDUINO_SIZE 92

#define HEADER_START_POS 0
#define HEADER_SIZE 4
#define HEADER_ID 0xAA
#define ERROR_ID 0x00

#define WORD_SIZE_BYTES 4
#define RESPUESTA_POS WORD_SIZE_BYTES * 1
#define ALIMENTACION_POS WORD_SIZE_BYTES * 2
#define ESTADO_BATERIA_POS WORD_SIZE_BYTES * 3
#define ALARMAS_POS WORD_SIZE_BYTES * 4
#define PIP_POS WORD_SIZE_BYTES * 5
#define PPLAT_POS WORD_SIZE_BYTES * 6
#define PEEP_POS WORD_SIZE_BYTES * 7

#define CMD_STATE_CLOCK_POS WORD_SIZE_BYTES * 8  ///(0-Omitir)  (1-SETEAR desde Arduino (Sin Error))  (2-Error)  (3-SETEAR desde Arduino (Error))
#define SECONDS_CLOCK_POS WORD_SIZE_BYTES * 9
#define MINUTES_CLOCK_POS WORD_SIZE_BYTES * 10
#define HOUR_CLOCK_POS WORD_SIZE_BYTES * 11
#define DAY_CLOCK_POS WORD_SIZE_BYTES * 12
#define MONTH_CLOCK_POS WORD_SIZE_BYTES * 13
#define YEAR_CLOCK_POS WORD_SIZE_BYTES * 14
#define VOLUMEN_REAL_POS WORD_SIZE_BYTES * 15
#define BPM_REAL_POS WORD_SIZE_BYTES * 16
#define COMPLIANCE WORD_SIZE_BYTES * 17
#define FIO2_POS WORD_SIZE_BYTES * 18
#define ETCO2_POS WORD_SIZE_BYTES * 19

#define BUFFER_DATA_POS WORD_SIZE_BYTES * 20

class CheckSerialMessage
{
public:
    CheckSerialMessage();
    static bool checkMessage(uint8_t *dataReceived);
    static uint32_t crc32(uint8_t *ptr, uint32_t size);
    static void convertUint32ToUintArray(uint32_t crcValue, uint8_t *buf_8b);
private:
    void fillVariables();
};

#endif // CHECKSERIALMESSAGE_H
