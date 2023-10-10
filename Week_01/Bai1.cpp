#include<iostream>
#include<iomanip>
using namespace std;

struct diemso
{
	float toan = 0, li = 0, hoa = 0, van = 0, anh = 0, sinh = 0, su = 0, dia = 0;
	float dtb = 0;
};
class student
{
public:
	int mahs=0, tuoi=0;
	string name, que_quan;
	float chieu_cao=0, can_nang=0;
	diemso diem;
	student(string ten, int age, string que)
	{
		name = ten;
		tuoi = age;
		que_quan = que;
	}
	void nhapdiem(float a, float b, float c, float d, float e, float f, float g, float h)
	{
		diem.toan = a; diem.li = b; diem.hoa = c; diem.van = d; diem.anh = e; diem.sinh = f; diem.su = g; diem.dia = h;
		diem.dtb = (a + b + c + d + e + f + g + h) / 8;
	}
	void introduce()
	{
		cout << "\t\t\t ~~~~~ THONG TIN HOC SINH ~~~~~" << endl;
		cout << "Ten: " << name << endl;
		cout << "Tuoi: " << tuoi << endl;
		cout << "Que Quan: " << que_quan << " " << endl;
	}
	void bangdiem()
	{
		cout << "\t\t ~~~~~ BANG DIEM CUA HOC SINH " << name << " ~~~~~" << endl;
		cout << "\t\t\t" << "+" << setw(15) << "--------------+" << setw(15) << "--------------+" << endl
			<< "\t\t\t" << "|" << setw(15) << "   Toan Hoc   |" << setw(9) << diem.toan << "     |" << endl
			<< "\t\t\t" << "|" << setw(15) << "   Vat Li     |" << setw(9) << diem.li << "     |" << endl
			<< "\t\t\t" << "|" << setw(15) << "   Hoa Hoc    |" << setw(9) << diem.hoa << "     |" << endl
			<< "\t\t\t" << "|" << setw(15) << "   Ngu Van    |" << setw(9) << diem.van << "     |" << endl
			<< "\t\t\t" << "|" << setw(15) << "   Tieng Anh  |" << setw(9) << diem.anh << "     |" << endl
			<< "\t\t\t" << "|" << setw(15) << "   Sinh Hoc   |" << setw(9) << diem.sinh << "     |" << endl
			<< "\t\t\t" << "|" << setw(15) << "   Lich Su    |" << setw(9) << diem.su << "     |" << endl
			<< "\t\t\t" << "|" << setw(15) << "   Dia Li     |" << setw(9) << diem.dia << "     |" << endl
			<< "\t\t\t" << "+" << setw(15) << "--------------+" << setw(9) << "--------------+" << endl;
	}
	void diemtb()
	{
		cout << "Diem trung binh cua ban la: " << diem.dtb << endl;
		if (diem.dtb > 8)
			cout << "Hoc luc gioi!" << endl;
		else if (diem.dtb < 8 && diem.dtb>5)
			cout << "Hoc luc kha!" << endl;
		else
			cout << "Hoc luc trung binh!" << endl;
	}
private:
};
int main()
{
	student* a = new student("Viet Anh", 19, "Ha Noi");
	a->nhapdiem(7, 6.7, 8.9, 8.6, 6.5, 9.6, 8.4, 8.5);
	a->bangdiem();
	a->diemtb();
}
