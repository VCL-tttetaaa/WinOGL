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
	// xy���W���擾
	void SetVector(double new_x, double new_y);
	// x��Ԃ�
	double GetX();
	// y��Ԃ�
	double GetY();
};
