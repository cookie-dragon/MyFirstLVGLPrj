/**
 * @file cklhmibsp.h
 * @author My Name (me@domain.com)
 * @brief
 * @date 2025-04-10
 *
 * @copyright Copyright (c) My Company 2025
 *
 */

#ifndef CKLHMIBSP_H
#define CKLHMIBSP_H

#ifdef __cplusplus

#include <iostream>
#include <boost/thread.hpp>

// 定义 CklHmiBsp 类
class CklHmiBsp
{
public:
    CklHmiBsp();
    ~CklHmiBsp();

    void echo();
    void hello();
};

#endif

// 封装 C++ 类的功能为 C 语言可调用的函数
#ifdef __cplusplus
extern "C"
{
#endif

    // 创建 CklHmiBsp 对象
    void *createCklHmiBsp();
    // 调用 CklHmiBsp 对象的 echo 方法
    void callCklHmiBspEcho(void *obj);
    // 销毁 CklHmiBsp 对象
    void destroyCklHmiBsp(void *obj);

#ifdef __cplusplus
}
#endif

#endif // CKLHMIBSP_H