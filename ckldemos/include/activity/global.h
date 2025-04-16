#ifndef GLOBAL_H
#define GLOBAL_H

// 设计的原始尺寸
#define DESIGN_WIDTH 800
#define DESIGN_HEIGHT 480

class GlobalManager
{
public:
    static GlobalManager *getInstance() { return p; };

private:
    GlobalManager() {}; // 私有构造函数，防止外部实例化
    static GlobalManager *p;

private:
    double scale_x;
    double scale_y;

public:
    double getScaleX() { return scale_x; }
    double getScaleY() { return scale_y; }

public:
    void setScreenSize(int width, int height)
    {
        scale_x = (double)width / DESIGN_WIDTH;
        scale_y = (double)height / DESIGN_HEIGHT;
    }
};
GlobalManager *GlobalManager::p = new GlobalManager();

#endif // GLOBAL_H