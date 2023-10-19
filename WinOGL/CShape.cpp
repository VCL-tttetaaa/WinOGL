#include "pch.h"
#include "CShape.h"
#include "CVertex.h"
#include "CVector.h"
#define _USE_MATH_DEFINES
#include <math.h>

CShape::CShape()
{
	vertex_head;
;	next_shape = NULL;
	count = 0;
}


CShape::CShape(double x, double y)
{
	vertex_head = new CVertex();
	vertex_head->SetXY(x, y);
	next_shape = NULL;
	count = 0;
}

CShape::~CShape()
{
}



void CShape::AddVertex(double new_x, double new_y, CShape* shape_head)
{
	double d = 100;
	// TODO: �����Ɏ����R�[�h��ǉ����܂�.
	CVertex* New_Vertex = new CVertex(); //�V�������������

	New_Vertex->SetXY(new_x, new_y); //�V���������Ɉ�����xy���W��������
	New_Vertex->SetNext(NULL);
	count++;


	if (count > 3 && CalcDistance(New_Vertex, SearchLastVertex(vertex_head)) <= 0.1) { //0.07
		//����Ƃ��ɒʂ�
		tmp_Vertex = SearchLastVertex(vertex_head);
	}
		//���̕����̏Z���i�ϐ�sava_vertex�́C�Z����ێ�����ϐ��j
		//�擪�ɂȂ��Ă�������
	bool flag = true;
	if (count >= 3) {
		//�����v�̎���������
		for (CVertex* start = GetVertexHead()->GetNext(); start->GetNext() != NULL; start = start->GetNext()) {
			if (!(Judge_selfcrossing_2(New_Vertex, tmp_Vertex, start, start->GetNext()))) {
				flag = false;
			}
		}
	}
	//�����i���łɂł��Ă���}�`�̏ォ��}�`�����Ȃ��悤�ɂ���j
	if (count >= 4 && this != shape_head) {
		for (CShape* shape = shape_head; shape != this; shape = shape->GetNext()) {
			if (!(this->Judge_Naihou(shape->GetVertexHead()))) {
				flag = false;
			}
		}
	}
	if (CalcDistance(New_Vertex, tmp_Vertex) <= 0.1 && flag == true) { //0.07
		New_Vertex->SetXY(tmp_Vertex->GetX(), tmp_Vertex->GetY());
		New_Vertex->SetNext(vertex_head);
		vertex_head = New_Vertex;
	}
	else {
		New_Vertex->SetNext(vertex_head);
		vertex_head = New_Vertex;
	}
		
}


// vertex_head�̃A�h���X��Ԃ�
CVertex* CShape::GetVertexHead()
{
	// TODO: �����Ɏ����R�[�h��ǉ����܂�.
	return vertex_head;
}


// �ŏ��̒��_�Ƃ̋������v�Z
double CShape::CalcDistance(CVertex* new_vertex, CVertex* vertex)
{
	double a = pow(new_vertex->GetX() - vertex->GetX(), 2);
	double b = pow(new_vertex->GetY() - vertex->GetY(), 2);
	return sqrt(a + b);
	// TODO: �����Ɏ����R�[�h��ǉ����܂�
}

// ���̐}�`�̃A�h���X
CShape* CShape::GetNext()
{
	// TODO: �����Ɏ����R�[�h��ǉ����܂�.
	return next_shape;
}
void CShape::SetNext(CShape* new_next)
{
	next_shape = new_next;
}

CVertex* CShape::GetTmp()
{
	// TODO: �����Ɏ����R�[�h��ǉ����܂�.
	return tmp_Vertex;
}

CVertex* CShape::SearchLastVertex(CVertex* start_vertex) {
	for (CVertex* Vertex = start_vertex; Vertex != NULL; Vertex = Vertex->GetNext()) {
		if (Vertex->GetNext() == NULL) {
			return Vertex;
		}
	}
}

// �O�ς̌v�Z
double CShape::CalcGaiseki(CVector* line1, CVector* line2)
{
	return (line1->GetX() * line2->GetY()) - (line1->GetY() * line2->GetX());
}


// ���ς̌v�Z
double CShape::CalcNaiseki(double gaiseki1, double gaiseki2)
{
	// TODO: �����Ɏ����R�[�h��ǉ����܂�.
	return gaiseki1 * gaiseki2;
}

// ���ς̌v�Z
double CShape::CalcNaiseki_2(CVector* line1, CVector* line2)
{
	return (line1->GetX() * line2->GetX()) + (line1->GetY() * line2->GetY());
}

