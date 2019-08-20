# Arduino 简明教程
## 第0章: 摘要
嵌入式系统已经在我们的生活中占有越来越重要的地位。小到手表，大到汽车，都使用了嵌入式系统。嵌入式系统的典型实现大量使用了单片机系统。学习单片机是创造智能硬件的简单方式，是深入了解计算机底层设计的捷径。在海量单片机系统中，Arduino 是一种经典。相比于树莓派等完备的片上系统(SoC)和51等仅具有低级抽象的单片机而言，Arduino 在保证低成本、低功耗的基础上支持 C++ 的高级抽象，同时又不失灵活性，具有极大优势，是单片机初学者理想的学习目标。

在本场 Chat 中，将会讲解以下内容：

* 关于 Arduino 的基础知识
* 控制流
* C 库函数和 Arduino 库函数
* 扩展卡与外围硬件
* 扩展库使用与编写
* 中断，并发与原子性
* 网络编程
* 通信协议
	* 串口
	* I2C 总线
	* OneWire 总线
* 持久性存储
* Arduino 底层编程
* ...

**适合人群：** 希望快速入门并掌握单片机基本原理，而又不想花费太多时间、金钱的人士；或是想要将自己的智创想法快速变成现实、获得他人认可的学生

## 第1章 什么是 Arduino
### 1.0 导语
在这一章中，我们将会看到一些前置知识，包括历史与不同 Arduino 板的型号对比。了解这些知识对之后的学习有非常大的帮助。

### 1.1 Arduino 的历史
时间回到2016年。专业研发微控制器的**安特梅尔** (Atmel) 公司刚刚被微芯科技公司 (Microchip Technology) 收购[1]，其旗下的ATmega系列微处理器同时归到微芯科技公司门下。本世纪初，最流行的单片机是Intel 8051系列，包括STM89，AT89等系列，统称为**51单片机**。51单片机由于其极低功耗和C语言工具链而被广泛应用于各项产品。然而，在2003年，采用ATmega系列芯片的初代 **Arduino** 及其 **avr-gcc** 工具链发布后，其与51单片机媲美的功耗以及“让非工程师构建数字项目”的目标吸引了大批用户。到2013年，已有多达700,000块官方发布的 Arduino 被使用[2]。

之后，使用不同芯片的 Arduino 被制造出来。2017年， Arduino 与 ARM Holdings 签署合作伙伴协议[3]，发布使用 ARM 构架的 Arduino 开发板 Arduino Yun 以及其他型号。

### 1.2 Arduino 板的结构及型号
Arduino 板是对于 ATmega/ARM 系列芯片的再封装，加入了 USB 控制器、晶振、稳压器、编程接口等外围设备。根据所封装芯片型号以及用途不同，Arduino 板分为多个型号。如下的表格列出了部分官方发布的 Arduino 板的名称、处理器和尺寸等信息[4]。

<table>
    <thead>
        <tr>
            <th>开发板名称</th>
            <th>处理器</th>
            <th>长度</th>
            <th>宽度</th>
            <th>电压</th>
            <th>时钟速度</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>Arduino Yún</td>
            <td>ATmega32U4, Atheros AR9331</td>
            <td>68.6mm</td>
            <td>53.3mm</td>
            <td>5V</td>
            <td>16MHz, 400MHz</td>
        </tr>
        <tr>
            <td>Arduino/Genuino UNO Revision 3</td>
            <td>ATmega328P</td>
            <td>68.6mm</td>
            <td>53.4mm</td>
            <td>5V</td>
            <td>16MHz</td>
        </tr>
        <tr>
            <td>Arduino/Genuino MEGA 2560</td>
            <td>ATmega2560</td>
            <td>101.52mm</td>
            <td>53.3mm</td>
            <td>5V</td>
            <td>16MHz</td>
        </tr>
        <tr>
            <td>Arduino/Genuino 101</td>
            <td>Intel® Curie™ 模块，包含一个 x86 (Quark SE) 和一个 ARC</td>
            <td>68.6mm</td>
            <td>53.4mm</td>
            <td>3.3V</td>
            <td>32MHz</td>
        </tr>
        <tr>
            <td>Arduino/Genuino Zero</td>
            <td>ATSAMD21G18A</td>
            <td>68.6mm</td>
            <td>53.3mm</td>
            <td>3.3V</td>
            <td>48MHz</td>
        </tr>
        <tr>
            <td>Arduino Due</td>
            <td>ATSAM3X8E (Cortex-M3)</td>
            <td>101.6mm</td>
            <td>53.3mm</td>
            <td>3.3V</td>
            <td>84MHz</td>
        </tr>
    </tbody>
