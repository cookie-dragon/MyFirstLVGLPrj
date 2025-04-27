#include <gtest/gtest.h>

#include "cklbase32.h"

// 定义一个测试用例，属于Base32Suite测试套件，测试Base32编码功能
TEST(Base32Suite, Base32EncodeCase)
{
    // 定义一个常量指针pname，指向字符串"Cooky.Long"
    const char *pname = "Cooky.Long";
    // 定义一个cotp_error_t类型的变量cotp_err，用于存储编码过程中的错误信息
    cotp_error_t cotp_err;
    // 调用base32_encode函数，将pname指向的字符串编码为Base32格式
    // 参数1: (const uchar *)pname，将pname转换为无符号字符指针
    // 参数2: strlen(pname) + 1，计算pname字符串的长度并加1，包括终止符'\0'
    // 参数3: &cotp_err，传递cotp_err变量的地址，用于接收错误信息
    // 返回值: 编码后的Base32字符串指针
    char *psecret = base32_encode((const uchar *)pname, strlen(pname) + 1, &cotp_err);
    // 定义一个常量指针psecretexpect，指向预期的Base32编码结果
    const char *psecretexpect = "INXW623ZFZGG63TH";

    // 使用EXPECT_STREQ宏断言psecret和psecretexpect指向的字符串是否相等
    // 如果不相等，测试失败
    EXPECT_STREQ(psecretexpect, psecret);

    // 释放psecret指向的内存，避免内存泄漏
    free(psecret);
}

// 定义一个测试用例，属于Base32Suite测试套件，测试名为Base32DecodeCase
TEST(Base32Suite, Base32DecodeCase)
{
    // 定义一个指向常量字符的指针psecret，存储Base32编码的字符串
    const char *psecret = "INXW623ZFZGG63TH";
    // 定义一个cotp_error_t类型的变量cotp_err，用于存储解码过程中可能出现的错误信息
    cotp_error_t cotp_err;
    // 调用base32_decode函数，将Base32编码的字符串解码为原始字符串
    // base32_decode函数参数：待解码的字符串、字符串长度+1（包括终止符）、错误信息指针
    // 解码后的字符串存储在pname指针中
    char *pname = (char *)(base32_decode(psecret, strlen(psecret) + 1, &cotp_err));
    // 定义一个指向常量字符的指针pnameexpect，存储预期的解码结果
    const char *pnameexpect = "Cooky.Long";

    // 使用EXPECT_STREQ宏断言解码后的字符串pname是否与预期的字符串pnameexpect相等
    // 如果不相等，测试失败
    EXPECT_STREQ(pnameexpect, pname);

    // 释放由base32_decode函数分配的内存，避免内存泄漏
    free(pname);
}

// 定义一个测试用例，属于Base32Suite测试套件，测试名称为Base32ValidTrueCase
TEST(Base32Suite, Base32ValidTrueCase)
{
    // 定义一个指向常量字符的指针psecret，并初始化为字符串"INXW623ZFZGG63TH"
    const char *psecret = "INXW623ZFZGG63TH";
    // 使用EXPECT_TRUE宏来断言is_string_valid_b32函数对psecret的验证结果为true
    // is_string_valid_b32函数应该检查psecret是否为有效的Base32编码字符串
    EXPECT_TRUE(is_string_valid_b32(psecret));
}

// 定义一个测试用例，属于Base32Suite测试套件，测试名称为Base32ValidFalseCase
TEST(Base32Suite, Base32ValidFalseCase)
{
    // 定义一个指向常量字符的指针psecret，并初始化为"INXW623ZFZGG63T1"
    // 这个字符串包含一个无效的Base32字符'1'
    const char *psecret = "INXW623ZFZGG63T1"; // invalid character '1'
    // 使用EXPECT_FALSE宏来断言is_string_valid_b32(psecret)的返回值为false
    // is_string_valid_b32函数用于检查字符串是否为有效的Base32编码
    EXPECT_FALSE(is_string_valid_b32(psecret));
}

// 包含主函数的头文件
#include <iostream>
// 使用命名空间std，避免每次使用std中的东西时都要加std::
using namespace std;
// 主函数，程序的入口
int main(int argc, char **argv)
{
    // 初始化Google Test框架，将命令行参数传递给它
    // argc: 命令行参数的数量
    // argv: 命令行参数的数组
    ::testing::InitGoogleTest(&argc, argv);
    // 运行所有的测试用例，并返回测试结果
    // RUN_ALL_TESTS() 会运行所有通过TEST宏定义的测试用例
    return RUN_ALL_TESTS();
}
