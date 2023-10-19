#include "pch.h"
#include "CAdminControl.h"
#include "CVertex.h"
#include <gl/GL.h>
#include "CShape.h"

CAdminControl::CAdminControl()
{
	/*�ύX�O
	L_Click_x = 0;
	L_Click_y = 0;
	*/
	count = 0;
	count2 = 0;
}

CAdminControl::~CAdminControl()
{
}


void CAdminControl::Draw()
{

	if (shape_head != NULL) {
		for(CShape* last_shape = shape_head; last_shape != NULL; last_shape= last_shape->GetNext()){
			for (CVertex* Vertex = last_shape->GetVertexHead(); Vertex != NULL; Vertex = Vertex->GetNext()) {
				glColor3f(1.0, 1.0, 1.0);
				glPointSize(5);
				glBegin(GL_POINTS);
				glVertex2f(Vertex->GetX(), Vertex->GetY());
				glEnd();
				if (Vertex->GetNext() != NULL) {
					DrawLine(Vertex, Vertex->GetNext());
				}
			}
		}
	}
	// TODO: �����Ɏ����R�[�h��ǉ����܂�.
}


// x���W���擾
void CAdminControl::SetXY(double x, double y)
{
	last_shape->GetVertexHead()->SetXY(x, y);
	// TODO: �����Ɏ����R�[�h��ǉ����܂�.
}



// �N���b�N�����_��xy���W���擾
void CAdminControl::L_Click(double click_x, double click_y)
{
	bool flag = true;
	bool flag2 = true;
	count++;
	count2++;


	if (shape_head == NULL) {
		shape_head = new CShape(click_x, click_y);
	}
	else {
		for (CShape* shape = shape_head; shape != NULL; shape = shape->GetNext()) {
			//��ԍŐV��shape�̓���
			last_shape = shape;
		}

		CVertex* new_vertex = new CVertex();
		new_vertex->SetXY(click_x, click_y);
		//�����Ō�����������C��������Ɉ���������Ȃ���΁C���̌�̏����𑱂���C���[�W
		CVertex* tmp = new CVertex();
		if (last_shape != shape_head) {
			for(CShape* head = shape_head; head != NULL; head = head->GetNext()){
				if (!(head->Judge_Naihou(new_vertex))) {
					flag = false;
					count--;
					break;
				}
			}
		}
		if (flag == true) {
			if (last_shape != shape_head && count != 1) {
				//����������
				for (CShape* check_shape = shape_head; check_shape != last_shape; check_shape = check_shape->GetNext()) { //���肷��`��̕ӂ�擪����T��
					for (CVertex* start = check_shape->GetVertexHead(); start->GetNext() != NULL; start = start->GetNext()) {
						if (!(last_shape->Judge_othercrossing(new_vertex, last_shape->GetVertexHead(), start, start->GetNext()))) {
							flag = false;
							flag2 = false;
							count--;
							break;
						}
					}
				}
			}
		}
		if (flag2 == true) {
			//������
			if (count >= 4) {
				//�Ō�ɑł����_�ƍŏ��ɑł����_�������ʒu�Ȃ�΁C�V����shape�����C�ŐV��shape�ɂȂ���
				for (CVertex* start = last_shape->GetVertexHead()->GetNext(); start->GetNext() != NULL; start = start->GetNext()) {
					if (!(last_shape->Judge_selfcrossing(new_vertex, last_shape->GetVertexHead(), start, start->GetNext()))) {
						flag = false;
					}
				}
			}
		}
		
		//[
		if (flag == true) {
			last_shape->AddVertex(click_x, click_y, shape_head);
			//�Ō�ɑł����_�ƍŏ��ɑł����_�������ʒu�Ȃ�΁C�V����shape�����C�ŐV��shape�ɂȂ���
			for (CVertex* start = last_shape->GetVertexHead(); start != NULL; start = start->GetNext()) {
				if (start->GetNext() == NULL) {
					if (count >= 4 && (last_shape->GetVertexHead()->GetX() == start->GetX() && last_shape->GetVertexHead()->GetY() == start->GetY())) {
						New_shape = new CShape();
						last_shape->SetNext(New_shape);
						count = 0;
					}
				}
			}
		}
		//}
	}
}
	// TODO: �����Ɏ����R�[�h��ǉ����܂�.


// ��������
void CAdminControl::DrawLine(CVertex* start, CVertex* end)
	{
			glLineWidth(2);
			glBegin(GL_LINES);
			glVertex2f(start->GetX(), start->GetY());
			glVertex2f(end->GetX(), end->GetY());
			glEnd();
	}