</table>

为了方便讨论，我们以 **Arduino/Genuino UNO Revision 3** 作为本 Chat 中默认使用的 Arduino 板，因为它是最简单、最适合初学者学习的 Arduino 板型号。 **如果没有特殊声明，本 Chat 之后所提到的 Arduino 板均指 Arduino/Genuino UNO Revision 3。**

> **旁注：Arduino 和 Genuino**

> 实际上， Arduino 和 Genuino 是指同一种产品---即 Arduino---的不同商标。这个差别源自2008年的一次纠纷。
> 2008年上半年，Massimo Banzi，David Cuartielles，Tom Igoe，Gianluca Martino 和 David Mellis 创建了 Arduino LLC 公司，共同持有在美国注册的 Arduino 商标。但是在2008年末，Gianluca Martino 的公司在未告知其他四位创始人的情况下在意大利注册了 Arduino 商标。其他四位创始人发现后，他们试图说服 Gianluca 将商标权归还，但他们没有成功。Gianluca 的公司随后指派了一位新 CEO，分裂了 Arduino LLC，将新公司命名为 Arduino SRL。于是，Arduino LLC 只好将美国外的商标更名为 Genuino [5]。

### 第1章参考资料
1. *Wikipedia*. "Atmel"[DB/OL]. (https://en.wikipedia.org/wiki/Atmel), 访问日期 2019-08-17
2. *Malmö University*. "Arduino FAQ – With David Cuartielles"[J/OL]. (http://medea.mah.se/2013/04/arduino-faq/), 2013-08-05, 访问日期 2019-08-17
3. *Electronics Weekly*. "Arduino reborn partners with ARM"[J/OL]. (https://www.electronicsweekly.com/blogs/distribution-world/arduino-reborn-partners-arm-2017-10/), 2017-10-06. 访问日期 2019-08-17
4. *Wikipedia*. "List of Arduino boards and compatible systems"[DB/OL]. (https://en.wikipedia.org/wiki/List_of_Arduino_boards_and_compatible_systems), 访问日期 2019-08-17
5. *Wikipedia*. "Arduino"[DB/OL]. (https://en.wikipedia.org/wiki/Arduino), 访问日期 2019-08-20

## 第2章 Arduino UNO 基础知识
### 2.0 导语
在本章中，我们将介绍关于 Arduino UNO 的有关知识，包括硬件构成以及所需要的软件。要注意，尽管这一章介绍的是 Arduino UNO，但是这些结论都是可以推广到其他 Arduino 板上的。当后面的讨论中提及本章概念时，我们将假设读者已经理解了它们。

### 2.1 硬件结构
TODO

### 2.2 软件需求
#### 电路设计
TODO

#### 编程
TODO

### 第2章参考资料
TODO

## 第3章 快速上手：一个 Blink 项目
### 3.0 导语
在本章中，我们会构建一个简单的 Blink 项目，充当‘Hello World’的角色，该项目使一盏 LED 灯闪烁。在本章中，我们只对这个项目中出现的各项细节做粗略讲解，因为该章的主要目的是向读者介绍一个典型 Arduino 项目的开发周期及流程。这意味着完全可以跳过该章，但跟着该章的步伐构建 Blink 项目能让读者更好地体会什么是现实中的 Arduino 编程。

**项目目标：**使一盏 LED 灯以固定间隔闪烁。

### 3.1 硬件设计
在构建一个 Arduino 项目前，我们首先应该考虑硬件设计，因为程序控制硬件，只有确定了硬件才能编写健壮的代码。回顾我们的项目目标（使一盏 LED 灯以固定间隔闪烁），我们发现该项目至少需要以下硬件：

* 1块 Arduino 板，作为**控制器** (Controller)
* 1个 LED 灯，颜色随意（建议用红色，醒目），作为**执行器** (Actuator)

经过查阅关于 LED 的资料得知，LED 需要一个电阻才能正常发光[1]，再加上辅助材料（线材等），完整的用料清单如下：

* 1块 Arduino 板，作为控制器
* 1个 LED 灯，作为执行器
* 1个 电阻，约为200欧
* 若干 线材

我们将用 Arduino 板上的数字I/O端口`2`来控制 LED 灯。由于数字I/O端口可以输出 0V 和 5V 电压并且 LED 灯耗能极少，我们将直接使用它驱动灯管。综上所述，我们只需要**将 LED 灯和电阻串联接至数字I/O口`2`**即可。

使用 Fritzing 绘制的电路图如下。

![实物图](https://raw.githubusercontent.com/CSharperMantle/arduino_intro/master/assets/blink_project/circuit_bb.png)
![原理图](https://raw.githubusercontent.com/CSharperMantle/arduino_intro/master/assets/blink_project/circuit_image.png)

### 3.2 软件设计
TODO

###第三章参考资料
1. *Wikipedia*. "Light-emitting diode"[DB/OL]. (https://en.wikipedia.org/wiki/Light-emitting_diode), 访问日期 2019-08-20

## 第4章 Arduino 编程基础
### 4.0 导语
TODO

### Arduino 使用的 C++ 语言

### 4.2 Arduino Sketch
一段能被烧录到 Arduino 板上并被执行的代码称为 **Arduino Sketch** [1]。这样的代码我们已经看到过了。一个最小的 Arduino Sketch 包含以下内容：
```c
// src/sketching/minimal_sketch.c
#include <Arduino.h>

void setup()
{
    // 这里写只执行一次的代码
}

void loop()
{
    // 这里写要被一直执行的代码
}
```

其中，`setup()` 与 `loop()` 函数原型如下：
```c
// Arduino.h

void setup(void);
void loop(void);
```

这两个函数构成了 Arduino 基本控制流。当 Arduino 板加电或重置时，将首先运行`setup()` 中的代码，**只运行一次**。编译器希望用户将 Arduino 板的初始化操作放在这里，这也是其取名为“setup” (设置) 的原因。它也可以被认为是入口点`main()`[2] -- 如果你学习过 C 或 C++ 之类语言的话。

`setup()` 返回之后，Arduino 板会**迭代地调用`loop()`**，直到断电或重置。如果你学习过 C 之类语言的话，该函数的执行路径类似于以下代码：
```c
while (1) // 死循环
{
    loop(); // 无限调用loop() 函数
}
```

一般来说，我们只需要上述最小 Arduino Sketch 就可以完成大量工作。但是也可以有以下更高级的 Sketch，其支持使 Arduino 板在空闲与工作中切换,实现“软关机”。
```c
// src/sketching/shutdownable_sketch.c
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

    if (isShutdownRequested) // 检查是否请求关机
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
```

在上述 Sketch 中，当用户将`isShutdownRequested`设为`true`时，即可进入空闲状态(死循环)，直到将`isStartupRequested`置为`true`， Arduino 板再次调用`setup()`初始化，退出死循环。

### 第4章参考资料
1. "Programming Arduino Getting Started with Sketches"[M]. 美国:McGraw-Hills教育, 2011.
2. *Arduino Reference*. "setup()"[DB/OL]. (https://www.arduino.cc/reference/en/language/structure/sketch/setup/), 访问日期 2019-08-18
3. *Arduino Reference*. "loop()"[DB/OL]. (https://www.arduino.cc/reference/en/language/structure/sketch/loop/), 访问日期 2019-08-18