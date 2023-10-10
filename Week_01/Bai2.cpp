#include<iostream>
#include<string>
#include<iomanip>
#include<windows.h>
using namespace std;

struct GPA
{
	float toan = 0, li = 0, hoa = 0, van = 0, anh = 0, sinh = 0, su = 0, dia = 0;
	float total_score = 0;
};
class student {
public:
	int student_code = 0;
	string name;
	int age = 0;
	string hometown;
	float height = 0;
	float weight = 0;
	GPA gpa;
private:
};
class lop_hoc {
public:
	string class_code;
	student a[100];
	student* monitor = new student;
	int number_of_class = 0;
	int number_of_student = 0;
	lop_hoc()
	{
		number_of_class++;
	}
	void add_student()
	{
		cout << "\t[1] Them hoc sinh vao lop" << endl;
		cout << "(?) Nhap ma hoc sinh: "; cin >> a[number_of_student].student_code;
		cin.ignore();
		cout << "(?) Nhap ten hoc sinh: "; getline(cin, a[number_of_student].name);
		cout << "(?) Nhap tuoi hoc sinh: "; cin >> a[number_of_student].age;
		cin.ignore();
		cout << "(?) Nhap que quan cua hoc sinh: "; getline(cin, a[number_of_student].hometown);
		cout << "(?) Nhap tong diem cua hoc sinh: "; cin >> a[number_of_student].gpa.total_score;
		cout << "\t(!) Da them hoc sinh " << a[number_of_student].name << " vao lop\n" << endl;
		number_of_student++;
	}
	void cout_student()
	{
		cout << "\t[5] Danh sach lop" << endl;
		cout << "+-------------+-----------------------------+---------+--------------------+-----------+" << endl;
		cout << setw(14) << left << "| Ma hoc sinh" << setw(30) << left << "| Ho va ten" << setw(10) << left << "| Tuoi" << setw(21) << left << "| Que quan " << setw(10) << left << "| Tong diem " << "|" << endl;
		cout << "+-------------+-----------------------------+---------+--------------------+-----------+" << endl;
		for (int i = 0; i < number_of_student; i++)
		{
			cout <<"|" << setw(13) << left << a[i].student_code << "|" << setw(29)  << left << a[i].name << "|" << setw(9) << left << a[i].age << "|" << setw(20) << left << a[i].hometown << "|" << setw(11) << left << a[i].gpa.total_score << "|" << endl;
		}
		cout << "+-------------+-----------------------------+---------+--------------------+-----------+" << endl;
		cout << "\t(!) Lop co " << number_of_student << " hoc sinh!\n" << endl; 
	}
	void delete_student()
	{
		cout << "\t[2] Xoa hoc sinh" << endl;
		int n, j;
		bool check = false;
		cout << "(?) Nhap ma hoc sinh can xoa: "; cin >> n;
		while (check == false)
		{
			for (int i = 0; i < number_of_student; i++)
			{
				if (a[i].student_code == n)
				{
					j = i;
					check = true;
					break;
				}
			}
			if (check == false)
			{
				cout << "\t(!) Khong tim thay ma sinh vien can xoa!" << endl;
				cout << "(?) Nhap lai ma sinh vien can xoa: "; cin >> n;
			}
		}
		cout << "\t(!) Da xoa sinh vien co ma hoc sinh " << a[j].student_code << endl;
		number_of_student--;
		for (int k = j; k < number_of_student; k++)
		{
			a[k] = a[k + 1];
		}
	}
	void edit_information()
	{
		cout << "\t[3] Sua thong tin hoc sinh" << endl;
		int n, t, j;
		cout << "(?) Nhap ma sinh vien can sua: "; cin >> n;
		cout << "\t\t(!) Nhap thong tin can sua " << endl;
		cout << "\t(1) Sua ma sinh vien" << endl
			 << "\t(2) Sua ho va ten" << endl
			 << "\t(3) Sua tuoi" << endl
			 << "\t(4) Sua que quan" << endl
			 << "\t(5) Sua diem tong ket" << endl;
		cout << "(?) Nhap lua chon cua ban: "; cin >> t;
		for (int i = 0; i < number_of_student; i++)
		{
			if (a[i].student_code == n)
				j = i;
		}
		while (t > 6 || t < 1)
		{
			cout << "\t(!) Lua chon khong hop le!" << endl;
			cout << "(?) Nhap lai lua chon: "; cin >> t;
		}
		if (t == 1)
		{
			cout << "(?) Nhap lai ma sinh vien: "; cin >> a[j].student_code;
			cout << "\t(!) Da sua lai ma sinh vien thanh " << a[j].student_code << endl;
		}
		else if (t == 2)
		{
			cin.ignore(1);
			cout << "(?) Nhap lai ho va ten: "; getline(cin, a[j].name);
			cout << "\t(!) Da sua lai ten thanh " << a[j].name << endl;
		}
		else if (t == 3)
		{
			cout << "(?) Nhap lai tuoi can sua: "; cin >> a[j].age;
			cout << "\t(!) Da sua lai tuoi thanh " << a[j].age << endl;
		}
		else if (t == 4)
		{
			cin.ignore(1);
			cout << "(?) Nhap lai que quan can sua: "; getline(cin, a[j].hometown);
			cout << "\t(!) Da sua lai que quan thanh " << a[j].hometown << endl;
		}
		else 
		{
			cout << "(?) Nhap lai diem tong ket can sua: "; cin >> a[j].gpa.total_score;
			cout << "\t(!) Da sua lai diem tong ket thanh " << a[j].gpa.total_score << endl;
		}
	}
	void set_monitor()
	{
		cout << "\t [4] Thiet lap lop truong " << endl;
		int n, j; 
		cout << "(?) Nhap ma sinh vien duoc chon lam lop truong: "; cin >> n;
		for (int i = 0; i < number_of_student; i++)
		{
			if (a[i].student_code == n)
				j = i;
		}
		cout << "\t(!) " << a[j].name << " da duoc chon lam lop truong " << endl;
		monitor = &a[j];
		cout << "\t(!) Thong tin lop truong cua lop" << endl;
		cout << "+-------------+-----------------------------+---------+--------------------+-----------+" << endl;
		cout << setw(14) << left << "| Ma hoc sinh" << setw(30) << left << "| Ho va ten" << setw(10) << left << "| Tuoi" << setw(21) << left << "| Que quan " << setw(10) << left << "| Tong diem " << "|" << endl;
		cout << "+-------------+-----------------------------+---------+--------------------+-----------+" << endl;
		cout << "|" << setw(13) << left << monitor->student_code << "|" << setw(29) << left << monitor->name << "|" << setw(9) << left << monitor->age << "|" << setw(20) << left << monitor->hometown << "|" << setw(11) << left << monitor->gpa.total_score << "|" << endl;
		cout << "+-------------+-----------------------------+---------+--------------------+-----------+" << endl;
	}
	void cout_noc()
	{
		cout << "\t\t[6] In ra so lop co trong truong" << endl;
		cout << "\t(!) So lop co trong truong la: " << number_of_class << endl;
	}
private:
};
int main()
{
	lop_hoc* A = new lop_hoc;
	while (true)
	{
		int n;
		cout << "\t\t ~~~~~ DANH SACH THAO TAC ~~~~~" << endl
			 << "\t(1): Them hoc sinh vao lop" << endl
			 << "\t(2): Xoa hoc sinh khoi lop" << endl
			 << "\t(3): Sua thong tin hoc sinh" << endl
			 << "\t(4): Thiet lap lop truong cho lop" << endl
			 << "\t(5): In ra danh sach lop" << endl
			 << "\t(6): In ra so lop co trong truong" << endl
			 << "\t(7): Thoat chuong trinh" << endl;
		cout << "(?) Nhap lua chon cua ban: "; cin >> n;
		while (n > 7 || n < 1)
		{
			cout << "Lua chon khong hop le! " << endl;
			cout << "Nhap lai lua chon cua ban: ";
			cin >> n;
		}
		switch (n)
		{
		case 1:
		{
			A->add_student();
			break;
		}
		case 2:
		{
			A->delete_student();
			break;
		}
		case 3:
		{
			A->edit_information();
			break;
		}
		case 4:
		{
			A->set_monitor();
			break;
		}
		case 5:
		{
			A->cout_student();
			break;
		}
		case 6:
		{
			A->cout_noc();
			break;
		}
		case 7:
		{
			delete A;
			return 0;
		}
		}
		cout << "Nhan enter de tiep tuc chuong trinh!";
		cin.ignore(2);
		system("cls");
	}
}