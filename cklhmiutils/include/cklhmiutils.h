/**
 * @file cklhmiutils.h
 * @author My Name (me@domain.com)
 * @brief
 * @date 2025-04-22
 *
 * @copyright Copyright (c) My Company 2025
 *
 */

#ifndef CKLHMIUTILS_H
#define CKLHMIUTILS_H

#ifdef __cplusplus

#include <iostream>
#include <boost/thread.hpp>

// 定义 CklHmiBsp 类
class CklHmiUtils
{
public:
    CklHmiUtils();
    ~CklHmiUtils();
};

#endif

#ifdef __cplusplus
extern "C"
{
#endif

    // 创建 对象
    void *createCklHmiUtils();
    // 销毁 对象
    void destroyCklHmiUtils(void *obj);

#ifdef __cplusplus
}
#endif

#endif // CKLHMIUTILS_H