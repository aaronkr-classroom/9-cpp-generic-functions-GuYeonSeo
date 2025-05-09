#pragma once
//split.h
#ifndef GUARD_split_h
#define GUARD_split_h

#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

//인수가 공백일때는 true, 그렇지 않을때는 false
inline bool space(char c) {
	return isspace(c);
}
//인수가 공백일때는 false, 그렇지 않을때는 true
inline bool not_space(char c) {
	return !isspace(c);
}


template <class Out>
void split(const string& s, Out os){
	
	typedef string::const_iterator iter;

	iter i = s.begin();

	//불변성 : 지금까지 [원래의 i, 현재의 i]범위에 있는 문자영을 처리
	while (i != s.end()) {
		//선행하는 공백들을 무시
		//지금 i위치부터 첫번째 띄어쓰기 아닌 문자 찾기
		i = find_if(i, s.end(), not_space);
		
		//순서상 다음 단어의 끝을 처음
		//while 반복할때 항상 새로운 반복자 j를 생성
		//지금 i위치부터 첫번째 띄어쓰기 문자 찾기
		iter j = find_if(i, s.end(), space);

		//공백이 아닌 문자들을 찾았을때
		if (i != s.end()) {
			*os++ = string(i, j);
		}
		//i 반복자 위치가 j 반복자의 위치를 저장하기
		i = j;
	}
}

#endif
