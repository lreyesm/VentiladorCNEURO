#include "checkserialmessage.h"
#include "ieee_754_class.h"

CheckSerialMessage::CheckSerialMessage()
{

}

void CheckSerialMessage::fillVariables(){


}

void CheckSerialMessage::convertUint32ToUintArray(uint32_t crcValue, uint8_t* buf_8b){
    for (int i=0; i<4 ;++i){
        buf_8b[i] = ((uint8_t*)(&crcValue))[3-i];
    }
}

bool CheckSerialMessage::checkMessage(uint8_t * dataReceived){

    uint8_t buf_8b[4];
    uint32_t crcValue = crc32(dataReceived, UART_READ_BUFFER_SIZE);

    for (int i=0; i<4 ;++i){
        buf_8b[i] = ((uint8_t*)(&crcValue))[3-i];
    }
    IEEE_754_class::changeEndianess(buf_8b);

    for (int i=0; i<4 ;++i){
        if(dataReceived[i+UART_READ_BUFFER_SIZE] != buf_8b[i]){
            return false;//Error de check_sum solicitar reenvio
        }
    }
    for(int i=HEADER_START_POS; i < HEADER_SIZE; i++){
        if(dataReceived[i] != HEADER_ID){
            return false;//Error de cabecera solicitar reenvio
        }
    }
    return true;
}

uint32_t CheckSerialMessage::crc32(uint8_t* ptr, uint32_t size)
{
    const unsigned long crc_table[16] = {
        0x00000000, 0x1db71064, 0x3b6e20c8, 0x26d930ac,
        0x76dc4190, 0x6b6b51f4, 0x4db26158, 0x5005713c,
        0xedb88320, 0xf00f9344, 0xd6d6a3e8, 0xcb61b38c,
        0x9b64c2b0, 0x86d3d2d4, 0xa00ae278, 0xbdbdf21c
    };

    unsigned long crc = ~0L;

    for (int index = 0 ; index < size  ; ++index) {
        crc = crc_table[(crc ^ ptr[index]) & 0x0f] ^ (crc >> 4);
        crc = crc_table[(crc ^ (ptr[index] >> 4)) & 0x0f] ^ (crc >> 4);
        crc = ~crc;
    }
    return crc;
}
