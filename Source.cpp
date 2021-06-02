

 #include <locale>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <Windows.h>
#include <string>

using namespace std;
struct Shopper
{
	string name;
	string family;
	string patronymic;
	string adress;
	string telephone;
	string creditka;
};


void textMenu() {
	cout << "1. ���� � ������ �������� \n"; // +
	cout << "2. ������ ������ � ������ �������� �� ���������� ����� \n"; 
	cout << "3. ������ ������ � ��������� ���� �� ������ �������� \n"; // +
	cout << "4. ���������� ������ � ������ �������� \n";
	cout << "5. ������� ������ � ������ �������� �� i-� ������� (��������� � 1) \n";
	cout << "6. ���������� ������� �������� �� ������� ����, ��������� � ��������� \n";
	cout << "7. ���������� ������� �������� �� ���� ������ ������ \n";
	cout << "8. ����� � ������� �������� �� ��������� ��������� \n";
	cout << "9. ��������� �������� ��������� \n";
	cout << "10. �������� i-�� ��������� �� ������� (��������� � 1) \n";
	cout << "11. �������� �������� �� ������� �� ��������� �������� ������� ���� \n";
	cout << "12. ����� �� ����� ������� �������� \n";
	cout << "13. ������� ��� ��������� \n";
}

struct Shopper* inputToArrStruct(struct Shopper* arr, int & count_el) {
	
	cout << "";
	cin >> count_el;

	arr =  new Shopper[count_el];

	for (int i = 0; i < count_el; i++) {
		cout << "������� ��� : ";
		cin>> arr[i].name;
		//cout << "������� ������� : ";
		//cin>> arr[i].family;
		//cout << "������� �������� : ";
		//cin >>  arr[i].patronymic;
		//cout << "������� ����� : ";
		//cin >> arr[i].adress;
		//cout << "������� �������: ";
		//cin >> arr[i].telephone;
		//cout << "����� �������� ����� : ";
		//cin >> arr[i].creditka;
	}

	return arr;
}

void initDataFromFile(struct Shopper* arr, int& count_el) {
	fstream f;
	string str;
	f.open("data.txt", ios::in);
	int i = 0; // ������� �� �������
	if (f)
	{
		while (getline(f, str)){ // ���������� ���������� �� �����
			// ���������� ��� ���� ����� ( ����� ������� � switch � ��������� �������)
			string str_new = str;
			if (i == 0) {
				arr[i].name = str_new;
			}

			
			// �������� if �� ��������� i if i> 5 ��� 6
			i++;
			f.close(); // ������� ��� ��� 1 �������

		}
		f.close();
	}
	else
		cout << "Error opening the file for reading!" << endl;

}


// ������ ���������� ��������, ���������� � �����
int getCountElementInFile() {
	int count = 0;
	fstream f;
	string str;
	int i = 0; // ������� ���������� �������
	f.open("data.txt", ios::in);
	if (f)
	{
		while (getline(f, str)) { // ���������� ���������� �� �����
			i++;
			if (i == 5) {
				count++;
				i = 0;
			}
			
		}
		f.close();
	}
	else
		cout << "Error opening the file for reading!" << endl;
	return count;
}

Shopper* getArrFromFile(Shopper* arr, int& count_el) {
	count_el = getCountElementInFile(); // ������� ���������� ��������, ����������� � �����
	arr = new Shopper[count_el]; // ������� ��� ��� ��������� ������
	initDataFromFile(arr, count_el); // ��������� ��������� ������ ������� �� �����
	return arr;
}

void save( struct Shopper* arr, int count) {
	fstream f;
	// �������� �����
	// ������� ���� � �������� ������������ ������������ ���� ��� ������� �����
	// �������� �������� �� ������������� �����
	ofstream filename("data.txt");
	filename.close();
	//
	f.open("data.txt");

	for (int i = 0; i < count; i++)
	{
		//getline(cin, str);
		f << arr[i].name << endl; // �������� ������ � ������ � ����
		/* �����!
		f << arr[i].family << endl; // �������
		f << arr[i].patronymic << endl; // ��������
		f << arr[i].adress << endl; // �����
		f << arr[i].telephone << endl; // �������
		f << arr[i].creditka << endl; // ��������
		*/
	}
	f.close();

}



void menu() {
	Shopper * arr = 0;
	int count_el = 0;
	while (true) {
		int i = -1; // ����� ������ ����
		textMenu();
		cout << "�������� ����� ���� �� ������: ";
		cin >> i;
		switch (i)
		{
		case 1:
			arr = inputToArrStruct(arr, count_el);
			break;
		case 2:
			getArrFromFile(arr, count_el);
			break;
		case 3:
			save(arr, count_el);
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
		case 11:
			break;
		case 12:
			break;
		case 13:
			exit(0);
			break;

		default:
			system("cls");
			cout << "������ ������������ ����� �� ������ \n";
			system("pause");
			break;
		}
		system("cls");
	}
}



/*
void form(char* filename[10], int Kol)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int i;
	char* rejim = "\0";
	FILE* f;
	shopper s;
	if (Kol == 1) {
		rejim = "a";
	}
	if ((f = fopen(sFileName, rejim)) == NULL) exit(1);
	for (i = 0; i < Kol; i++) {
		cout << "������� ��� ����������: ";
		scanf("%s", &s.Name);
		cout << "������� ������: ";
		scanf("%s", &s.adress);
		cout << "������� ����� ��������: ";
		scanf("%s", &s.telephone);
		cout << "������� ����� �����: ";
		scanf("%s", &s.creditka);
		cout << endl;
		fwrite(&s, sizeof(shopper), 1, f);
		if (ferror(f) != NULL) exit(2);
	}
	fclose(f);
}
void vivod(char sFileName[10])
{
	FILE* f;
	shopper d;
	if ((f = fopen(sFileName, "r")) == NULL) exit(3);
	cout << "File - " << sFileName << endl;
	while (!feof(f)) {
		fread(&d, sizeof(shopper), 1, f);
		if (!feof(f)) {
			cout << "**************************\n";
			cout << "Familia: " << d.name << endl;
			cout << "Adress: " << d.0adress << endl;
			cout << "Telephone: " << d.telephone << endl;
			cout << "Nomer carti:" << d.creditka << endl;
			cout << "**************************\n";
		}
	}
	fclose(f);
}
*/

int main(int argc, char* argv[])
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	menu();

	//ofstream filename("data.txt");
	
	return 0;
}