// ����������
// line1��line2�̊O�ς����߁C���ꂼ��̊O�ς̓��ς�0�ȉ��Ȃ�������Ă���
bool CShape::Judge_selfcrossing(CVertex* a_start, CVertex* a_finish, CVertex* b_start, CVertex* b_finish)
{
	CVector* a0 = new CVector(a_finish, a_start);
	CVector* a1 = new CVector(b_start, a_start);
	CVector* a2 = new CVector(b_finish, a_start);

	CVector* b0 = new CVector(b_finish, b_start);
	CVector* b1 = new CVector(a_start, b_start);
	CVector* b2 = new CVector(a_finish, b_start);


	double ca1 = CalcGaiseki(a0, a1);
	double ca2 = CalcGaiseki(a0, a2);

	double cb1 = CalcGaiseki(b0, b1);
	double cb2 = CalcGaiseki(b0, b2);

	if (CalcNaiseki(ca1, ca2) <= 0 && CalcNaiseki(cb1, cb2) <= 0) {
		return false;
	}
	else {
		return true;
	}
}


// �������̔���
bool CShape::Judge_othercrossing(CVertex* a_start, CVertex* a_finish, CVertex* b_start, CVertex* b_finish)
{
	CVector* a0 = new CVector(a_finish, a_start);
	CVector* a1 = new CVector(b_start, a_start);
	CVector* a2 = new CVector(b_finish, a_start);

	CVector* b0 = new CVector(b_finish, b_start);
	CVector* b1 = new CVector(a_start, b_start);
	CVector* b2 = new CVector(a_finish, b_start);


	double ca1 = CalcGaiseki(a0, a1);
	double ca2 = CalcGaiseki(a0, a2);

	double cb1 = CalcGaiseki(b0, b1);
	double cb2 = CalcGaiseki(b0, b2);

	if (CalcNaiseki(ca1, ca2) <= 0 && CalcNaiseki(cb1, cb2) <= 0) {
		return false;
	}
	else {
		return true;
	}

	// TODO: �����Ɏ����R�[�h��ǉ����܂�.
	return false;
}
bool CShape::Judge_selfcrossing_2(CVertex* a_start, CVertex* a_finish, CVertex* b_start, CVertex* b_finish)
{
	CVector* a0 = new CVector(a_finish, a_start);
	CVector* a1 = new CVector(b_start, a_start);
	CVector* a2 = new CVector(b_finish, a_start);

	CVector* b0 = new CVector(b_finish, b_start);
	CVector* b1 = new CVector(a_start, b_start);
	CVector* b2 = new CVector(a_finish, b_start);


	double ca1 = CalcGaiseki(a0, a1);
	double ca2 = CalcGaiseki(a0, a2);

	double cb1 = CalcGaiseki(b0, b1);
	double cb2 = CalcGaiseki(b0, b2);

	if (CalcNaiseki(ca1, ca2) < 0 && CalcNaiseki(cb1, cb2) < 0) {
		return false;
	}
	else {
		return true;
	}

	// TODO: �����Ɏ����R�[�h��ǉ����܂�.
	return false;
}


// �����
bool CShape::Judge_Naihou(CVertex* new_vertex)
{
	CVector* line1 = new CVector();
	CVector* line2 = new CVector();
	CVector* last_line = new CVector();
	CVector* start_line = new CVector();
	double sum = 0, tan1 = 0;

	for (CVertex* vertex = this->GetVertexHead(); vertex != NULL; vertex = vertex->GetNext()) {
		if (vertex->GetNext() != NULL) {
			line1 = new CVector(vertex, new_vertex);
			line2 = new CVector(vertex->GetNext(), new_vertex);
			tan1 = atan2(this->CalcGaiseki(line1, line2),this->CalcNaiseki_2(line1, line2));
			sum = sum + tan1;
		}
		else {
			last_line = new CVector(vertex, new_vertex);
			start_line = new CVector(this->GetVertexHead(), new_vertex);
			tan1 = atan2(this->CalcGaiseki(last_line, start_line), this->CalcNaiseki_2(last_line, start_line));
			sum = sum + tan1;
		}
	}
	if (sum < 0) {
		sum = sum * (-1);
	}
	if (sum < 6) {
		return true;
	}
	else {
		return false;
	}
}


// ���_���̍��v
int CShape::Calc_sum_vertex()
{
	int i = 0;
	for (CVertex* vertex = this->GetVertexHead(); vertex != NULL; vertex = vertex->GetNext()) {
		i++;
	}

	return i;
}
