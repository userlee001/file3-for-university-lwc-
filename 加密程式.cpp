#include<bits/stdc++.h>
#include <windows.h>
using namespace std ;
string encryption(string s1 , int t1 ){
	string s2 , s3 ; // s2 密文 ; s3 密文鑰匙 ; 
	int len = s1.size() , p , tem , q ; // p 決定加密方式 ; tem 先生成密文 ; tem 後生成密文鑰匙  ; // q 加密參數 ;
	char c ;
	bool b ; // b 決定密文大小寫 ;
	for( int i=0 ; i<len ; i++ ){
		if( s1[i] == ' '){
			s2 += ' ' ;
			s3 += ' ' ; 
			continue ;
		} // 處理空格  
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
		}  // 處理數字  
		if( 'a' <= s1[i] && s1[i] <= 'z' ){
			tem = s1[i] - 'a' ;
			b = true ;
		}
		if( 'A' <= s1[i] && s1[i] <= 'Z' ){
			tem = s1[i] - 'A' ;
			b = false ;
		}
		if( p==0 ){
		    tem += 13 ; // 呼應ROT13  
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
	} //處理英文  
	cout << "密文：     " << s2 << endl ;
	s3 += (char)('0' + t1 ) ;
	cout << "加密鑰匙： "<<s3 << endl ;
	return s2 ;
} 
int main(){ 
    srand( time(NULL) ) ; 
	string str ; // str 明文；　 
	getline( cin , str ) ;
	int times , t=0 ;
	cin >> times ; //  times 重複加密次數 ; 
	cout << "加密後之密文與加密鑰匙： " << endl ; 
	while( times-- ){
		t++ ;
		t %= 10 ;
		str = encryption(str,t) ;
	}
	cout << "一分鐘後自動關閉頁面" << endl ; 
	Sleep(60000) ; 
} 
