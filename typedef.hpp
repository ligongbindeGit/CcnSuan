/*====--- ====--- ====--- ====---*/ /*====--- ====--- ====--- ====---*/
//2023��223�� �й� ���� ȫ���� ���ѧʿ																             //
//�� ISO c++14   	Visual Studio 2022 (v143)																			           //
//��д�ļ�������ĳ�ֵ ����: 51��43 =+2193	   															         //
/*====--- ====--- ====--- ====---*/ /*====--- ====--- ====--- ====---*/
#pragma once
#define ____S___  static	
namespace Ligongbinde {
       /*====--- ====--- ====--- ====---*/
       // char �ַ���(8����)  �� short int  ������(16����)�� long int  ������(32����)��long long int  ��������(64���أ�
        /*====--- ====--- ====--- ====---*/
        //������ ������ �����һ�������������ŵ� 8���غ�� ������CcnI8��
       using CcnI8 = signed char;//��
       /*====--- ====--- ====--- ====---*/
       //������ ������ �����һ���������������ŵ� 8���غ�� ������CcnU8
       using CcnU8 = unsigned char; //
       //������ ������ �����һ�������������ŵ� 16���غ�� ������CcnI16��
       using CcnI16 = signed short int;//��
       /*====--- ====--- ====--- ====---*/
       //������ ������ �����һ���������������ŵ� 16���غ�� ������CcnU16
       using CcnU16 = unsigned short   int; //
       /*====--- ====--- ====--- ====---*/
       //������ ������ �����һ�������������ŵ� 32���غ�� ������CcnI32��
       using CcnI32 = signed long int;//��
       /*====--- ====--- ====--- ====---*/
       //������ ������ �����һ���������������ŵ� 32���غ�� ������CcnU32
       using CcnU32 = unsigned long   int; //
       /*====--- ====--- ====--- ====---*/
       //������ ������ �����һ�������������ŵ�64���غ�� ������CcnI64��
       using CcnI64 = signed long long int;
       /*====--- ====--- ====--- ====---*/
       // ������ ������ �����һ���������������ŵ� 64���غ�� ������CcnU64
       using CcnU64 = unsigned long long   int;
}
//
namespace Ligongbinde {
       /*====--- ====--- ====--- ====---*/
       //������ ������  ���һ���������ָ��  ����ʮ�����������ı������ָ��
       using arryPtr = long long unsigned int( * )[100 + 23];

}
//
namespace Ligongbinde {
       /*====--- ====--- ====--- ====---*/
       //������ ������  ���һ����Ϊ CcnInteger������
       class CcnInteger;
}
//
namespace Ligongbinde {

       /*====--- ====--- ====--- ====---*/
       //�쳣�� ���һ�� ��ΪZERO�ĳ����������ڷ���λ�ĳ�����
       CcnI32 const ZERO = CcnI32();// signed int();
       /*====--- ====--- ====--- ====---*/
       //�쳣�� ���һ����ΪuZERO�ĳ��� ���������ڷ���λ�ĳ�����
       CcnU32 const uZERO = CcnU32();
}
//
#include <iostream>
namespace Ligongbinde {
       /*====--- ====--- ====--- ====---*/
      //������ �캯ʽ ���һ�� ��Ϊ shezhizhi �ĺ�ʽ
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
       //��ʽ �캯ʽ ������ ����� ���һ����ΪValueUP��ʽ �����һ�������Ͽ���ĳ����
       //���ӣ�3*ValueUP( 4, 3 ) �� 4 ����6��
       ____S___ int ValueUP( int v, int const N ) {
              return  ( v / N ) + ( v % N > ZERO );
       }
}
//
//
/*====--- ====--- ====--- ====---*/