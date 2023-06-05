#pragma once		   //2023年223日 中国 广西 全州人 李公斌编写的 计算大数的乘值 例子: 51*43 =+2193
#include <assert.h>
#define __李公斌的 
#define __李公斌的声明  static
#define __李公斌写的代码命名区 
using Ccn32 = int;
using arryPtr = long long unsigned int ( * ) [ 23 ];
__李公斌的声明 int Round ( int v , int V ) {
	return  ( v / V ) + ( v % V > 0 ) ;
}
__李公斌的
class CcnInteger
{
	public:
	friend void  shezhizhi ( CcnInteger &Z , char const *const pch );
	using 	data_type = long long unsigned int;
	__李公斌的声明
		int const Total = 9;
	__李公斌的声明
		int const Max = 999999999;
	__李公斌的声明
		int const Radix = Max + 1;
	__李公斌的声明
		int const Way = 3;
	__李公斌的声明
		data_type const FLAGEND = 11112224444333111122ull;
	operator arryPtr ( ) {
		return 	( arryPtr ) &_V [ 0 ];
	}
	private:
	unsigned int _Dneg : 1; int _Alen; int _Dlen;
	data_type *_V ;
	data_type *_Ve ;
	public:
	CcnInteger ( ) {
		_Dneg = _Alen = _Dlen = 0; _V = _Ve = 0;
	}
	explicit
		CcnInteger ( int lenh ) {
		resize ( lenh ) ; zero ( );
	}
	~CcnInteger ( ) {
		delete [ ] _V;
	}
	void  resize ( int alloclength ) {
		assert ( alloclength > 0 && alloclength < ( ~0u >> 1 ) );
		_Alen = Round ( alloclength , CcnInteger::Way ) * CcnInteger::Way;
		_Dlen = 0;
		delete [ ] _V;
		_V = new data_type [ _Alen + 1 ];
		_Ve = _V + _Alen  ;
		_Ve [ 0 ] = FLAGEND;
	}
	int size ( ) {
		return _Alen;
	}
	int length ( ) {
		return _Dlen;
	}
	data_type &operator[]( int inx ) {
		assert ( inx >= 0 && inx <= _Alen );
		return 	   _V [ inx ];
	}
	void __setvalue ( int inx , data_type const &v ) {
		assert ( inx >= 0 && inx < total_alloc_size ( ) );
		_V [ inx ] = v;
	}
	data_type const &__getvalue ( int inx ) {
		assert ( inx >= 0 && inx < total_alloc_size ( ) );
		return _V [ inx ];
	}
	void  __setlength ( int length ) {
		assert ( length >= 0 && length <= total_alloc_size ( ) );
		_Dlen = length;
	}
	int total_alloc_size ( )
	{
		return ( int ) ( _Ve - _V )	;
	}
	bool isneg ( ) {
		return _Dneg;
	}
	void __setneg ( unsigned int neg ) {
		_Dneg =neg;
	}
	void zero ( )
	{
		for ( data_type *p = _V ; p < _Ve; p++ )
		{
			*p = data_type ( );
		}
		_Dlen = int ( ) ;
	}
};
__李公斌的
using type = CcnInteger::data_type;
__李公斌写的代码命名区
void suan3way ( type  vX [ 3 ] , type vY [ 3 ] , type vZ [ 1 + 2 + 3 ] ) {
	vZ [ 0x00 + 0x00 ] +=/**/+vX [ 0x00 + 0x00 ] * vY [ 0x00 + 0x00 ];
	vZ [ 0x01 + 0x00 ] +=/**/+vX [ 0x00 + 0x00 ] * vY [ 0x01 + 0x00 ] + vX [ 0x01 + 0x00 ] * vY [ 0x00 + 0x00 ];
	vZ [ 0x02 + 0x00 ] +=/**/+vX [ 0x00 + 0x00 ] * vY [ 0x02 + 0x00 ] + vX [ 0x01 + 0x00 ] * vY [ 0x01 + 0x00 ] + vX [ 0x02 + 0x00 ] * vY [ 0x00 + 0x00 ];
	vZ [ 0x03 + 0x00 ] +=/**/+vX [ 0x01 + 0x00 ] * vY [ 0x02 + 0x00 ] + vX [ 0x02 + 0x00 ] * vY [ 0x01 + 0x00 ];
	vZ [ 0x04 + 0x00 ] +=/**/+vX [ 0x02 + 0x00 ] * vY [ 0x02 + 0x00 ];
}
__李公斌写的代码命名区
//设置值
void  shezhizhi ( CcnInteger &Z , char const *const pch ) {
	using 	d_t = CcnInteger::data_type;
   //d
   //+987654321
  //                   p;
	char const *d = pch;
	char const *p = pch;
	if ( *d == '+' || *d == '-' ) d++;
	while ( *p ) p++;
	int bytes = ( p - d );
	int datalen = Round ( bytes , CcnInteger::Total );
	if ( datalen >= Z.size ( ) )
		Z.resize ( datalen );
	Z.zero ( );
	int i = 0;
	while ( p > d ) {
		d_t V = 0;
		d_t R = 1;
		int  n = CcnInteger::Total;
		while ( p > d && n > 0 ) {
			V = ( *--p - '0' ) * R + V;
			R = R * 10;
			n += -1;
		}
		Z.__setvalue ( i , V );
		i++;
	}
	Z.__setlength ( i );
	if ( pch [ 0 ] == '-' )
		Z.__setneg ( 1 );
	else
		Z.__setneg ( 0 );
}
__李公斌写的代码命名区
void multiply ( CcnInteger &X , CcnInteger &Y , CcnInteger &Z ) {
	int nX = X.length ( );
	int nY = Y.length ( );
	int nZ = nX + nY;
	if ( nZ > Z.size ( ) )
	{
		Z.resize ( nZ );
	}
	Z.zero ( );
	Z.__setlength ( nZ );
	int  iX = 0;
	int  iY = 0;
	int  iZ = 0;
	for ( iX = 0; iX < nX; iX += ::CcnInteger::Way )
	{
		for ( iY = 0; iY < nY; iY += ::CcnInteger::Way )
		{
			::suan3way ( &X [ iX ] , &Y [ iY ] , &Z [ iX + iY ] )	 ;
		}
		//进位
		{
			static auto Min = [ ] ( int a , int b ) { return a < b ? a : b; } ;
			int e = Min ( iX + nY + CcnInteger::Way , nZ );
			type *f = &Z [ iX ] , *t = &Z [ e ];
			for ( ; f < t; f++ ) {
				CcnInteger::data_type H = f [ 0 ] / CcnInteger::Radix ;
				CcnInteger::data_type L = f [ 0 ] % CcnInteger::Radix;
				f [ 0 ] = L ;
				f [ 1 ] += H ;
			}
		}
	}
	Z.__setneg ( X.isneg ( ) +Y.isneg ( ) );
}
__李公斌写的代码命名区
#include <iostream>
#include <iomanip>				    
#include <string>		
std::ostream &operator<<( std::ostream &aa , CcnInteger &vA )
{
	Ccn32 i {};
	if ( vA.isneg ( ) )
		aa << "-" << std::flush;
	else
		aa << "+" << std::flush;
	typename CcnInteger::data_type *b = &vA [ 0 ];
	typename CcnInteger::data_type *e = b + vA.length ( ) - 1;
	while ( e > b && *e == 0 ) e--;
	aa << std::setw ( 1 ) << std::setfill ( ' ' ) << *e << std::flush;
	e--;
	while ( e >= b )
	{
		aa << std::setw ( CcnInteger::Total ) << std::setfill ( '0' ) << *e;
		e--;
	}
	aa << std::endl;
	return aa;
}
 __李公斌写的代码命名区
void CcnSuan(){
	CcnInteger  Z , X , Y ;
	std::string a,b;
	std::cin>>a>>b; 
	shezhizhi ( X , a.c_str() );		  //9999
	shezhizhi ( Y ,b.c_str() );
	multiply ( X , Y , Z );
	std::cout << Z << std::endl;
}
__李公斌写的代码命名区
void CcnRun ( ) {
	while ( 2==1+1)CcnSuan ( );
}
