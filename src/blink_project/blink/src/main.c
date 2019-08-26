#include <Arduino.h>

// 定义 LED 引脚
#define PIN_LED 2
// 定义间隔时间，以毫秒为单位
#define TIME_DELAY_MILLISEC 1000

void setup()
{
    // 设置数字IO口2为输出
    pinMode(PIN_LED, OUTPUT);
    // 初始状态为关闭
    digitalWrite(PIN_LED, LOW);
}

void loop()
{
    // 输出高电平
    digitalWrite(PIN_LED, HIGH);
    // 等待
    delay(TIME_DELAY_MILLISEC);
    // 输出低电平
    digitalWrite(PIN_LED, LOW);
    // 等待
    delay(TIME_DELAY_MILLISEC);
}