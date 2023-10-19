#pragma once
#include "CVertex.h"
class CVector
{
public:
	CVector();
	CVector(CVertex* start, CVertex* finish);
	~CVector();
private:
	double x;
	double y;


public:
	// xy座標を取得
	void SetVector(double new_x, double new_y);
	// xを返す
	double GetX();
	// yを返す
	double GetY();
};
