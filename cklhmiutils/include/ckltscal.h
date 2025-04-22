/**
 * @file ckltscal.h
 * @author My Name (me@domain.com)
 * @brief
 * @date 2025-04-22
 *
 * @copyright Copyright (c) My Company 2025
 *
 */

#ifndef CKLTSCAL_H
#define CKLTSCAL_H

#define CROSS_BOUND_DIST 50

#include <stdio.h>
#include <stdint.h>

typedef struct
{
    int x[5], xfb[5];
    int y[5], yfb[5];
    int a[7];
} calibration;

typedef struct
{
    double x;
    double y;
} Point;

// 封装 C++ 类的功能为 C 语言可调用的函数
#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief 最小二乘法拟合
     *
     * @param cal 输入x,y,xfb,yfb，自动计算a参数
     * @return int 1:成功，0:失败
     * @author My Name (me@domain.com)
     * @date 2025-04-22
     */
    int perform_calibration(calibration *cal);

    /**
     * @brief 写入校准数据（模仿tslib输出文件到TSLIB_CALIBFILE指向的文件）
     *
     * 当前只做打印，不写入文件
     *
     * @param cal
     * @param xres_orig
     * @param yres_orig
     * @param rotation 旋转角度
     * @author My Name (me@domain.com)
     * @date 2025-04-22
     */
    void write_calibration(calibration *cal, uint32_t xres_orig, uint32_t yres_orig, int8_t rotation);

    Point convertToDeviceParams(calibration *cal, Point dispPoint);

    Point convertToDisplayPoints(calibration *cal, Point devPoint);

#ifdef __cplusplus
}
#endif

#endif // CKLTSCAL_H