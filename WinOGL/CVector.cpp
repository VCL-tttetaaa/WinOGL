#include "pch.h"
#include "CVector.h"
#include "CVertex.h"

CVector::CVector()
{

}

CVector::CVector(CVertex* start, CVertex* finish)
{
	x = finish->GetX() - start->GetX(); 
	y = finish->GetY() - start->GetY();
}

CVector::~CVector()
{
}


// xy���W���擾
void CVector::SetVector(double new_x, double new_y)
{
	x = new_x;
	y = new_y;

	// TODO: �����Ɏ����R�[�h��ǉ����܂�.
}

// x��Ԃ�
double CVector::GetX()
{
	return x;
}


// y��Ԃ�
double CVector::GetY()
{
	// TODO: �����Ɏ����R�[�h��ǉ����܂�.
	return y;
}


