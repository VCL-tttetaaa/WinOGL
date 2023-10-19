#pragma once
#include "CVertex.h"
#include "CShape.h"
class CAdminControl
{
public:
	CAdminControl();
	~CAdminControl();
	void Draw();
/*�ύX�O
private:
	// x���W
	double L_Click_x;

	// y���W
	double L_Click_y;
	*/
public:
	// x���W���擾
	void SetXY(double x, double y);
private:
	// ���_�̈ʒu���W
	CVertex* vertex_head;
	CShape* shape_head = NULL;
	CShape* last_shape = new CShape();
	CShape* New_shape;
	int count;
	int count2;
public:
	// �N���b�N�����_��xy���W���擾
	void L_Click(double click_x, double click_y);
	// ��������
	void DrawLine(CVertex* start, CVertex* end);
	double CalcDistance(CVertex* new_vertex, CVertex* vertex_head);
};
