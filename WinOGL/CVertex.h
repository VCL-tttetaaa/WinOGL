#pragma once
class CVertex
{
public:
	CVertex();
	~CVertex();
private:
	// クリックしたx座標
	double new_x;
	// クリックしたy座標
	double new_y;	
	//　次の頂点リストを指すポインタ
	CVertex* next_vertex;
public:
	// クリックしたx座標の取得
	void SetX(double x);
	// クリックしたy座標の取得
	void SetY(double y);
	// クリックしたxy座標の取得
	void SetXY(double x, double y);
	//　頂点のX座標を読み込む込む
	double GetX();
	//　頂点のY座標を読み込む
	double GetY();
	//　頂点のX・Y座標の両方を読み込む
	void GetXY(double get_x, double get_y);
	//　次の頂点リストを指すポインタを書き込む
	void SetNext(CVertex* new_next);
	//　次の頂点リストを指すポインタを読み込む
	CVertex* GetNext();
};

