#pragma once
//my_algs.h

#ifndef GUARD_my_algs_h
#define GUARD_my_algs_h

//최대함수
template<class T>
T max(const T& left, const T& right) {
	return left > right ? //조건?
		left : right; //참변환 : 거짓변환
}
//최솟값 함수(min)
template<class T>
T min(const T& left, const T& right) {
	return left < right ? //조건?
		left : right; //참변환 : 거짓변환
}

//같으면 함수(equals)
template<class T>
T equals(const T& left, const T& right) {
	return left == right ? //조건?
		true : false; //참변환 : 거짓변환
}

#endif
