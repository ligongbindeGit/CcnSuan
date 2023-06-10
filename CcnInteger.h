/*====--- ====--- ====--- ====--- ====--- ====--- ====---*/
//2023年223日 中国 广西 全州人 李公斌学士																						           //
//用 ISO c++14   	Visual Studio 2022 (v143)																				         //
//--编写的 计算大数的乘值 例子: 51×43 =+2193	   															    //
/*====--- ====--- ====--- ====--- ====--- ====--- ====---*/
#pragma once		   
#include <assert.h>
#define ____S___  static		
using CcnI32 = int;
using CcnU32 = unsigned  int;
using arryPtr = long long unsigned int ( * ) [ 23 ]; //二十三个量组的指针
____S___ int Round ( int v , int const N ) { return  ( v / N ) + ( v % N > 0 ) ; }
//
class CcnInteger
{
	public:
	friend void  shezhizhi ( CcnInteger &c , char const *const pch );
	 /*李公斌学士声明:  64比特的无符号 data_type */
	using 	data_type = long long unsigned int;
	using 	data_pointer  =data_type*; 
	using 	data_reference  =data_type&; 
	____S___ /*李公斌学士声明: data_type型变量存九个十进制量字*/
		CcnI32 const Total = 9;
	____S___ /*李公斌学士声明: data_type型的最大值是999999999*/
		data_type  const Max = 999999999;
	____S___ /*李公斌学士声明: data_type型的基数R=999999999+1=1000000000*/
		data_type  const Radix = Max + 1;
	____S___ /*李公斌学士声明: 用一元多项式计算乘*/
		CcnI32 const Way = 1 + 1 + +1;  //Way=3时 用的是一元三项式
	____S___ /*李公斌学士声明: 分配内存的尾部存了安全标志FLAGEND*/
		data_type const FLAGEND = 11112224444333111122ull;
	    /*李公斌学士声明: 这个arryPtr  调试代码时查看内存里存的量.....*/
	    operator arryPtr( ) { return ( arryPtr ) &_V [ 0 ]; }
	private:
	CcnU32 _Dneg : 1;    //1比特符号位表示正负量 1为负;  0为正
	CcnI32 _Alen;	           // 在一组变量_V 里 分了_Alen+1  个  data_type 型量
	CcnI32 _Dlen;	           // 在一组变量_V 里 存了_Dlen      个  data_type 型量
	data_pointer _V ;	     //一组变量	[_Alen]......_V[4] _V[3] _V[2] _V[1] _V[0]
	data_pointer _Ve ;	   //......
	public:
	CcnInteger ( ) {
		_Dneg = _Alen = _Dlen = CcnI32 ( ); _V = _Ve = ( data_type * ) 0;	    //......
	}
	explicit
		CcnInteger ( CcnI32 lenh ) { resize ( lenh ) ; zero ( ); }
	~CcnInteger ( ) { delete [ ] _V; /*释放分出的内存*/}
	void  resize ( CcnI32 alloclength ) {
		assert ( alloclength > 0 && alloclength < ( ~0u >> 1 ) );
		_Alen = Round ( alloclength , CcnInteger::Way ) * CcnInteger::Way; _Dlen = CcnI32 ( ); delete [ ] _V;
		//分内存 分出一组变量( _Alen + 1 个)，首地址存入_V里。
		_V = new data_type [ _Alen + 1 ]; _Ve = _V + _Alen  ; _Ve [ 0 ] = FLAGEND;
	}
	CcnI32 size ( ) const { return _Alen; }
	CcnI32 length ( ) const { return _Dlen; }
	data_type &operator[]( CcnI32 inx ) const {
		assert ( inx >= CcnI32 ( ) && inx <= _Alen ); return 	   _V [ inx ];
	}
	data_type &operator[]( CcnI32 inx ) {
		assert ( inx >= CcnI32 ( ) && inx <= _Alen ); return 	   _V [ inx ];
	}
	void __setvalue ( CcnI32 inx , data_type const &v ) {
		assert ( inx >= CcnI32 ( ) && inx < total_alloc_size ( ) ); _V [ inx ] = v;
	}
	data_type const &__getvalue ( CcnI32 inx ) const {
		assert ( inx >= CcnI32 ( ) && inx < total_alloc_size ( ) ); return _V [ inx ];
	}
	void  __setlength ( CcnI32 length ) {
		assert ( length >= CcnI32 ( ) && length <= total_alloc_size ( ) ); _Dlen = length;
	}
	CcnI32 total_alloc_size ( ) const { return ( CcnI32 ) ( _Ve - _V )	; }
	bool isneg ( )  const { return _Dneg; }void __setneg ( CcnU32 neg ) { _Dneg = neg; }
	void zero ( ) {
		for ( data_type *p = _V ; p < _Ve; p++ ) {
			*p = data_type ( );
		}
		_Dlen = CcnI32 ( ) ;
	}
};
//李公斌学士写的命名区代码
//设置值
void  shezhizhi ( CcnInteger &d , char const *const pch )
{
	using 	d_t = CcnInteger::data_type;
   //pd
   // +987654321
  //                      pe;
	char const *pd = pch;
	char const *pe = pch;
	if ( *pd == '+' || *pd == '-' ) pd++;
	while ( *pe ) pe++;
	CcnI32 bytes = CcnI32 ( pe - pd );
	CcnI32 datalen = Round ( bytes , CcnInteger::Total );
	if ( datalen > d.size ( ) )
		d.resize ( datalen );
	d.zero ( );
	CcnI32 i = CcnI32 ( ) ;
	while ( pe > pd ) {
		d_t V = d_t ( ) ;
		d_t R = 1;
		CcnI32  n = CcnInteger::Total;
		while ( pe > pd && n > 0 ) {
			V = ( *--pe - '0' ) * R + V;
			R = R * 10;
			n += -1;
		}
		d.__setvalue ( i , V );
		i++;
	}
	d.__setlength ( i );
	if ( pch [ 0 ] == '-' )
	d.__setneg ( 1 );
	else
		d.__setneg ( 0 );
}
//李公斌学士的
using type = CcnInteger::data_type;
//李公斌学士写的命名区代码	 见内存(办索引)重指针
void suan3way ( type  a [ 1 + 2 ] , type b [ 1 + 2 ] , type c [ 1 + 2 + 3 ] )
{	 //这是十进制量用一元三项式 算乘
	 //(a[2]×r²+a[1]×r¹+a[0]×rº)×(b[2]×r²+b[1]×r¹+b[0]×rº)     (r=10;100;1000;1000;...1000000000)
	c [ 0x00 + 0x00 ] +=/**/+a [ 0x00 + 0x00 ] * b [ 0x00 + 0x00 ];
	c [ 0x01 + 0x00 ] +=/**/+a [ 0x00 + 0x00 ] * b [ 0x01 + 0x00 ] + a [ 0x01 + 0x00 ] * b [ 0x00 + 0x00 ];
	c [ 0x02 + 0x00 ] +=/**/+a [ 0x00 + 0x00 ] * b [ 0x02 + 0x00 ] + a [ 0x01 + 0x00 ] * b [ 0x01 + 0x00 ] + a [ 0x02 + 0x00 ] * b [ 0x00 + 0x00 ];
	c [ 0x03 + 0x00 ] +=/**/+a [ 0x01 + 0x00 ] * b [ 0x02 + 0x00 ] + a [ 0x02 + 0x00 ] * b [ 0x01 + 0x00 ];
	c [ 0x04 + 0x00 ] +=/**/+a [ 0x02 + 0x00 ] * b [ 0x02 + 0x00 ];
}
//李公斌学士写的命名区代码
void multiply (
	const CcnInteger &a , CcnI32 const ia1 , CcnI32 const ia2 ,
	const CcnInteger &b , CcnI32 const ib1 , CcnI32 const ib2 ,
	CcnInteger &c , CcnI32 const iC1
)
{
	using 	d_t = CcnInteger::data_type;
	d_t const &R = CcnInteger::Radix ;

	CcnI32  ia = CcnI32 ( );
	CcnI32  ib = CcnI32 ( );
	CcnI32  ic = CcnI32 ( );
	CcnI32 iC2 = c.size ( );
	for ( ia = ia1; ia < ia2; ia += ::CcnInteger::Way ) {
		for ( ib = ib1; ib < ib2; ib += ::CcnInteger::Way ) {
			ic = ia + ib ;
			::suan3way ( &a [ ia ] , &b [ ib ] , &c [ ic ] )	 ;
		}
		{//进位

			static auto Min = [ ] ( CcnI32 a , CcnI32 b ) { return a < b ? a : b; } ;

			type *c1 = &c [ ia + 0 ] , *c2 = &c [ Min ( ia + ib2 + CcnInteger::Way , iC2 ) ];
			for ( ; c1 < c2; c1++ ) {
				d_t H = c1 [ 0 ] / R ;
				d_t L = c1 [ 0 ] % R;
				c1 [ 0 ] = L ;
				c1 [ 1 ] += H ;
			}
		}
	}
	c.__setneg ( a.isneg ( ) + b.isneg ( ) );
}
void multiply ( CcnInteger &a , CcnInteger &b , CcnInteger &c ) {
	CcnI32 nC = b.length ( ) + a.length ( );
	if ( nC > c.size ( ) ) {
		c.resize ( nC );
	}
	c.zero ( );
	c.__setlength ( nC );
	multiply ( a , 0 , a.length ( ) , b , 0 , b.length ( ) , c , 0 + 0 );
}

