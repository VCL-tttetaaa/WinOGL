#pragma once
class CVertex
{
public:
	CVertex();
	~CVertex();
private:
	// �N���b�N����x���W
	double new_x;
	// �N���b�N����y���W
	double new_y;	
	//�@���̒��_���X�g���w���|�C���^
	CVertex* next_vertex;
public:
	// �N���b�N����x���W�̎擾
	void SetX(double x);
	// �N���b�N����y���W�̎擾
	void SetY(double y);
	// �N���b�N����xy���W�̎擾
	void SetXY(double x, double y);
	//�@���_��X���W��ǂݍ��ލ���
	double GetX();
	//�@���_��Y���W��ǂݍ���
	double GetY();
	//�@���_��X�EY���W�̗�����ǂݍ���
	void GetXY(double get_x, double get_y);
	//�@���̒��_���X�g���w���|�C���^����������
	void SetNext(CVertex* new_next);
	//�@���̒��_���X�g���w���|�C���^��ǂݍ���
	CVertex* GetNext();
};

