#include "sdram.h"


void SDRAM_Init(SDRAM_HandleTypeDef *handle)
{
    // 给SDRAM提供时钟
    FMC_SDRAM_CommandTypeDef  Command;
    Command.CommandMode = FMC_SDRAM_CMD_CLK_ENABLE;
    Command.CommandTarget = FMC_SDRAM_CMD_TARGET_BANK2;
    Command.AutoRefreshNumber = 1;
    Command.ModeRegisterDefinition = 0;
    HAL_SDRAM_SendCommand(handle,&Command,0xffff);

    // 给SDRAM延迟至少200us
    HAL_Delay(2);

    // bank预充电
    Command.CommandMode = FMC_SDRAM_CMD_PALL;
    Command.CommandTarget = FMC_SDRAM_CMD_TARGET_BANK2;
    Command.AutoRefreshNumber = 1;
    Command.ModeRegisterDefinition = 0;
    HAL_SDRAM_SendCommand(handle,&Command,0xffff);

    // 插入8个自动刷新
    Command.CommandMode = FMC_SDRAM_CMD_AUTOREFRESH_MODE;
    Command.CommandTarget = FMC_SDRAM_CMD_TARGET_BANK2;
    Command.AutoRefreshNumber = 1;
    Command.ModeRegisterDefinition = 0;
    HAL_SDRAM_SendCommand(handle,&Command,0xffff);

    // 发鿁模式设置命仿
    Command.CommandMode = FMC_SDRAM_CMD_LOAD_MODE;
    Command.CommandTarget = FMC_SDRAM_CMD_TARGET_BANK2;
    Command.AutoRefreshNumber = 1;
    Command.ModeRegisterDefinition = 0x230;// 工作模式寄存器
    HAL_SDRAM_SendCommand(handle,&Command,0xffff);

    // SDRAM 自动刷新周期
    uint32_t refresh_rate  = round(604.8);//7.81us*80-20=604.8

    HAL_SDRAM_ProgramRefreshRate(handle,refresh_rate);//7.81us*80-20=604.8

}

void sdram::init()
{

}

void sdram::send_commend(FMC_SDRAM_CommandTypeDef *Command,uint32_t Timeout)
{
    HAL_SDRAM_SendCommand(this->handle,Command,Timeout);
}

void sdram::precharge()
{
    FMC_SDRAM_CommandTypeDef  Command;
    Command.CommandMode = FMC_SDRAM_CMD_PALL;
    Command.CommandTarget = FMC_SDRAM_CMD_TARGET_BANK2;
    Command.AutoRefreshNumber = 1;
    Command.ModeRegisterDefinition = 0;
    send_commend(&Command,0xffff);
}

void sdram::getxxx() {

}

sdram::~sdram() {

}

sdram::sdram() {

}

