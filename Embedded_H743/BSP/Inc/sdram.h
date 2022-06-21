#ifndef _H743_SDRAM_H
#define _H743_SDRAM_H

#include "main.h"

class sdram{

    SDRAM_HandleTypeDef *handle;

public:
    sdram();
    ~sdram();
    void send_commend(FMC_SDRAM_CommandTypeDef *Command,uint32_t Timeout);
    void precharge();
    void init();
    void getxxx();
};


#ifdef __cplusplus
extern "C"{
#endif

void SDRAM_Init(SDRAM_HandleTypeDef *handle);

#ifdef __cplusplus
}
#endif

#endif
