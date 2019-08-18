#include <Arduino.h>

bool isShutdownRequested = false;
bool isStartupRequested = false;

void setup()
{
    // 这里写初始化代码
}

void loop()
{
    // 这里写要被一直执行的代码

    if (isShutdownRequested) // 检查是否请求开机
    {
        while (1)
        {
            if (isStartupRequested) // 检查是否请求开机
            {
                isStartupRequested = false;
                isShutdownRequested = false;
                setup();
                break;
            }
        }
    }
}