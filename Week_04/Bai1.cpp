#include<iostream>
using namespace std;

class matrix
{
public:
	matrix()
	{
		for(int i=0;i<50;i++)
			for (int j = 0; j < 50; j++)
			{
				a[i][j] = 0;
			}
	}
	void cout_parameter()
	{
		cout << "Nhap vao so hang cua ma tran: "; cin >> row;
		cout << "Nhap vao so cot cua ma tran: "; cin >> column;
	}
	void check(matrix* a, matrix* b)
	{
		while (a->column != b->row)
		{
			cout << "\t(!) Hai ma tran khong the nhan voi nhau! " << endl;
			cout << "\t(!) Nhap lai hai ma tran " << endl;
			cout << "(?) Nhap vao so hang cua ma tran A: "; cin >> a->row;
			cout << "(?) Nhap vao so cot cua ma tran A: "; cin >> a->column;
			cout << "(?) Nhap vao so hang cua ma tran B: "; cin >> b->row;
			cout << "(?) Nhap vao so cot cua ma tran B: "; cin >> b->column;
		}
	}
	void cout_matrix()
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				cout << "Nhap a[" << i + 1 << "][" << j + 1 << "]: "; cin >> a[i][j];
			}
		}
	}
	void multiply(matrix* e, matrix* f)
	{
		matrix* c = new matrix;
		c->row = e->row; c->column = f->column;
		for (int i = 0; i < c->row; i++)
			for (int j = 0; j < c->column; j++)
				for (int k = 0; k < c->row; k++)
				{
					c->a[i][j] += e->a[i][k] * f->a[k][j];
				}
		cout << "\t(!) Tich cua hai ma tran A va B la: " << endl;
		for (int i = 0; i < c->row; i++)
		{
			for (int j = 0; j < c->column; j++)
			{
				cout << "\t" << c->a[i][j] << "  ";
			}
			cout << endl;
		}
	}
	
private:
	int row = 0;
	int column = 0;
	int a[50][50];
};
int main()
{
	matrix* A = new matrix;
	matrix* B = new matrix;
	cout << "\t(!) Nhap thong so cho ma tran A" << endl; A->cout_parameter(); 
	cout << "\t(!) Nhap thong so cho ma tran B" << endl; B->cout_parameter();
	A->check(A, B);
	cout << "\t(!) Nhap du lieu cho ma tran A" << endl;
	A->cout_matrix(); 
	cout << "\t(!) Nhap du lieu cho ma tran B" << endl;
	B->cout_matrix();
	B->multiply(A, B);
}