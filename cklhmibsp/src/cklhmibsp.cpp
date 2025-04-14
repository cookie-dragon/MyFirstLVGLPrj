#include "cklhmibsp.h"

CklHmiBsp::CklHmiBsp()
{
}

CklHmiBsp::~CklHmiBsp()
{
}

void CklHmiBsp::echo()
{
    // 创建一个线程对象，传入对象实例和成员函数指针
    boost::thread t(&CklHmiBsp::hello, this);

    // 等待线程执行完毕
    t.join();

    std::cout << "Hello, world!" << std::endl;
}

void CklHmiBsp::hello()
{
    std::cout << "Hello from thread!" << std::endl;
}

// 创建 CklHmiBsp 对象
extern "C" void *createCklHmiBsp()
{
    return new CklHmiBsp();
}

// 调用 CklHmiBsp 对象的 echo 方法
extern "C" void callCklHmiBspEcho(void *obj)
{
    CklHmiBsp *bsp = static_cast<CklHmiBsp *>(obj);
    if (bsp)
    {
        bsp->echo();
    }
}

// 销毁 CklHmiBsp 对象
extern "C" void destroyCklHmiBsp(void *obj)
{
    delete static_cast<CklHmiBsp *>(obj);
}
