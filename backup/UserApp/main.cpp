/*
 * CubeMX 重新生成工程后 CMakeList.txt会重置，需要重新添加一些参数设置
 * 一定注意要先更改设置后再Build工程！！
 *
 * CMake:->
 * 包含文件<file>: "UserApp/*.*" "DSP/*.*"
 * 头文件<include_directories>: DSP/Inc UserApp UserApp/Inc
 *
 * FreeRTOS:->
 * 如果使用了FreeRTOS,在CMakeLists.txt文件中找到
 * <#Uncomment for hardware floating point>, 取消注释下面的两条语句,
 * 注意：此时编译仍会报错。
 * 解决方法：
 *  删除 <add_definitions> 一行中的 "-D__FPU_PRESENT=1" 参数即可
 *
 * ARM DSP:->
 * Description of DSP library：https://arm-software.github.io/CMSIS_5/DSP/html/modules.html
 *
 */
#include "user.h"



void Main(){

    // SD Init

    // Screen Init

    // Main loop
    for(;;)
    {
        HAL_Delay(200);
    }

}



//The <void TimxCallbackxxHz()> function declaration is in the <stm32h7xx_it.c> file.
extern "C" void TimxCallbackxxHz(){

    // __HAL_TIM_CLEAR_IT(&htimx,TIM_IT_UPDATE);

    // do something ...
}


















