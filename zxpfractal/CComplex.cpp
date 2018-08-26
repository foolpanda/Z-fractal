#include "stdafx.h"
#include "CComplex.h"

CComplex operator +(const CComplex &lhs, const CComplex &rhs)
{
	CComplex result(lhs);
	result += rhs;

	return result;
}

CComplex operator -(const CComplex &lhs, const CComplex &rhs)
{
	CComplex result(lhs);
	result -= rhs;

	return result;
}

CComplex operator *(const CComplex &lhs, const CComplex &rhs)
{
	CComplex result(lhs.m_real * rhs.m_real - lhs.m_imag * rhs.m_imag,
		lhs.m_imag * rhs.m_real + lhs.m_real * rhs.m_imag);

	return result;
}

bool operator ==(const CComplex &lhs, const CComplex &rhs)
{
	return lhs.m_real == rhs.m_real && lhs.m_imag == rhs.m_imag;
}