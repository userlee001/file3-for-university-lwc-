#include<bits/stdc++.h>
#include <windows.h>
using namespace std ;
string encryption(string s1 , int t1 ){
	string s2 , s3 ; // s2 �K�� ; s3 �K���_�� ; 
	int len = s1.size() , p , tem , q ; // p �M�w�[�K�覡 ; tem ���ͦ��K�� ; tem ��ͦ��K���_��  ; // q �[�K�Ѽ� ;
	char c ;
	bool b ; // b �M�w�K��j�p�g ;
	for( int i=0 ; i<len ; i++ ){
		if( s1[i] == ' '){
			s2 += ' ' ;
			s3 += ' ' ; 
			continue ;
		} // �B�z�Ů�  
		p = rand()%3 ;
		q = rand() ;
		if( '0' <= s1[i] && s1[i] <= '9' ){
			tem = s1[i] ;
			if( p==1 ){
		        tem += q%10 ; 
		    }
		    if( p==2 ){
			    tem -= q%10 ;
		    }   
			if( tem < '0' ){
				tem += 10 ;
			}
			if( tem > '9' ){
				tem -=10 ;
			}
			s2 += (char)tem ;
			s3 += (char)('0'+p) ;
 			continue ;
		}  // �B�z�Ʀr  
		if( 'a' <= s1[i] && s1[i] <= 'z' ){
			tem = s1[i] - 'a' ;
			b = true ;
		}
		if( 'A' <= s1[i] && s1[i] <= 'Z' ){
			tem = s1[i] - 'A' ;
			b = false ;
		}
		if( p==0 ){
		    tem += 13 ; // �I��ROT13  
		}
		if( p==1 ){
		    tem++ ;
		}
		if( p==2 ){
			tem-- ;
		}
		if( tem < 0 ){
			tem += 26 ;
		}else if( tem > 25 ){
			tem -= 26 ;
		}
		if( b ){
			tem += 'a' ;
		}else{
			tem += 'A' ;
		}
		s2 += (char)tem ;
		s3 += (char)('0' + p) ; 
	} //�B�z�^��  
	cout << "�K��G     " << s2 << endl ;
	s3 += (char)('0' + t1 ) ;
	cout << "�[�K�_�͡G "<<s3 << endl ;
	return s2 ;
} 
int main(){ 
    srand( time(NULL) ) ; 
	string str ; // str ����F�@ 
	getline( cin , str ) ;
	int times , t=0 ;
	cin >> times ; //  times ���ƥ[�K���� ; 
	cout << "�[�K�ᤧ�K��P�[�K�_�͡G " << endl ; 
	while( times-- ){
		t++ ;
		t %= 10 ;
		str = encryption(str,t) ;
	}
	cout << "�@������۰���������" << endl ; 
	Sleep(60000) ; 
} 
