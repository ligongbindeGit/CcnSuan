#pragma once
#include <assert.h>
#define ____S__   signed   
#define ____S___ static
typedef  signed ____S_ ;
using ____S_74123 = signed int;

using arryPtr = long long unsigned int ( * ) [ 223 ];

class Ccnint
{

	public:
	friend void test ( );
	friend void    carryout ( Ccnint &Z );
	friend void  shezhizhi ( Ccnint &Z )	;
	friend void  fanma ( Ccnint &Z ) ;
	friend void  jinwei ( Ccnint &Z , int f , int t );
	friend void  shezhizhi ( Ccnint &Z , char const *const pch );

	using 	data_type = long long unsigned int;

	____S___
		int const Total = 4;
	____S___
		int const Max = 9999;
	____S___
		int const Radix = Max + 1;
	____S___
		int const Way = 3;


	operator arryPtr ( ) {
		return 	( arryPtr ) &__value [ 0 ];
	}
	private:
	int __alloc_length;
	int __data_length;
	data_type *__value ;
	data_type *__valueend ;
	public:

	Ccnint ( ) {
		__alloc_length = 0;
		__data_length = 0;
		__value = 0;
		__valueend = 0;
	}

	explicit
		Ccnint ( int lenh ) {
		resize ( lenh ) ;
		zero();
	}
	~Ccnint ( ) {
		delete [ ] __value;
	}

	void  resize ( int alloclength ) {
		__alloc_length = alloclength;
		__data_length = 0;
		delete [ ] __value;
		assert ( alloclength > 0 && alloclength < ( ~0u >> 1 ) );
		__value = new data_type [ alloclength + Way + Way ];
		__valueend = __value + alloclength + Way + Way;
	}
	int size ( ) {
		return __alloc_length;
	}
	int length ( ) {
		return __data_length;
	}
	data_type &operator[]( int inx ) {
		assert ( inx >= 0 && inx <= __alloc_length );
		return 	   __value [ inx ];
	}

	void __setvalue(int inx, data_type const&v){
			assert ( inx >= 0 && inx < total_alloc_size() );
		 __value [ inx ] =v;
	}
	data_type const &__getvalue(int inx){
			assert ( inx >= 0 && inx < total_alloc_size() );
		 return __value [ inx ];
	}

	void  __setlength (int length ) {
			assert ( length >= 0 && length < total_alloc_size() );
		  __data_length=length;
	}

	int total_alloc_size()
	{
		 return (int)( __valueend- __value)	;
	}
	
	bool isneg ( ) {
		return __value [ __alloc_length ] == Ccnint::Max;
	}

	void zero()
	{
		for ( data_type *p = __value ; p < __valueend; p++ )
		{
			*p = data_type ( );
		}
		__data_length = 0;
	}

};

using type = Ccnint::data_type;

void suan4way ( type  vX [ 4 ] , type vY [ 4 ] , type vZ [ 4 + 4 ] ) {
	vZ [ 0x00 + 0x00 ] +=/**/+vX [ 0x00 + 0x00 ] * vY [ 0x00 + 0x00 ];
	vZ [ 0x01 + 0x00 ] +=/**/+vX [ 0x00 + 0x00 ] * vY [ 0x01 + 0x00 ] + vX [ 0x01 + 0x00 ] * vY [ 0x00 + 0x00 ];
	vZ [ 0x02 + 0x00 ] +=/**/+vX [ 0x00 + 0x00 ] * vY [ 0x02 + 0x00 ] + vX [ 0x01 + 0x00 ] * vY [ 0x01 + 0x00 ] + vX [ 0x02 + 0x00 ] * vY [ 0x00 + 0x00 ];
	vZ [ 0x03 + 0x00 ] +=/**/+vX [ 0x00 + 0x00 ] * vY [ 0x03 + 0x00 ] + vX [ 0x01 + 0x00 ] * vY [ 0x02 + 0x00 ] + vX [ 0x02 + 0x00 ] * vY [ 0x01 + 0x00 ] + vX [ 0x03 + 0x00 ] * vY [ 0x00 + 0x00 ];
	vZ [ 0x04 + 0x00 ] +=/**/+vX [ 0x01 + 0x00 ] * vY [ 0x03 + 0x00 ] + vX [ 0x02 + 0x00 ] * vY [ 0x02 + 0x00 ] + vX [ 0x03 + 0x00 ] * vY [ 0x01 + 0x00 ];
	vZ [ 0x05 + 0x00 ] +=/**/+vX [ 0x02 + 0x00 ] * vY [ 0x03 + 0x00 ] + vX [ 0x03 + 0x00 ] * vY [ 0x02 + 0x00 ];
	vZ [ 0x06 + 0x00 ] +=/**/+vX [ 0x03 + 0x00 ] * vY [ 0x03 + 0x00 ];
}

