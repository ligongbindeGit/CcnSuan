/*====--- ====--- ====--- ====---*//*====--- ====--- ====--- ====---*/
// 2023年223日																   //
// 中国 广西 全州人 李公斌学士												   //	
//用 ISO c++14   	Visual Studio 2022 (v143)										   //										           //
//编写的计算大数的乘值														   //
//例子: 51×43 =+2193														   //
 /*====--- ====--- ====--- ====---*//*====--- ====--- ====--- ====---*/
#include <iostream> 
#include <iomanip>	 
#include <string>	
#include "CcnInteger.h"
/*====--- ====--- ====--- ====---*/
//办的类型
using type = Ligongbinde::CcnInteger::data_type;







/*====--- ====--- ====--- ====---*/
//办个命名区——代码区，见内存，办索引重指针
____S___
void
suan3way( type  a[1 + 2], type b[1 + 2], type c[1 + 2 + 3] )
{	 //这是十进制量用一元三项式 算乘
        //(a[2]×r²+a[1]×r¹+a[0]×rº)×(b[2]×r²+b[1]×r¹+b[0]×rº)     (r=10;100;1000;1000;...1000000000)
       c[0x00 + 0x00] +=/**/+a[0x00 + 0x00] * b[0x00 + 0x00];
       c[0x01 + 0x00] +=/**/+a[0x00 + 0x00] * b[0x01 + 0x00] + a[0x01 + 0x00] * b[0x00 + 0x00];
       c[0x02 + 0x00] +=/**/+a[0x00 + 0x00] * b[0x02 + 0x00] + a[0x01 + 0x00] * b[0x01 + 0x00] + a[0x02 + 0x00] * b[0x00 + 0x00];
       c[0x03 + 0x00] +=/**/+a[0x01 + 0x00] * b[0x02 + 0x00] + a[0x02 + 0x00] * b[0x01 + 0x00];
       c[0x04 + 0x00] +=/**/+a[0x02 + 0x00] * b[0x02 + 0x00];
}




/*====--- ====--- ====--- ====---*/
//办个命名区——计算乘值的函式代码区，中文名曰：乘 ，英文名曰：multiply。
____S___
void
Ligongbinde::multiply(
       const CcnInteger &a, CcnI32 const ia1, CcnI32 const ia2,
       const CcnInteger &b, CcnI32 const ib1, CcnI32 const ib2,
       CcnInteger &c, CcnI32 const iC1
)
{
       using 	d_t = CcnInteger::data_type;
       d_t const R = CcnInteger::Radix;

       CcnI32  ia = CcnI32();
       CcnI32  ib = CcnI32();
       CcnI32  ic = CcnI32();
       CcnI32 iC2 = c.size();
       for (ia = ia1; ia < ia2; ia += CcnInteger::Way) {
              for (ib = ib1; ib < ib2; ib += CcnInteger::Way) {
                     ic = ia + ib;
                     ::suan3way( &a[ia], &b[ib], &c[ic] );
              }
              {//进位

                     static auto Min = []( CcnI32 a, CcnI32 b ) { return a < b ? a : b; };

                     type *c1 = &c[ia + 0], *c2 = &c[Min( ia + ib2 + CcnInteger::Way, iC2 )];
                     for (; c1 < c2; c1++) {
                            d_t H = c1[0] / R;
                            d_t L = c1[0] % R;
                            c1[0] = L;
                            c1[1] += H;
                     }
              }
       }
       c.__setneg( a.isneg() + b.isneg() );
}




/*====--- ====--- ====--- ====---*/
//
____S___
void
Ligongbinde::multiply( CcnInteger &a, CcnInteger &b, CcnInteger &c ) {
       CcnI32 nC = b.length() + a.length();
       if (nC > c.size()) {
              c.resize( nC );
       }
       c.zero();
       c.__setlength( nC );
       multiply( a, 0, a.length(), b, 0, b.length(), c, 0 + 0 );
}



/*====--- ====--- ====--- ====---*/
//办写的命名区代码
____S___
std::ostream &
Ligongbinde::operator<<( std::ostream &aa, CcnInteger &aaa )
{
       using d_t = CcnInteger::data_type;
       CcnI32 i{};
       if (aaa.isneg())
              aa << "-" << std::flush;
       else
              aa << "+" << std::flush;

       // CcnInteger::data_type  const * b = &aaa[0];
       CcnInteger::data_type  const *b = ( (arryPtr)aaa )[0];
       CcnInteger::data_type  const *e = b + aaa.length() - 1;
       while (e > b && *e == d_t()) e--;
       aa << std::setw( 1 ) << std::setfill( ' ' ) << *e << std::flush;
       e--;
       while (e >= b) {
              aa << std::setw( CcnInteger::Total ) << std::setfill( '0' ) << *e;
              e--;
       }
       aa << std::endl;
       return aa;
}





/*====--- ====--- ====--- ====---*/
//办写的命名区代码
____S___
void
CcnSuan()
{

       Ligongbinde::CcnInteger  c, a, b;
       {
              std::string sa, sb;
              std::cin >> sa >> sb;
              shezhizhi( a, sa.c_str() );
              shezhizhi( b, sb.c_str() );
       }
       multiply( a, b, c );
       //为调试
       //arryPtr  cc = c, aa = a, bb = b;
       std::cout << c << std::endl;
}



























//办写的命名区代码
void CcnRun()
{



































       while (2 == 1 + 1)CcnSuan();
}
/////////////////////////////// 