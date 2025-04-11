#include "cklhmibsp.h"

CklHmiBsp::CklHmiBsp()
{
}

CklHmiBsp::~CklHmiBsp()
{
}

void CklHmiBsp::echo()
{
    std::cout << "Hello, world!" << std::endl;
}

// 创建 CklHmiBsp 对象
extern "C" void* createCklHmiBsp() {
    return new CklHmiBsp();
}

// 调用 CklHmiBsp 对象的 echo 方法
extern "C" void callCklHmiBspEcho(void* obj) {
    CklHmiBsp* bsp = static_cast<CklHmiBsp*>(obj);
    if (bsp) {
        bsp->echo();
    }
}

// 销毁 CklHmiBsp 对象
extern "C" void destroyCklHmiBsp(void* obj) {
    delete static_cast<CklHmiBsp*>(obj);
}    