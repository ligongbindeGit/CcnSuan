/*====--- ====--- ====--- ====---*/ /*====--- ====--- ====--- ====---*/
//2023年223日 中国 广西 全州人 李公斌学士																             //
//用 ISO c++14   	Visual Studio 2022 (v143)																			           //
//编写的计算大数的乘值 例子: 51×43 =+2193	   															         //
/*====--- ====--- ====--- ====---*/ /*====--- ====--- ====--- ====---*/
#pragma once
#define ____S___  static	
namespace Ligongbinde {
       /*====--- ====--- ====--- ====---*/
       // char 字符型(8比特)  ， short int  短整型(16比特)， long int  长整型(32比特)，long long int  长长整型(64比特）
        /*====--- ====--- ====--- ====---*/
        //办声明 办类型 ，办出一个存在正负符号的 8比特厚的 整量型CcnI8。
       using CcnI8 = signed char;//。
       /*====--- ====--- ====--- ====---*/
       //办声明 办类型 ，办出一个不存在正负符号的 8比特厚的 整量型CcnU8
       using CcnU8 = unsigned char; //
       //办声明 办类型 ，办出一个存在正负符号的 16比特厚的 整量型CcnI16。
       using CcnI16 = signed short int;//。
       /*====--- ====--- ====--- ====---*/
       //办声明 办类型 ，办出一个不存在正负符号的 16比特厚的 整量型CcnU16
       using CcnU16 = unsigned short   int; //
       /*====--- ====--- ====--- ====---*/
       //办声明 办类型 ，办出一个存在正负符号的 32比特厚的 整量型CcnI32。
       using CcnI32 = signed long int;//。
       /*====--- ====--- ====--- ====---*/
       //办声明 办类型 ，办出一个不存在正负符号的 32比特厚的 整量型CcnU32
       using CcnU32 = unsigned long   int; //
       /*====--- ====--- ====--- ====---*/
       //办声明 办类型 ，办出一个存在正负符号的64比特厚的 整量型CcnI64。
       using CcnI64 = signed long long int;
       /*====--- ====--- ====--- ====---*/
       // 办声明 办类型 ，办出一个不存在正负符号的 64比特厚的 整量型CcnU64
       using CcnU64 = unsigned long long   int;
}
//
namespace Ligongbinde {
       /*====--- ====--- ====--- ====---*/
       //办声明 办类型  办出一个变量组的指针  含二十三个整型量的变量组的指针
       using arryPtr = long long unsigned int( * )[100 + 23];

}
//
namespace Ligongbinde {
       /*====--- ====--- ====--- ====---*/
       //办声明 办类型  办出一个名为 CcnInteger的类型
       class CcnInteger;
}
//
namespace Ligongbinde {

       /*====--- ====--- ====--- ====---*/
       //办常量 办出一个 名为ZERO的常量——存在符号位的常量。
       CcnI32 const ZERO = CcnI32();// signed int();
       /*====--- ====--- ====--- ====---*/
       //办常量 办出一个名为uZERO的常量 ——不存在符号位的常量。
       CcnU32 const uZERO = CcnU32();
}
//
#include <iostream>
namespace Ligongbinde {
       /*====--- ====--- ====--- ====---*/
      //办声明 办函式 办出一个 名为 shezhizhi 的函式
       void  shezhizhi( CcnInteger &c, char const *const pch );
       void multiply( CcnInteger &a, CcnInteger &b, CcnInteger &c );
       void multiply(
              const CcnInteger &a, CcnI32 const ia1, CcnI32 const ia2,
              const CcnInteger &b, CcnI32 const ib1, CcnI32 const ib2,
              CcnInteger &c, CcnI32 const iC1
       );
       std::ostream &operator<<( std::ostream &aa, CcnInteger &aaa );
}
namespace Ligongbinde {
       /*====--- ====--- ====--- ====---*/
       //办式 办函式 进入量 算出量 办出一个名为ValueUP函式 计算出一个量向上靠近某个量
       //例子：3*ValueUP( 4, 3 ) 。 4 靠近6。
       ____S___ int ValueUP( int v, int const N ) {
              return  ( v / N ) + ( v % N > ZERO );
       }
}
//
//
/*====--- ====--- ====--- ====---*/