void suan3way ( type  vX [ 3 ] , type vY [ 3 ] , type vZ [ 1 + 2 + 3 ] ) {
	vZ [ 0x00 + 0x00 ] +=/**/+vX [ 0x00 + 0x00 ] * vY [ 0x00 + 0x00 ];
	vZ [ 0x01 + 0x00 ] +=/**/+vX [ 0x00 + 0x00 ] * vY [ 0x01 + 0x00 ] + vX [ 0x01 + 0x00 ] * vY [ 0x00 + 0x00 ];
	vZ [ 0x02 + 0x00 ] +=/**/+vX [ 0x00 + 0x00 ] * vY [ 0x02 + 0x00 ] + vX [ 0x01 + 0x00 ] * vY [ 0x01 + 0x00 ] + vX [ 0x02 + 0x00 ] * vY [ 0x00 + 0x00 ];
	vZ [ 0x03 + 0x00 ] +=/**/+vX [ 0x01 + 0x00 ] * vY [ 0x02 + 0x00 ] + vX [ 0x02 + 0x00 ] * vY [ 0x01 + 0x00 ];
	vZ [ 0x04 + 0x00 ] +=/**/+vX [ 0x02 + 0x00 ] * vY [ 0x02 + 0x00 ];
}
void suan2way ( type  vX [ 2 ] , type vY [ 2 ] , type vZ [ 1 + 1 + 2 ] ) {
	vZ [ 0x00 + 0x00 ] +=/**/+vX [ 0x00 + 0x00 ] * vY [ 0x00 + 0x00 ];
	vZ [ 0x01 + 0x00 ] +=/**/+vX [ 0x00 + 0x00 ] * vY [ 0x01 + 0x00 ] + vX [ 0x01 + 0x00 ] * vY [ 0x00 + 0x00 ];
	vZ [ 0x02 + 0x00 ] +=/**/+vX [ 0x01 + 0x00 ] * vY [ 0x01 + 0x00 ];
}

//进位
void  jinwei ( Ccnint &Z , int f , int t ) {

	for ( int i = f; i <= t + Ccnint::Way; i++ ) {
		Ccnint::data_type H = Z.__getvalue(i) / Ccnint::Radix ;
		Ccnint::data_type L =  Z.__getvalue(i)% Ccnint::Radix;
		Z.__setvalue( i, L);
		Z.__setvalue( i + 1 ,Z.__getvalue( i + 1 )+H);

	}
}
 

//反码
void  fanma ( Ccnint &Z ) {

	for ( int i = 0; i < Z.size ( )+ Ccnint::Way ; i++ ) {
		Z.__setvalue(i, Ccnint::Max - Z.__getvalue( i) ) ;
	}
}
//加1
void  jiayi ( Ccnint &Z ) {
	Z [ 0 ]++;
}

