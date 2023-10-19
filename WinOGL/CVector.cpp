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


// xy座標を取得
void CVector::SetVector(double new_x, double new_y)
{
	x = new_x;
	y = new_y;

	// TODO: ここに実装コードを追加します.
}

// xを返す
double CVector::GetX()
{
	return x;
}


// yを返す
double CVector::GetY()
{
	// TODO: ここに実装コードを追加します.
	return y;
}


