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
	// 覚えておく頂点
	CVertex* vertex_head;

	CShape* shape_head;

	CShape* next_shape = NULL;

	CVertex* tmp_Vertex = new CVertex();
	int count;
public:
	//リストをつなげる関数
	void CShape::AddVertex(double new_x, double new_y, CShape* shape_head);

	// vertex_headのアドレスを返す
	CVertex* GetVertexHead();
	// 最初の頂点との距離を計算
	double CalcDistance(CVertex* new_vertex, CVertex* vertex_head);
	// 次の図形の最初
	CShape* GetNext();

	void CShape::SetNext(CShape* new_next);
	CVertex* GetTmp();

	CVertex* SearchLastVertex(CVertex* start_vertex);

	// vertex_headのアドレスを返す
	CShape* GetShapeHead();
	double CShape::CalcGaiseki(CVector* line1, CVector* line2);
	// 内積の計算
	double CalcNaiseki(double gaiseki1, double gaiseki2S);
	// 内積の計算
	double CShape::CalcNaiseki_2(CVector* line1, CVector* line2);
	// 自交差判定
	bool Judge_selfcrossing(CVertex* a_start, CVertex* a_finish, CVertex* b_start, CVertex* b_finish);
	// 他交差の判定
	bool Judge_othercrossing(CVertex* a_start, CVertex* a_finish, CVertex* b_start, CVertex* b_finish);
	bool CShape::Judge_selfcrossing_2(CVertex* a_start, CVertex* a_finish, CVertex* b_start, CVertex* b_finish);

	// 内包判定
	bool Judge_Naihou(CVertex* new_vertex);
	// 頂点数の合計
	int Calc_sum_vertex();
};