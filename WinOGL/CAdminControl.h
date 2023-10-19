#pragma once
#include "CVertex.h"
#include "CShape.h"
class CAdminControl
{
public:
	CAdminControl();
	~CAdminControl();
	void Draw();
/*変更前
private:
	// x座標
	double L_Click_x;

	// y座標
	double L_Click_y;
	*/
public:
	// x座標を取得
	void SetXY(double x, double y);
private:
	// 頂点の位置座標
	CVertex* vertex_head;
	CShape* shape_head = NULL;
	CShape* last_shape = new CShape();
	CShape* New_shape;
	int count;
	int count2;
public:
	// クリックした点のxy座標を取得
	void L_Click(double click_x, double click_y);
	// 線を引く
	void DrawLine(CVertex* start, CVertex* end);
	double CalcDistance(CVertex* new_vertex, CVertex* vertex_head);
};
