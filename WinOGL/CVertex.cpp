#include "pch.h"
#include "CVertex.h"

CVertex::CVertex()
{
	new_x = 0;
	new_y = 0;
	next_vertex = NULL;
}

CVertex::~CVertex()
{
}


void CVertex::SetX(double x)
{
	new_x = x;
	
}

void CVertex::SetY(double y)
{
	new_y = y;
}

// クリックしたxy座標の取得
void CVertex::SetXY(double x, double y)
{
	new_x = x;
	new_y = y;
}

double CVertex::GetX()
{
	return new_x;
}

double CVertex::GetY()
{
	return new_y;
}

void CVertex::GetXY(double get_x, double get_y)
{
}

void CVertex::SetNext(CVertex* new_next)
{
	next_vertex = new_next;
}

CVertex* CVertex::GetNext()
{
	return next_vertex;
}
