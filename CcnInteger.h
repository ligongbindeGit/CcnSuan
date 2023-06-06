/*----------------------------------------------------------------*/
//2023��223�� �й� ���� ȫ���� ���
//ISO C++14   	Visual Studio 2022 (v143)
//��д�� ��������ĳ�ֵ ����: 51*43 =+2193	   
/*----------------------------------------------------------------*/
#pragma once		   
#include <assert.h>
#define ____S___  static
using CcnI32 = int;
using CcnU32 = unsigned  int;
using arryPtr = long long unsigned int ( * ) [ 23 ];
____S___ int Round ( int v , int V ) { return  ( v / V ) + ( v % V > 0 ) ; }
//���д������������
class CcnInteger
{
	public:
	friend void  shezhizhi ( CcnInteger &Z , char const *const pch );
	 /*�������:  �޷��ŵ�64���ص�data_type*/
	using 	data_type = long long unsigned int;
	____S___ /*�������: data_type�ͱ�����Ÿ�ʮ��������*/
		CcnI32 const Total = 9;
	____S___ /*�������: data_type�͵����ֵ��999999999*/
		CcnI32 const Max = 999999999;
	____S___ /*�������: data_type�͵Ļ���R=999999999+1=1000000000*/
		CcnI32 const Radix = Max + 1;
	____S___ /*�������: ��һԪ����ʽ�����*/
		CcnI32 const Way = 3;  //Way=3ʱ �õ���һԪ����ʽ
	____S___ /*�������: �����ڴ�β����ȫ��־FLAGEND*/
		data_type const FLAGEND = 11112224444333111122ull;
	//�����鿴�ڴ�������......
	operator arryPtr( ) { return ( arryPtr ) &_V [ 0 ]; }
	private:
	CcnU32 _Dneg : 1;  //1���ط���λ��ʾ������ 1Ϊ��;  0Ϊ��
	CcnI32 _Alen;	         //_V�������_Alen��data_type����
	CcnI32 _Dlen;	         //_V�����_Dlen��data_type����
	data_type *_V ;	     //�������ڴ�	_V[4] _V[3] _V[2] _V[1] _V[0]
	data_type *_Ve ;	     //......
	public:
	CcnInteger ( ) {
		_Dneg = _Alen = _Dlen = CcnI32 ( ); _V = _Ve = ( data_type * ) 0;	    //......
	}
	explicit
		CcnInteger ( CcnI32 lenh ) {
		resize ( lenh ) ;
		zero ( );
	}
	~CcnInteger ( ) { delete [ ] _V; }
	void  resize ( CcnI32 alloclength ) {
		assert ( alloclength > 0 && alloclength < ( ~0u >> 1 ) );
		_Alen = Round ( alloclength , CcnInteger::Way ) * CcnInteger::Way;
		_Dlen = CcnI32 ( );
		delete [ ] _V;
		_V = new data_type [ _Alen + 1 ];
		_Ve = _V + _Alen  ;
		_Ve [ 0 ] = FLAGEND;
	}
	CcnI32 size ( ) { return _Alen; }
	CcnI32 length ( ) { return _Dlen; }
	data_type &operator[]( CcnI32 inx ) {
		assert ( inx >= CcnI32 ( ) && inx <= _Alen );
		return 	   _V [ inx ];
	}
	void __setvalue ( CcnI32 inx , data_type const &v ) {
		assert ( inx >= CcnI32 ( ) && inx < total_alloc_size ( ) );
		_V [ inx ] = v;
	}
	data_type const &__getvalue ( CcnI32 inx ) {
		assert ( inx >= CcnI32 ( ) && inx < total_alloc_size ( ) );
		return _V [ inx ];
	}
	void  __setlength ( CcnI32 length ) {
		assert ( length >= CcnI32 ( ) && length <= total_alloc_size ( ) );
		_Dlen = length;
	}
	CcnI32 total_alloc_size ( ) { return ( CcnI32 ) ( _Ve - _V )	; }
	bool isneg ( ) { return _Dneg; }
	void __setneg ( CcnU32 neg ) { _Dneg = neg; }
	void zero ( ) {
		for ( data_type *p = _V ; p < _Ve; p++ ) {
			*p = data_type ( );
		}
		_Dlen = CcnI32 ( ) ;
	}
};
//����
using type = CcnInteger::data_type;
//���д������������
void suan3way ( type  vX [ 3 ] , type vY [ 3 ] , type vZ [ 1 + 2 + 3 ] )
{
	vZ [ 0x00 + 0x00 ] +=/**/+vX [ 0x00 + 0x00 ] * vY [ 0x00 + 0x00 ];
	vZ [ 0x01 + 0x00 ] +=/**/+vX [ 0x00 + 0x00 ] * vY [ 0x01 + 0x00 ] + vX [ 0x01 + 0x00 ] * vY [ 0x00 + 0x00 ];
	vZ [ 0x02 + 0x00 ] +=/**/+vX [ 0x00 + 0x00 ] * vY [ 0x02 + 0x00 ] + vX [ 0x01 + 0x00 ] * vY [ 0x01 + 0x00 ] + vX [ 0x02 + 0x00 ] * vY [ 0x00 + 0x00 ];
	vZ [ 0x03 + 0x00 ] +=/**/+vX [ 0x01 + 0x00 ] * vY [ 0x02 + 0x00 ] + vX [ 0x02 + 0x00 ] * vY [ 0x01 + 0x00 ];
	vZ [ 0x04 + 0x00 ] +=/**/+vX [ 0x02 + 0x00 ] * vY [ 0x02 + 0x00 ];
}
//���д������������
//����ֵ
void  shezhizhi ( CcnInteger &Z , char const *const pch )
{
	using 	d_t = CcnInteger::data_type;
   //d
   //+987654321
  //                   p;
	char const *d = pch;
	char const *p = pch;
	if ( *d == '+' || *d == '-' ) d++;
	while ( *p ) p++;
	CcnI32 bytes = CcnI32 ( p - d );
	CcnI32 datalen = Round ( bytes , CcnInteger::Total );
	if ( datalen >= Z.size ( ) )
		Z.resize ( datalen );
	Z.zero ( );
	CcnI32 i = CcnI32 ( ) ;
	while ( p > d ) {
		d_t V = d_t ( ) ;
		d_t R = 1;
		CcnI32  n = CcnInteger::Total;
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
//���д������������
void multiply ( CcnInteger &X , CcnInteger &Y , CcnInteger &Z ) {
	CcnI32 nX = X.length ( );
	CcnI32 nY = Y.length ( );
	CcnI32 nZ = nX + nY;
	if ( nZ > Z.size ( ) ) {
		Z.resize ( nZ );
	}
	Z.zero ( );
	Z.__setlength ( nZ );
	CcnI32  iX = CcnI32 ( );
	CcnI32  iY = CcnI32 ( );
	CcnI32  iZ = CcnI32 ( );
	for ( iX = CcnI32 ( ); iX < nX; iX += ::CcnInteger::Way ) {
		for ( iY = CcnI32 ( ); iY < nY; iY += ::CcnInteger::Way ) {
			::suan3way ( &X [ iX ] , &Y [ iY ] , &Z [ iX + iY ] )	 ;
		}
		//��λ
		{
			static auto Min = [ ] ( CcnI32 a , CcnI32 b ) { return a < b ? a : b; } ;
			CcnI32 e = Min ( iX + nY + CcnInteger::Way , nZ );
			type *f = &Z [ iX ] , *t = &Z [ e ];
			for ( ; f < t; f++ ) {
				CcnInteger::data_type H = f [ 0 ] / CcnInteger::Radix ;
				CcnInteger::data_type L = f [ 0 ] % CcnInteger::Radix;
				f [ 0 ] = L ;
				f [ 1 ] += H ;
			}
		}
	}
	Z.__setneg ( X.isneg ( ) + Y.isneg ( ) );
}
#include <iostream>
#include <iomanip>				    
#include <string>			
//���д������������
std::ostream &operator<<( std::ostream &aa , CcnInteger &vA )
{
	using d_t = CcnInteger::data_type;
	CcnI32 i {};
	if ( vA.isneg ( ) )
		aa << "-" << std::flush;
	else
		aa << "+" << std::flush;
	typename CcnInteger::data_type *b = &vA [ 0 ];
	typename CcnInteger::data_type *e = b + vA.length ( ) - 1;
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
//���д������������
void CcnSuan ( )
{
	CcnInteger  Z , X , Y ;
	std::string a , b;
	std::cin >> a >> b;
	shezhizhi ( X , a.c_str ( ) );		  //9999
	shezhizhi ( Y , b.c_str ( ) );
	multiply ( X , Y , Z );
	std::cout << Z << std::endl;
}









//���д������������
void CcnRun ( )
{
	while ( 2 == 1 + 1 )CcnSuan ( );
}