#include <iostream>
#include <iomanip>				    
#include <string>			
//李公斌学士写的命名区代码
std::ostream &operator<<( std::ostream &aa , CcnInteger &a )
{
	using d_t = CcnInteger::data_type;
	CcnI32 i {};
	if ( a.isneg ( ) )
		aa << "-" << std::flush;
	else
		aa << "+" << std::flush;
	CcnInteger::data_type *b = &a [ 0 ];
	CcnInteger::data_type *e = b + a.length ( ) - 1;
	while ( e > b && *e == d_t ( ) ) e--;
	aa << std::setw ( 1 ) << std::setfill ( ' ' ) << *e << std::flush;
	e--;
	while ( e >= b ) {
		aa << std::setw ( CcnInteger::Total ) << std::setfill ( '0' ) << *e;
		e--;
	}
	aa << std::endl;
	return aa;
}
//李公斌学士写的命名区代码
void CcnSuan ( )
{
	CcnInteger  c , a , b ;
	{
		std::string sa , sb;
		std::cin >> sa >> sb;
		shezhizhi ( a , sa.c_str ( ) );
		shezhizhi ( b , sb.c_str ( ) );
	}
	multiply ( a , b , c );
	std::cout << c << std::endl;
}
//李公斌学士写的命名区代码
void CcnRun ( )
{
	while ( 2 == 1 + 1 )CcnSuan ( );
}
