#include<iostream>
#include<iomanip>
#include<string>
#include<Windows.h>
#include<fstream>
#include<sstream>
#include<stdlib.h>
using namespace std;
string filename = "data.txt";

float diemTot = 8;
float diemKha = 6;
float diemTB = 4;

int collumWidthName = 25;
int collumWidthAge = 5;
int collumWidthPoint = 4;
struct Student {
	string name;
	int age;
	float point;
	Student* next = NULL;
	void printStudent() {
		cout << left << setw(collumWidthName) << name << "|" << left << setw(collumWidthAge) << age << "|" << left << setw(collumWidthPoint) << point << "|" << endl;
	}
};
struct LinkList {
	Student* head = NULL;
	int length = 0;

	//In
	void printListStudent()
	{
		int i = 1;
		Student* p = head;
		printRow();
		cout << endl;
		printCollumName();
		printRow();
		cout << endl;
		while (p != NULL)
		{
			cout << "\t\t\t" << "|" << left << setw(4) << i << "|";	p->printStudent();
			p = p->next;
			i++;
		}
		printRow();
		cout << endl;

	}
	void printCollumWidthSTT()
	{
		printTab(3);
		
		for (int i = 1; i < 4 + 2; i++)
		{
			if (i == 1)
				cout << "+";
			else
				cout << "-";
		}
	}
	void printCollumWidthName()
	{
		for (int i = 1; i < collumWidthName + 2; i++)
		{
			if (i == 1)
				cout << "+";
			else
				cout << "-";
		}
	}
	void printCollumWidthAge()
	{
		for (int i = 1; i < collumWidthAge + 2; i++)
		{
			if (i == 1)
				cout << "+";
			else
				cout << "-";
		}
	}
	void printCollumWidthPoint()
	{
		for (int i = 1; i <= collumWidthPoint + 2; i++)
		{
			if (i == 1 || i == collumWidthPoint + 2)
				cout << "+";
			else
				cout << "-";
		}
	}
	void printTab(int tab)
	{
		for (int i = 1; i <= tab; i++)
		{
			cout << "\t";
		}
	}
	void printRow()
	{
		printCollumWidthSTT(); printCollumWidthName(); printCollumWidthAge(); printCollumWidthPoint();
	}
	void printCollumName()
	{
		printTab(2); cout << "        "; 
		cout <<"|"<<left<<setw(4)<<"STT" << left << setw(collumWidthName+1) << "|HO TEN" << left << setw(collumWidthAge+1) << "|TUOI"  << left << setw(collumWidthPoint+1) << "|DIEM" << "|" << endl;
	}
	//Them
	Student* createStudent(string  namE, int agE, float poinT)
	{
		Student* student = new Student;
		student->name = namE;
		student->age = agE;
		student->point = poinT;
		student->next = NULL;
		return student;
	}
	void appendStudent(string  namE, int agE, float poinT)
	{
		Student* student = createStudent(namE, agE, poinT);
		length++;
		if (head == NULL)
		{
			head = student;
			return;
		}
		Student* p = head;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = student;

	}	
	void addStudent()
	{
		string name; int age; float point;
		cin.ignore();
		cout << "(?) Enter name: "; 
		getline(cin, name);

		cout << "(?) Enter age: "; cin >> age;
		cout << "(?) Enter point: "; cin >> point;
		appendStudent(name, age, point);
		cout << "(!) Da them sinh vien " << name << " Thanh cong" << endl;
	}
	//Sua
	void updateStudentData(string namE, int pos)
	{
		if (pos<1 || pos> length)
		{
			cout << "Out of range" << endl;
			return;
		}
		Student* StudentNeedUpdate = findByPosition(pos);
		if (StudentNeedUpdate != NULL)
		{
			StudentNeedUpdate->name = namE;
		}
	}
	void updateStudentData(float poinT, int pos)
	{
		if (pos<1 || pos> length)
		{
			cout << "Out of range" << endl;
			return;
		}
		Student* StudentNeedUpdate = findByPosition(pos);
		if (StudentNeedUpdate != NULL)
		{
			StudentNeedUpdate->point = poinT;
		}
	}
	void updateStudentData(int agE, int pos)
	{
		if (pos<1 || pos> length)
		{
			cout << "Out of range" << endl;
			return;
		}
		Student* StudentNeedUpdate = findByPosition(pos);
		if (StudentNeedUpdate != NULL)
		{
			StudentNeedUpdate->age = agE;
		}
	}
	//Xoa
	void deleteStudent(int pos)
	{
		if (pos > length || pos < 1)
		{
			cout << "Out of range" << endl;
			return;
		}
		if (pos == 1)
		{
			Student* p = head;
			head = head->next;
			delete p;
			return;
		}
		int index = 2;
		Student* p = head->next;
		Student* p_back = head;
		while (p != NULL)
		{
			if (index == pos)
			{
				p_back->next = p->next;
				delete p;
				return;
			}
			p_back = p;
			p = p->next;
			index++;
		}
	}
	//Tim kiem
	Student* findByPosition(int pos)
	{
		if (pos > length || pos < 1)
		{
			return NULL;
		}

		int index = 1;
		for (Student* p = head; p != NULL; p = p->next)
		{
			if (index == pos)
				return p;
			index++;
		}
	}
	LinkList* findByWord(string word)
	{
		LinkList* result = new LinkList;
		Student* p = head;
		while (p != NULL)
		{
			if (p->name.find(word) != string::npos)
			{
				result->appendStudent(p->name, p->age, p->point);
			}
			p = p->next;
		}
		return result;
	}
	//Sap xep
	void swap(int& a, int& b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
	void swap(float& a, float& b)
	{
		float tmp = a;
		a = b;
		b = tmp;
	}
	void swap(string& a, string& b)
	{
		string tmp = a;
		a = b;
		b = tmp;
	}
	string extractName(string fullName) {
		// Tìm vị trí khoảng trắng cuối cùng trong chuỗi họ tên
		int lastSpacePos = fullName.find_last_of(" ");

		if (lastSpacePos == string::npos) {
			// Nếu không tìm thấy khoảng trắng thì trả về toàn bộ chuỗi họ tên
			return fullName;
		}
		else {
			// Trích xuất tên từ vị trí sau khoảng trắng cuối cùng đến hết chuỗi
			return fullName.substr(lastSpacePos + 1);
		}
	}
	void SortByName()
	{
		for (Student* p = head; p->next != NULL; p = p->next)
		{
			for (Student* q = p->next; q != NULL; q = q->next)
			{
				if (extractName(p->name) > extractName(q->name))
				{
					swap(p->name, q->name);
					swap(p->age, q->age);
					swap(p->point, q->point);
				}
			}
		}
	}
	void SortByAge()
	{
		for (Student* p = head; p->next != NULL; p = p->next)
		{
			for (Student* q = p->next; q != NULL; q = q->next)
			{
				if (p->age > q->age)
				{
					swap(p->name, q->name);
					swap(p->age, q->age);
					swap(p->point, q->point);
				}
			}
		}
	}
	void SortByPoint()
	{
		for (Student* p = head; p->next != NULL; p = p->next)
		{
			for (Student* q = p->next; q != NULL; q = q->next)
			{
				if (p->point > q->point)
				{
					swap(p->name, q->name);
					swap(p->age, q->age);
					swap(p->point, q->point);
				}
			}
		}
	}
	//Thong ke
	float avgStudentPoint()
	{
		float sumPoint = 0;
		int NumberOfSV = 0;
		Student* p = head;
		while (p != NULL)
		{
			sumPoint += p->point;
			NumberOfSV++;
			p = p->next;
		}
		return (float)(sumPoint / NumberOfSV);
	}
	float tiLeHSG()
	{
		int soHSG = 0;
		Student* p = head;
		while (p != NULL)
		{
			if (p->point>=diemTot && p->point<=10)
			{
				soHSG++;
			}
			p = p->next;
		}
		return (float)((soHSG * 100) / length);
	}
	float tiLeHSK()
	{
		int soHSK = 0;
		Student* p = head;
		while (p != NULL)
		{
			if (p->point >= diemKha && p->point < diemTot)
			{
				soHSK++;
			}
			p = p->next;
		}
		return (float)((soHSK * 100) / length);
	}
	float timDiemCaoNhat()
	{
		float diemCaoNhat = head->point;
		Student* p = head;
		while (p != NULL)
		{
			if (p->point > diemCaoNhat)
			{
				diemCaoNhat = p->point;
			}
			p = p->next;
		}
		return diemCaoNhat;
	}
	LinkList* danhSachSVCoDiemCaoNhatLop()
	{
		LinkList* result = new LinkList;
		float diemCaoNhat = timDiemCaoNhat();
		Student* p = head;
		while (p != NULL)
		{
			if (p->point == diemCaoNhat)
			{
				result->appendStudent(p->name, p->age, p->point);
			}
			p = p->next;
		}
		return result;
	}
	//File
	void loadStudentFromFile(string filename)
	{
		ifstream file(filename);
		string name;
		int age;
		float point;
		string line;
		int length = 0;
		while (getline(file, line)) {
			stringstream ss(line);
			string token;

			getline(ss, token, ';');
			name = token;
			getline(ss, token, ';');
			age = stoi(token);

			getline(ss, token, ';');
			point = stof(token);
			appendStudent(name, age, point);
			length++;
		}
	}
	void writeListStudentToFile(string filename)
	{
		ofstream file(filename);
		if (!file.is_open())
		{
			cout << "Error: Could not open file" << endl;
			return;
		}

		Student* p = head;
		while (p != NULL)
		{
			file << p->name << ";" << p->age << ";" << p->point << endl;
			p = p->next;
		}
	}
};

int main()
{

	LinkList* L = new LinkList;
	L->loadStudentFromFile(filename);
	int flag = 1;
	
	while (true)
	{
		int select;
		int sothutu;
		cout << "Danh sach thao tac: " << endl
			<< "1 -  In danh sach sinh vien" << endl
			<< "2 - Them" << endl
			<< "3 - Sua" << endl
			<< "4 - Xoa " << endl
			<< "5 - Tim kiem" << endl
			<< "6 - Sap xep" << endl
			<< "7 - Thong ke" << endl
			<< "8 - Sao luu" << endl
			<< "9 - Thoat" << endl
			<< "Nhap lenh: ";
		cin >> select;

		switch (select)
		{
		case 1:
		{
			cout << "[" << select << "]" << " In danh sach sinh vien:" << endl;
			L->printListStudent();
			break;
		}
		case 2:
		{
			cout << "[" << select << "]" << "Them sinh vien:" << endl;
			L->addStudent();
			break;
		}
		case 3:
		{
			string name; int age, luachon; float point;
			cout << "[" << select << "]" << "Sua thong tin sinh vien:" << endl;
			cout << "\t\t\t" << "(?) Nhap STT sinh vien can sua: "; cin >> sothutu;
			cout << "\t\t\t" << "(!) Ban muon sua gi" << endl
				<< "\t\t\t1 - Ten" << endl
				<< "\t\t\t2 - Tuoi " << endl
				<< "\t\t\t3 - Diem" << endl
				<< "\t\t\t(?) Nhap lua chon cua ban: "; cin >> luachon;
			if (luachon == 1)
			{
				cout << "\t\t\tNhap ten: "; cin >> name;
				L->updateStudentData(name, sothutu);
			}
			else if (luachon == 2)
			{
				cout << "\t\t\tNhap tuoi: "; cin >> age;
				L->updateStudentData(age, sothutu);
			}
			else
			{
				cout << "\t\t\tNhap diem: "; cin >> point;
				L->updateStudentData(point, sothutu);
			}
			cout << "\t\t\t(!) Sua thong tin sinh vien thanh cong" << endl;
			break;
		}
		case 4:
		{
			cout << "[" << select << "]" << "Xoa sinh vien:" << endl;
			cout << "\t\t\t" << "(?) Nhap STT sinh vien can xoa: "; cin >> sothutu;
			L->deleteStudent(sothutu);
			cout << "\t\t\t(!) Xoa sinh vien co so thu tu " << sothutu << " thanh cong" << endl;
			break;
		}
		case 5:
		{
			string searchStudent;
			cout << "[" << select << "]" << "Tim kiem:" << endl;
			cout << "\t\t\t" << "(?) Nhap ki tu "; cin >> searchStudent;
			LinkList* search = L->findByWord(searchStudent);
			search->printListStudent();
			break;
		}
		case 6: 
		{
			int luachon1;
			cout << "[" << select << "]" << "Sap xep:" << endl
				<< "\t\t\t(!) 1 - Theo ten" << endl
				<< "\t\t\t(!) 2 - Theo tuoi" << endl
				<< "\t\t\t(!) 3 - Theo diem" << endl
				<< "\t\t\t" << "(?) Nhap lua chon "; cin >> luachon1;

			if (luachon1 == 1)
			{
				L->SortByName();
				cout << "\t\t\t(!) Da sap xep danh sach sien vien theo ten" << endl;
			}
			else if (luachon1 == 2)
			{
				L->SortByAge();
				cout << "\t\t\t(!) Da sap xep danh sach sien vien theo tuoi" << endl;
			}
			else
			{
				L->SortByPoint();
				cout << "\t\t\t(!) Da sap xep danh sach sien vien theo diem" << endl;
			}
			break;
		}
		case 7: 
		{
			cout << "[" << select << "]" << "Thong ke:" << endl
				<< "\t\t\t(!) Diem trung binh: " << L->avgStudentPoint() << endl
				<< "\t\t\t(!) Ti le hoc sinh gioi: " << L->tiLeHSG() << "%" << endl
				<< "\t\t\t(!) Ti le hoc sinh kha: " << L->tiLeHSK() << "%" << endl
				<< "\t\t\t(!) Diem cao nhat trong danh sach sinh vien: " << L->timDiemCaoNhat() << endl
				<< "\t\t\tDanh sach sinh vien co diem cao nhat" << endl;
			LinkList* dsSVDiemMax = L->danhSachSVCoDiemCaoNhatLop();
			dsSVDiemMax->printListStudent();
			break;
		}
		case 8:
		{
			cout << "[" << select << "]" << "Sao luu:" << endl;
			L->writeListStudentToFile(filename);
			cout << "\t(!) Da sao luu danh sach sinh vien vao file" << endl;
			break;
		}
		case 9:
		{
			cout << "Thoat chuong trinh";
			flag = 0;
			break;
		} 
		}
		if (flag == 0)
			break;
		system("pause");
		system("cls");
	}
}
