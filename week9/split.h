#pragma once
//split.h
#ifndef GUARD_split_h
#define GUARD_split_h

#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

//�μ��� �����϶��� true, �׷��� �������� false
inline bool space(char c) {
	return isspace(c);
}
//�μ��� �����϶��� false, �׷��� �������� true
inline bool not_space(char c) {
	return !isspace(c);
}


template <class Out>
void split(const string& s, Out os){
	
	typedef string::const_iterator iter;

	iter i = s.begin();

	//�Һ��� : ���ݱ��� [������ i, ������ i]������ �ִ� ���ڿ��� ó��
	while (i != s.end()) {
		//�����ϴ� ������� ����
		//���� i��ġ���� ù��° ���� �ƴ� ���� ã��
		i = find_if(i, s.end(), not_space);
		
		//������ ���� �ܾ��� ���� ó��
		//while �ݺ��Ҷ� �׻� ���ο� �ݺ��� j�� ����
		//���� i��ġ���� ù��° ���� ���� ã��
		iter j = find_if(i, s.end(), space);

		//������ �ƴ� ���ڵ��� ã������
		if (i != s.end()) {
			*os++ = string(i, j);
		}
		//i �ݺ��� ��ġ�� j �ݺ����� ��ġ�� �����ϱ�
		i = j;
	}
}

#endif
