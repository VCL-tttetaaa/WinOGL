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
	// xyÀ•W‚ğæ“¾
	void SetVector(double new_x, double new_y);
	// x‚ğ•Ô‚·
	double GetX();
	// y‚ğ•Ô‚·
	double GetY();
};
