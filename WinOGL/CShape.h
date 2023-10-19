#pragma once
#include "CVertex.h"
#include "CShape.h"
#include "CVector.h"
#include <math.h>
class CShape
{
public:
	CShape();
	CShape(double x, double y);
	~CShape();

private:
	// �o���Ă������_
	CVertex* vertex_head;

	CShape* shape_head;

	CShape* next_shape = NULL;

	CVertex* tmp_Vertex = new CVertex();
	int count;
public:
	//���X�g���Ȃ���֐�
	void CShape::AddVertex(double new_x, double new_y, CShape* shape_head);

	// vertex_head�̃A�h���X��Ԃ�
	CVertex* GetVertexHead();
	// �ŏ��̒��_�Ƃ̋������v�Z
	double CalcDistance(CVertex* new_vertex, CVertex* vertex_head);
	// ���̐}�`�̍ŏ�
	CShape* GetNext();

	void CShape::SetNext(CShape* new_next);
	CVertex* GetTmp();

	CVertex* SearchLastVertex(CVertex* start_vertex);

	// vertex_head�̃A�h���X��Ԃ�
	CShape* GetShapeHead();
	double CShape::CalcGaiseki(CVector* line1, CVector* line2);
	// ���ς̌v�Z
	double CalcNaiseki(double gaiseki1, double gaiseki2S);
	// ���ς̌v�Z
	double CShape::CalcNaiseki_2(CVector* line1, CVector* line2);
	// ����������
	bool Judge_selfcrossing(CVertex* a_start, CVertex* a_finish, CVertex* b_start, CVertex* b_finish);
	// �������̔���
	bool Judge_othercrossing(CVertex* a_start, CVertex* a_finish, CVertex* b_start, CVertex* b_finish);
	bool CShape::Judge_selfcrossing_2(CVertex* a_start, CVertex* a_finish, CVertex* b_start, CVertex* b_finish);

	// �����
	bool Judge_Naihou(CVertex* new_vertex);
	// ���_���̍��v
	int Calc_sum_vertex();
};