//设置值
void  shezhizhi ( Ccnint &Z , char const *const pch ) {
	using 	d_t = Ccnint::data_type;
   //d
   //+987654321
  //                   p;
	char const *d = pch;
	char const *p = pch;
	if ( *d == '+' || *d == '-' ) d++;

	while ( *p ) p++;

	int bytes = ( p - d );
	int datalen = ( bytes / Ccnint::Total ) + ( bytes % Ccnint::Total > 0 );

	if ( datalen >= Z.size ( ) )
		Z.resize ( datalen );
   Z.zero( );

	int i = 0;
	while ( p > d ) {

		d_t V = 0;
		d_t R = 1;
		int  n = Ccnint::Total;
		while ( p > d && n > 0 ) {
			V = ( *--p - '0' ) * R + V;
			R = R * 10;
			n += -1;
		}
		Z.__setvalue(i, V);
		i++;
	}
	 Z.__setlength(i);

	if ( pch [ 0 ] == '-' ) {
		::fanma ( Z );
		::jiayi ( Z );
		if(Z[0]>Ccnint::Max)
			::jinwei ( Z , 0 , Z.size ( ) );
	}

}

void multiplyui ( Ccnint &X , Ccnint &Y , Ccnint &Z ) {

	int nX = X.length ( );
	int nY = Y.length ( );
	int nZ = nX + nY;

	if ( nZ > Z.size ( ) )
	{
		Z.resize ( nZ );
	}
	Z.zero ( );
	Z.__setlength(nZ);

	int  iX = 0;
	int  iY = 0;
	int  iZ = 0;

	for ( iX = 0; iX <= nX; iX += ::Ccnint::Way )
	{
		for ( iY = 0; iY <= nY; iY += ::Ccnint::Way )
		{
			::suan3way ( &X [ iX ] , &Y [ iY ] , &Z [ iX + iY ] )	 ;

		}
		::jinwei ( Z , iX + 0 , ( iX + nY < nZ ? iX + nY : nZ ) );
	}


}


