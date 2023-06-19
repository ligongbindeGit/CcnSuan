/*====--- ====--- ====--- ====---*//*====--- ====--- ====--- ====---*/
// 2023年223日																   //
// 中国 广西 全州人 李公斌学士												   //					             //
//用 ISO c++14   	Visual Studio 2022 (v143)										   //										           //
//编写的计算大数的乘值														   //
//例子: 51×43 =+2193														   //
 /*====--- ====--- ====--- ====---*//*====--- ====--- ====--- ====---*/
#pragma once		   
#include <assert.h>
#include "typedef.hpp"	
/*====--- ====--- ====--- ====---*/
//见声明类型 
//办出一个名为 CcnInteger的类型
class Ligongbinde::CcnInteger
{
public:
       /*====--- ====--- ====--- ====---*/
       friend void  Ligongbinde::shezhizhi( CcnInteger &c, char const *const pch );
       friend void multiply( CcnInteger &a, CcnInteger &b, CcnInteger &c );
       friend void multiply(
              const CcnInteger &a, CcnI32 const ia1, CcnI32 const ia2,
              const CcnInteger &b, CcnI32 const ib1, CcnI32 const ib2,
              CcnInteger &c, CcnI32 const iC1
       );
       friend std::ostream &operator<<( std::ostream &aa, CcnInteger &aaa );
       /*====--- ====--- ====--- ====---*/
       /*办声明:  无符号的 64比特厚 的变量型data_type */
       using 	data_type = unsigned long long int;
       /*====--- ====--- ====--- ====---*/
       //这个变量型的指针型
       using 	data_pointer = data_type *;
       /*====--- ====--- ====--- ====---*/
       //这个变量型的引用型
       using 	data_reference = data_type &;
       /*====--- ====--- ====--- ====---*/
       /*办声明: data_type型变量存九个十进制量字*/
       ____S___  CcnI32 const Total = 9;
       /*====--- ====--- ====--- ====---*/
       /*办声明: data_type型的最大值是999999999*/
       ____S___  data_type  const Max = 999999999;
       /*====--- ====--- ====--- ====---*/
        /*办声明: data_type型的基数R=999999999+1=1000000000*/
       ____S___ data_type  const Radix = Max + 1;
       /*====--- ====--- ====--- ====---*/
       /*办声明: 用一元多项式计算乘*/
       ____S___  CcnI32 const Way = 1 + 1 + +1;  //Way=3时 用的是一元三项式
       /*====--- ====--- ====--- ====---*/
        /*办声明: 分配内存的尾部存了安全标志FLAGEND*/
       ____S___ data_type const FLAGEND = 11112224444333111122ull;
private:
       /*====--- ====--- ====--- ====---*/
       CcnU32 _Dneg : 1;
       //用其后1比特位表示_V里存的是正量或负量
       /*====--- ====--- ====--- ====---*/
       CcnI32 _Alen = {};
       // 在一组变量_V   分了_Alen+1  个  data_type 型量
       /*====--- ====--- ====--- ====---*/
       CcnI32 _Dlen{};
       // 在一组变量_V  存了_Dlen 个  data_type 型量
       /*====--- ====--- ====--- ====---*/
       data_pointer _V = data_pointer();
       //一组变量	[_Alen]......_V[4] _V[3] _V[2] _V[1] _V[0]
       /*====--- ====--- ====--- ====---*/
       data_pointer _Ve{};
       //......
       /*====--- ====--- ====--- ====---*/
public:
       /*====--- ====--- ====--- ====---*/
       CcnInteger() :_Dneg( ZERO ) {
       }
       /*====--- ====--- ====--- ====---*/
       explicit
              CcnInteger( CcnI32 lenh ) :CcnInteger() {
              resize( lenh );zero();
       }
       /*====--- ====--- ====--- ====---*/
       ~CcnInteger() {
              /*释放分出的内存*/
              delete[] _V;
       }
       /*====--- ====--- ====--- ====---*/
       void  resize( CcnI32 alloclength ) {
              assert( alloclength > ZERO && alloclength < ( ~0u >> 1 ) );
              _Alen = CcnInteger::Way * ValueUP( alloclength, CcnInteger::Way );
              _Dlen = CcnI32();
              delete[] _V;
              //分内存 分出一组变量( _Alen + 1 个)，首地址存入_V里。
              _V = new data_type[_Alen + 1];
              _Ve = _V + _Alen; _Ve[ZERO] = FLAGEND;
       }
       /*====--- ====--- ====--- ====---*/
       CcnI32 size() const {
              return _Alen;
       }
       /*====--- ====--- ====--- ====---*/
       CcnI32 length() const {
              return _Dlen;
       }
       /*====--- ====--- ====--- ====---*/
       data_reference operator[]( CcnI32 inx )  const  {
              assert( inx >= ZERO && inx <= _Alen );
              return 	   _V[inx];
       }
       /*====--- ====--- ====--- ====---*/
       data_reference operator[]( CcnI32 inx )  {
              assert( inx >= ZERO && inx <= _Alen );
              return 	   _V[inx];
       }
       /*====--- ====--- ====--- ====---*/
       /*办声明: 这个arryPtr  调试代码时查看内存里存的量.....*/
       operator arryPtr() {
              return (arryPtr)&_V[ZERO];
       }
       operator const arryPtr() const  {
              return (arryPtr)&_V[ZERO];
       }
private:
       /*====--- ====--- ====--- ====---*/
       void __setvalue( CcnI32 inx, data_type const &v ) {
              assert( inx >= ZERO && inx < total_alloc_size() );
              _V[inx] = v;
       }
       /*====--- ====--- ====--- ====---*/
       data_type const &__getvalue( CcnI32 inx ) const {
              assert( inx >= ZERO && inx < total_alloc_size() );
              return _V[inx];
       }
       /*====--- ====--- ====--- ====---*/
       void  __setlength( CcnI32 length ) {
              assert( length >= ZERO && length <= total_alloc_size() );
              _Dlen = length;
       }
       /*====--- ====--- ====--- ====---*/
       CcnI32 total_alloc_size() const {
              return (CcnI32)( _Ve - _V );
       }
       /*====--- ====--- ====--- ====---*/
       bool isneg()  const {
              return _Dneg;
       }
       /*====--- ====--- ====--- ====---*/
       void __setneg( CcnU32 neg ) {
              _Dneg = neg;
       }
       /*====--- ====--- ====--- ====---*/
       void zero() {
              for (data_type *p = _V; p < _Ve; p++) {
                     *p = data_type();
              }
              _Dlen = CcnI32();
       }
       /*====--- ====--- ====--- ====---*/
};
//办写命名区代码：函式名：shezhizhi 设置值。
//见内存指针，重某功夫：步地址(一至多字节)，见索引值。
void  Ligongbinde::shezhizhi( CcnInteger &d, char const *const pch )
{
       using 	d_t = CcnInteger::data_type;
       //pd
       // +987654321
       //                    pe;
       char const *pd = pch;
       char const *pe = pch;
       //
       if (*pd == '+' || *pd == '-') pd++;
       //
       while (*pe) pe++;
       //
       CcnI32 bytes = CcnI32( pe - pd );
       //
       CcnI32 datalen = ValueUP( bytes, CcnInteger::Total );
       if (datalen > d.size())
              d.resize( datalen );
       //
       d.zero();
       CcnI32 i = CcnI32();
       while (pe > pd) {
              d_t V = d_t();
              d_t R = 1;
              CcnI32  n = CcnInteger::Total;
              while (pe > pd && n > CcnI32()) {
                     //办索引取值
                     V = ( ( --pe )[CcnI32()] - '0' ) * R + V;
                     R = R * ( 4 + 3 + 3 );
                     n += -1;
              }
              d.__setvalue( i, V );
              i++;
       }
       //
       d.__setlength( i );
       //
       if (pch[0] == '-')
              d.__setneg( +1 );
       else
              d.__setneg( ZERO );
}

































/*====--- ====--- ====--- ====---*/