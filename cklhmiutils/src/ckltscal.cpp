#include "ckltscal.h"

#include <math.h>

/* Powered by tslib 1.23 */
/* https://raw.githubusercontent.com/libts/tslib/refs/tags/1.23/tests/ts_calibrate_common.c */
int perform_calibration(calibration *cal)
{
    int j;
    float n, x, y, x2, y2, xy, z, zx, zy;
    float det, a, b, c, e, f, i;
    float scaling = 65536.0;

    /* Get sums for matrix */
    n = x = y = x2 = y2 = xy = 0;
    for (j = 0; j < 5; j++)
    {
        n += 1.0;
        x += (float)cal->x[j];
        y += (float)cal->y[j];
        x2 += (float)(cal->x[j] * cal->x[j]);
        y2 += (float)(cal->y[j] * cal->y[j]);
        xy += (float)(cal->x[j] * cal->y[j]);
    }

    /* Get determinant of matrix -- check if determinant is too small */
    det = n * (x2 * y2 - xy * xy) + x * (xy * y - x * y2) + y * (x * xy - y * x2);
    if (det < 0.1 && det > -0.1)
    {
        printf("ts_calibrate: determinant is too small -- %f\n", det);
        return 0;
    }

    /* Get elements of inverse matrix */
    a = (x2 * y2 - xy * xy) / det;
    b = (xy * y - x * y2) / det;
    c = (x * xy - y * x2) / det;
    e = (n * y2 - y * y) / det;
    f = (x * y - n * xy) / det;
    i = (n * x2 - x * x) / det;

    /* Get sums for x calibration */
    z = zx = zy = 0;
    for (j = 0; j < 5; j++)
    {
        z += (float)cal->xfb[j];
        zx += (float)(cal->xfb[j] * cal->x[j]);
        zy += (float)(cal->xfb[j] * cal->y[j]);
    }

    /* Now multiply out to get the calibration for framebuffer x coord */
    cal->a[0] = (int)((a * z + b * zx + c * zy) * (scaling));
    cal->a[1] = (int)((b * z + e * zx + f * zy) * (scaling));
    cal->a[2] = (int)((c * z + f * zx + i * zy) * (scaling));

    printf("%f %f %f\n", (a * z + b * zx + c * zy),
           (b * z + e * zx + f * zy),
           (c * z + f * zx + i * zy));

    /* Get sums for y calibration */
    z = zx = zy = 0;
    for (j = 0; j < 5; j++)
    {
        z += (float)cal->yfb[j];
        zx += (float)(cal->yfb[j] * cal->x[j]);
        zy += (float)(cal->yfb[j] * cal->y[j]);
    }

    /* Now multiply out to get the calibration for framebuffer y coord */
    cal->a[3] = (int)((a * z + b * zx + c * zy) * (scaling));
    cal->a[4] = (int)((b * z + e * zx + f * zy) * (scaling));
    cal->a[5] = (int)((c * z + f * zx + i * zy) * (scaling));

    printf("%f %f %f\n", (a * z + b * zx + c * zy),
           (b * z + e * zx + f * zy),
           (c * z + f * zx + i * zy));

    /* If we got here, we're OK, so assign scaling to a[6] and return */
    cal->a[6] = (int)scaling;

    return 1;
}

/* Powered by tslib 1.23 */
/* https://raw.githubusercontent.com/libts/tslib/refs/tags/1.23/tests/ts_calibrate.c */
void write_calibration(calibration *cal, uint32_t xres_orig, uint32_t yres_orig, int8_t rotation)
{
    char cal_buffer[256];
    unsigned int len;
    len = sprintf(cal_buffer, "%d %d %d %d %d %d %d %d %d %d",
                  cal->a[1], cal->a[2], cal->a[0],
                  cal->a[4], cal->a[5], cal->a[3], cal->a[6],
                  xres_orig, yres_orig, rotation);

    printf("Writing calibration: %s\n", cal_buffer);
}

Point convertToDeviceParams(calibration *cal, Point dispP) {
    Point devP;
    float scaling = 65536.0;

    double a0 = cal->a[0] / scaling;
    double a1 = cal->a[1] / scaling;
    double a2 = cal->a[2] / scaling;
    double a3 = cal->a[3] / scaling;
    double a4 = cal->a[4] / scaling;
    double a5 = cal->a[5] / scaling;

    devP.x = a0 + a1 * dispP.x + a2 * dispP.y;
    devP.y = a3 + a4 * dispP.x + a5 * dispP.y;

    return devP;
}


Point convertToDisplayPoints(calibration *cal, Point devP) {
    Point dispP;
    float scaling = 65536.0;
    
    double a0 = cal->a[0] / scaling;
    double a1 = cal->a[1] / scaling;
    double a2 = cal->a[2] / scaling;
    double a3 = cal->a[3] / scaling;
    double a4 = cal->a[4] / scaling;
    double a5 = cal->a[5] / scaling;

    if (fabs(a1) < 1e-6 || fabs(a5) < 1e-6) {
        // Handle the case where a1 or a5 is zero
        printf("Calibration matrix is singular, cannot perform inverse transformation.\n");
        dispP.x = dispP.y = 0;
        return dispP;
    }

    dispP.x = a1 != 0 ? (devP.x - a0 - a2 * (devP.y - a3 - a4 * devP.x) / a5) / a1 : 0;
    dispP.y = a5 != 0 ? (devP.y - a3 - a4 * (devP.x - a0 - a2 * devP.y / a5)) / a5 : 0;

    return dispP;
}