void multiply ( Ccnint &X , Ccnint &Y , Ccnint &Z ) {

	int nX = X.length ( );
	int nY = Y.length ( );
	int nZ = nX + nY;

	if ( nZ > Z.size ( ) )
	{
		Z.resize ( nZ );
		nZ = Z.size ( );
	} else{
		  nZ =  Z.size();
	}
	Z.zero ( );
	Z.__setlength(nZ);

	int  iX = 0;
	int  iY = 0;
	int  iZ = 0;
	for ( iX = 0; iX <= nX; iX += ::Ccnint::Way )
	{
		type *vX = &X [ iX ];
		for ( iY = 0; iY <= nY && ( iX + iY <= nZ ) ; iY += ::Ccnint::Way )
		{
			//::suan3way ( &X [ iX ] , &Y [ iY ] , &Z [ iX + iY ] )	 ;
			type *vY = &Y [ iY ] , *vZ = &Z [ iX + iY ]	;
			vZ [ 0x00 + 0x00 ] +=/**/+vX [ 0x00 + 0x00 ] * vY [ 0x00 + 0x00 ];
			vZ [ 0x01 + 0x00 ] +=/**/+vX [ 0x00 + 0x00 ] * vY [ 0x01 + 0x00 ] + vX [ 0x01 + 0x00 ] * vY [ 0x00 + 0x00 ];
			vZ [ 0x02 + 0x00 ] +=/**/+vX [ 0x00 + 0x00 ] * vY [ 0x02 + 0x00 ] + vX [ 0x01 + 0x00 ] * vY [ 0x01 + 0x00 ] + vX [ 0x02 + 0x00 ] * vY [ 0x00 + 0x00 ];
			vZ [ 0x03 + 0x00 ] +=/**/+vX [ 0x01 + 0x00 ] * vY [ 0x02 + 0x00 ] + vX [ 0x02 + 0x00 ] * vY [ 0x01 + 0x00 ];
			vZ [ 0x04 + 0x00 ] +=/**/+vX [ 0x02 + 0x00 ] * vY [ 0x02 + 0x00 ];
		}
		if ( Y.isneg ( ) ) {
			for ( iY; iY <= nZ && ( iX + iY <= nZ ) ; iY += ::Ccnint::Way )
			{
				type /**vY = &Y [ iY ] , */ *vZ = &Z [ iX + iY ]	;
				vZ [ 0x00 + 0x00 ] +=/**/+vX [ 0x00 + 0x00 ] * Ccnint::Max;
				vZ [ 0x01 + 0x00 ] +=/**/+vX [ 0x00 + 0x00 ] * Ccnint::Max + vX [ 0x01 + 0x00 ] * Ccnint::Max;
				vZ [ 0x02 + 0x00 ] +=/**/+vX [ 0x00 + 0x00 ] * Ccnint::Max + vX [ 0x01 + 0x00 ] * Ccnint::Max + vX [ 0x02 + 0x00 ] * Ccnint::Max;
				vZ [ 0x03 + 0x00 ] +=/**/+vX [ 0x01 + 0x00 ] * Ccnint::Max + vX [ 0x02 + 0x00 ] * Ccnint::Max;
				vZ [ 0x04 + 0x00 ] +=/**/+vX [ 0x02 + 0x00 ] * Ccnint::Max;
			}
			::jinwei ( Z , iX + 0 , nZ );

		} else	::jinwei ( Z , iX + 0 , ( iX + nY < nZ ? iX + nY : nZ ) );
	}


	if ( X.isneg ( ) ) {

		for ( iX ; iX <= nZ ; iX += ::Ccnint::Way )
		{
			for ( iY = 0; iY <= nY && ( iX + iY <= nZ ) ; iY += ::Ccnint::Way )
			{
				//::suan3way ( &X [ iX ] , &Y [ iY ] , &Z [ iX + iY ] )	 ;
				type *vY = &Y [ iY ] , *vZ = &Z [ iX + iY ]	;
				vZ [ 0x00 + 0x00 ] +=/**/+Ccnint::Max * vY [ 0x00 + 0x00 ];
				vZ [ 0x01 + 0x00 ] +=/**/+Ccnint::Max * vY [ 0x01 + 0x00 ] + Ccnint::Max * vY [ 0x00 + 0x00 ];
				vZ [ 0x02 + 0x00 ] +=/**/+Ccnint::Max * vY [ 0x02 + 0x00 ] + Ccnint::Max * vY [ 0x01 + 0x00 ] + Ccnint::Max * vY [ 0x00 + 0x00 ];
				vZ [ 0x03 + 0x00 ] +=/**/+Ccnint::Max * vY [ 0x02 + 0x00 ] + Ccnint::Max * vY [ 0x01 + 0x00 ];
				vZ [ 0x04 + 0x00 ] +=/**/+Ccnint::Max * vY [ 0x02 + 0x00 ];
			}
			if ( Y.isneg ( ) ) {
				for ( iY; iY <= nZ && ( iX + iY < nZ ) ; iY += ::Ccnint::Way )
				{
					type *vZ = &Z [ iX + iY ]	;
					vZ [ 0x00 + 0x00 ] +=/**/+Ccnint::Max * Ccnint::Max;
					vZ [ 0x01 + 0x00 ] +=/**/+Ccnint::Max * Ccnint::Max + Ccnint::Max * Ccnint::Max;
					vZ [ 0x02 + 0x00 ] +=/**/+Ccnint::Max * Ccnint::Max + Ccnint::Max * Ccnint::Max + Ccnint::Max * Ccnint::Max;
					vZ [ 0x03 + 0x00 ] +=/**/+Ccnint::Max * Ccnint::Max + Ccnint::Max * Ccnint::Max;
					vZ [ 0x04 + 0x00 ] +=/**/+Ccnint::Max * Ccnint::Max;
				}
				::jinwei ( Z , iX + 0 , nZ );

			} else	::jinwei ( Z , iX + 0 , ( iX + nY < nZ ? iX + nY : nZ ) );
		}
	}



}


using funcPtr = long long unsigned int( * ) ( int , int );

void test ( ) {


	Ccnint  Z ( 51 ) , X ( 23 ) , Y (23);

	//::shezhizhi ( Z );
	//::shezhizhi ( X );
	//::shezhizhi ( Y );

	shezhizhi ( Y , "999999999999999999999999" );		  //9999
	shezhizhi ( X , "-999999999999999999999999" );

	multiply ( X , Y , Z );

	bool isneg = Z.isneg ( );

	::fanma ( Z );
	::jiayi ( Z );

	::fanma ( Z );
	::jiayi ( Z );

	::fanma ( Z );
	::jiayi ( Z );


}
