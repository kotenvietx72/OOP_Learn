#include<iostream>
using namespace std;

class patient {
public:
	patient(int a, string b)
	{
		patient_code = a;
		name = b;
	}
	void setpcode()
	{
		cout << "Ma so cua benh nhan la: " << patient_code << endl;
	}
	void setname()
	{
		cout << "Ten cua benh nhan la: " << name << endl;
	}
	void getdate(int a)
	{
		datetime = a;
	}
	void setdate()
	{
		cout <<"Ngay nhap vien cua benh nhan la: " << datetime << endl;
	}
	void getcode(string a)
	{
		disease_code = a;
	}
	void setcode()
	{
		cout <<"Benh cua benh nhan la: " << disease_code << endl;
	}
	void getfee(float a)
	{
		hospital_fee = a;
	}
	void setfee()
	{
		cout <<"Tong vien phi la: " << hospital_fee << endl;
	}
private:
	int patient_code;
	string name;
	int datetime;
	string disease_code;
	float hospital_fee;
};
int main()
{
	patient* a = new patient(1, "Viet Anh");
	a->setpcode();
	a->setname();
	a->getdate(25); a->setdate();
	a->getcode("Benh Da Day"); a->setcode();
	a->getfee(999999); a->setfee();
}