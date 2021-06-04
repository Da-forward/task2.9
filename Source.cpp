#include <locale>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <Windows.h>
#include <string>
#include <list>

using namespace std;
struct Shopper
{
	string family;
	string name;
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

struct Shopper* createArr(struct Shopper* arr, int& count_el) {
	cout << "������� ����������: ";
	cin >> count_el;
	arr = new Shopper[count_el];
	return arr;
}

//������������� ��� ������ ������ �� ������ � ������������ �������
void inputOnItemByIndex(struct Shopper* arr, int i) {

	cout << "������� ������� : ";
	cin >> arr[i].family;
	cout << "������� ��� : ";
	cin >> arr[i].name;
	cout << "������� �������� : ";
	cin >>  arr[i].patronymic;
	cout << "������� ����� : ";
	cin >> arr[i].adress;
	cout << "������� �������: ";
	cin >> arr[i].telephone;
	cout << "����� �������� ����� : ";
	cin >> arr[i].creditka;
}

struct Shopper* inputToArrStruct(struct Shopper* arr, int& count_el) {

	cout << "������� ����������: ";
	cin >> count_el;
	arr = new Shopper[count_el];

	for (int i = 0; i < count_el; i++) {
		inputOnItemByIndex(arr, i);
	}

	return arr;
}



void initDataFromFile(struct Shopper* arr, int& count_el) {
	fstream f;
	string str;
	f.open("data.txt", ios::in);
	if (f)
	{
		for (int i = 0; i < count_el; i++) { // ����� ����������� ��������� �� �����
			for (int k = 0; k < 5; k++) { 
				getline(f, str);
				string str_new = str;
				switch (k)
				{
				case 0:
					arr[i].family = str;
					break;
					case 1: 
						arr[i].name = str;
						break;
					case 2:
						arr[i].patronymic = str;
						break;
					case 3:
						arr[i].adress = str;
						break;
					case 4:
						arr[i].telephone = str;
						break;
					case 5:
						arr[i].creditka = str;
						break;
				default:
					cout << "��������� ������";
					break;
				}
			}
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
			if (i == 1) {  // ����� ������ ���� 5
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

void save(struct Shopper* arr, int count) {
	fstream f;
	// �������� �����
	// ������� ���� � �������� ������������ ������������ ���� ��� ������� �����
	// �������� �������� �� ������������� �����
	ofstream filename("data.txt");
	filename.close();

	f.open("data.txt");
	for (int i = 0; i < count; i++)
	{
		f << arr[i].family << endl; // �������� ������ � ������ � ����
		
		f << arr[i].name << endl; // �������
		f << arr[i].patronymic << endl; // ��������
		f << arr[i].adress << endl; // �����
		f << arr[i].telephone << endl; // �������
		f << arr[i].creditka << endl; // ��������
	}
	f.close();

}

// ����������� ������ �� ����� ��������� � ������, �� ������� ��������

void copyDataStructsByItem(struct Shopper* prev, int posPrev, struct Shopper* current, int posCurrent) {

	current[posCurrent].family = prev[posPrev].family;
	current[posCurrent].name = prev[posPrev].name;
	current[posCurrent].patronymic = prev[posPrev].patronymic;
	current[posCurrent].adress = prev[posPrev].adress;
	current[posCurrent].telephone = prev[posPrev].telephone;
	current[posCurrent].creditka = prev[posPrev].creditka;

}


// ���������� � i-��� ������� � ������������ ������
Shopper* addInItem(struct Shopper* arr, int& count_el) {

	int newCountEl = 0;
	int position = 0;
	cout << "������� �������: ";
	cin >> position;
	count_el += 1; // �������� ����������, �.� ����������� �� 1
	Shopper* arrNew = new Shopper[count_el]; // ����� ������ � ������ ����� �����������
	for (int i = 0; i < count_el - 1; i++) {
		// ���� �� ����� ��� �� ����� �����������, �� �������� ������
		if (i < position) { //
			copyDataStructsByItem(arr, i, arrNew, i);
		}
		// ����� ���������� ���������������� �� ������ �������
		else {
			if (i == position) { 
				inputOnItemByIndex(arrNew, position);
			}
			copyDataStructsByItem(arr, i, arrNew, i + 1);
		}
	}

	cout << "������ ��������� � ���������!";
	system("pause");

	return arrNew;

}

// �������� �� i-��� ������� � ������������ ������
Shopper* deleteInItem(struct Shopper* arr, int& count_el) {

	int newCountEl = 0;
	int position = 0;
	cout << "������� �������: ";
	cin >> position;
	count_el -= 1; // �������� ����������, �.� ��������� �� 1
	Shopper* arrNew = new Shopper[count_el]; // ����� ������ � ������ ����� �����������
	for (int i = 0; i < count_el; i++) {
		// ���� �� ����� ��� �� ����� �����������, �� �������� ������
		if (i < position) { //
			copyDataStructsByItem(arr, i, arrNew, i);
		}
		// ����� ���������� ���������������� �� ������ �������
		else {
			copyDataStructsByItem(arr, i + 1, arrNew, i);
		}
	}


	cout << "������ ��������� � ���������!";
	system("pause");

	return arrNew;

}


// ���������� ����� ������ � ������������ ������
Shopper* appendInExistArr(struct Shopper* arr, int& count_el) {

	int newCountEl = 0;
	cout << "������� ���������� ����� �����������: ";
	cin >> newCountEl;
	count_el += newCountEl; // �������� ����������, �.� ���������� � �������, ����� ��������� �������������
	Shopper* arrNew = new Shopper[count_el]; // ����� ������ � ������ ����� �����������
	for (int i = 0; i < count_el; i++) {
		// ���� �� ����� ��� �� ����� �����������, �� �������� ������
		if (i < count_el - newCountEl) { //  count_el - newCountEl =  ���������� ��������� � ������ �������
			//copyDataStructs(arr, count_el - newCountEl, arrNew);
			copyDataStructsByItem(arr, i, arrNew, i);
		}
		// ����� ���������� ���������������� �� ������ �������
		else {
			inputOnItemByIndex(arrNew, i);
		}
	}


	cout << "������ ��������� � ���������!";
	system("pause");

	return arrNew;

}


void structureInference(struct Shopper* arr, int& count_el) {

	for (int i = 0; i < count_el; i++) {
		cout << arr[i].family << endl;
		cout << arr[i].name << endl;// ���
		cout << arr[i].patronymic << endl; // ��������
		cout << arr[i].adress << endl; // �����
		cout << arr[i].telephone << endl; // �������
		cout << arr[i].creditka << endl;// ����� ��������� �����
	}
	system("pause");
}
// ����� i-��� ���������
void structureInferenceItem(struct Shopper* arr, int index) {
	cout << arr[index].family << endl;
	cout << arr[index].name << endl;// ���
	cout << arr[index].patronymic << endl; // ��������
	cout << arr[index].adress << endl; // �����
	cout << arr[index].telephone << endl; // �������
	cout << arr[index].creditka << endl;// ����� ��������� �����
}


// 11 ������� 
Shopper* deleteFirstField(struct Shopper* arr, int& count_el) {
	string val;
	cout << "������� �������� ����: ";
	cin >> val;


	// �����
	int count = 0;
	for (int i = 0; i < count_el; i++) {
		if (strcmp(val.c_str(), arr[i].family.c_str()) == 0) {
			count++;
		}
	}

	Shopper* arrNew = new Shopper[count_el - count]; // ����� ������ � ������ ����� �����������
	int countArrNew = 0;

	for (int i = 0; i < count_el; i++) {
		if (strcmp(val.c_str(), arr[i].family.c_str()) != 0) {
			copyDataStructsByItem(arr, i, arrNew, countArrNew); \
				countArrNew++;
		}
	}
	count_el -= count;
	return arrNew;

}

//������� 6
void sortingArray_of_StructuresFirst(struct Shopper* arr, int count_el) {
	Shopper* tmp = new Shopper[1];
	for (int i = 0; i < count_el - 1; i++) {
		int min = i;
		for (int j = i + 1; j < count_el; j++) {
			if (arr[j].family < arr[min].family)

				min = j;
		}
		if (min != i) {
			/*tmp = min
			min = i
			a = t*/
			copyDataStructsByItem(arr, min, tmp, 0);
			copyDataStructsByItem(arr, i, arr, min);
			copyDataStructsByItem(tmp, 0, arr, i);
		}
	}
}

void sortingArray_of_StructuresPatronymic(struct Shopper* arr, int count_el, string str) {
	Shopper* tmp = new Shopper[1];
	for (int i = 0; i < count_el - 1; i++) {
		int min = i;
		for (int j = i + 1; j < count_el; j++) {
			if (arr[j].patronymic < arr[min].patronymic)

				min = j;
		}
		if (min != i) {
			/*tmp = min
			min = i
			a = t*/
			copyDataStructsByItem(arr, min, tmp, 0);
			copyDataStructsByItem(arr, i, arr, min);
			copyDataStructsByItem(tmp, 0, arr, i);
		}
	}
}

void sortingArray_of_StructuresName(struct Shopper* arr, int count_el, string str) {
	Shopper* tmp = new Shopper[1];
	for (int i = 0; i < count_el - 1; i++) {
		int min = i;
		for (int j = i + 1; j < count_el; j++) {
			if (arr[j].name < arr[min].name)

				min = j;
		}
		if (min != i) {
			/*tmp = min
			min = i
			a = t*/
			copyDataStructsByItem(arr, min, tmp, 0);
			copyDataStructsByItem(arr, i, arr, min);
			copyDataStructsByItem(tmp, 0, arr, i);
		}
	}
}

//7 �������
void sortingArray_of_Structures3(struct Shopper* arr, int count_el) {
	string str;
	Shopper* tmp = new Shopper[1];
	for (int i = 0; i < count_el - 1; i++) {
		int min = i;
		for (int j = i + 1; j < count_el; j++) {
			if (arr[j].family < arr[min].family)

				min = j;
		}
		if (min != i) {
			/*tmp = min
			min = i
			a = t*/
			copyDataStructsByItem(arr, min, tmp, 0);
			copyDataStructsByItem(arr, i, arr, min);
			copyDataStructsByItem(tmp, 0, arr, i);
		}
	}

	for (int i = 0; i < count_el - 1; i++) {
		for (int j = i + 1; j < count_el; j++) {
			if (strcmp(arr[i].family.c_str(), arr[j].family.c_str()) == 0) {
				sortingArray_of_StructuresName(arr, count_el, str);
			}

		}
	}

	for (int i = 0; i < count_el - 1; i++) {
		for (int j = i + 1; j < count_el; j++) {
			if (strcmp(arr[i].name.c_str(), arr[j].name.c_str()) == 0) {
				sortingArray_of_StructuresPatronymic(arr, count_el, str);
			}

		}
	}


}



void menuItem() {
	cout << "0. �������" << endl;
	cout << "1. ���" << endl;
	cout << "2. ��������" << endl;
	cout << "3. �����" << endl;
	cout << "4. �������" << endl;
	cout << "5. ��������" << endl;
}

void searcStuctByItemSolution(int i, string val, struct Shopper* arr, int count_el) { // i - ����� ���������� ����
	cout << "����������:" << endl;
	switch (i)
	{
	case 0:
		for (int i = 0; i < count_el; i++) {
			if (strcmp(val.c_str(), arr[i].family.c_str()) == 0) {
				structureInferenceItem(arr, i);
				cout << "######" << endl;
			}
		}
		break;
	case 1:
		for (int i = 0; i < count_el; i++) {
			if (strcmp(val.c_str(), arr[i].name.c_str()) == 0) {
				structureInferenceItem(arr, i);
				cout << "######" << endl;
			}
		}
		break;
	case 2:
		for (int i = 0; i < count_el; i++) {
			if (strcmp(val.c_str(), arr[i].patronymic.c_str()) == 0) {
				structureInferenceItem(arr, i);
				cout << "######" << endl;
			}
		}
		break;
	case 3:
		for (int i = 0; i < count_el; i++) {
			if (strcmp(val.c_str(), arr[i].adress.c_str()) == 0) {
				structureInferenceItem(arr, i);
				cout << "######" << endl;
			}
		}
		break;
	case 4:
		for (int i = 0; i < count_el; i++) {
			if (strcmp(val.c_str(), arr[i].telephone.c_str()) == 0) {
				structureInferenceItem(arr, i);
				cout << "######" << endl;
			}
		}
		break;
	case 5:
		for (int i = 0; i < count_el; i++) {
			if (strcmp(val.c_str(), arr[i].creditka.c_str()) == 0) {
				structureInferenceItem(arr, i);
				cout << "######" << endl;
			}
		}
		break;
	default:
		system("cls");
		cout << "������ ������������ ����� �� ������ \n";
		system("pause");
		break;
	}

}

// ���� �� ��������� ����
void searcStuctByItem(struct Shopper* arr, int count_el) {
	string val;
	int num = 0;
	menuItem();
	cout << "�������� ����� ����, �� �������� ����� ������: ";
	cin >> num;
	cout << "������� ����� ��� ������: ";
	cin >> val;
	searcStuctByItemSolution(num, val, arr, count_el);
	system("pause");


}

// ���������� �������� ����
string getNameItem(int i) {

	switch (i)
	{
	case 0:
		return "�������";
		break;
	case 1:
		return "���";
		break;
	case 2:
		return "��������";
		break;
	case 3:
		return "�����";
		break;
	case 4:return "�������";

		break;
	case 5:
		return "����� ��������� �����";
		break;
	default:
		break;
	}

	return "";

}
void structuralChangeSolution(int num, int i, string val, struct Shopper* arr) { // i - ����� ���������� ����, num - ����� ��������, ��������������
	
	switch (i)
	{
	case 0:
		arr[num].family = val;
		break;
	case 1:
		arr[num].name = val;
		break;
	case 2:
		arr[num].patronymic = val;
		break;
	case 3:
		arr[num].adress = val;
		break;
	case 4:
		arr[num].telephone= val;
		break;
	case 5:
		arr[num].creditka = val;
		break;
	default:
		
		break;
	}

}
// 9 ��������
void structuralChange(struct Shopper* arr, int count_el) {
	system("cls");
	int num; // ����� ���������, ������� ����� ��������
	cout << "������� ����� ���������, ������� ����� ������������� :";
	cin >> num;
	string anw; // ����� �� ������ 
	for (int i = 0; i < 5; i++) { // �������� 6 (���������� ����� � ���������)
		cout << "����� �� �� ������ �������� ���� " << getNameItem(i)<< endl;
		cout << "������� 'y', ���� ��������" << endl;
		cin >> anw;
		if (strcmp(anw.c_str(), "y") == 0) {
			string newVal;
			cout << "������� ����� �������� ����:" << endl;
			cin >> newVal;
			structuralChangeSolution(num ,i, newVal, arr);

		}
	}

	cout << "������� ��������!" << endl;
	system("pause");
	
}



void menu() {
	Shopper* arr = 0;
	int count_el = 0; // ������� �������� ��� ������
	// ������� ���������

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
			arr = getArrFromFile(arr, count_el);
			break;
		case 3:
			save(arr, count_el);
			break;
		case 4:
			arr = appendInExistArr(arr, count_el);
			break;
		case 5:
			arr = addInItem(arr, count_el);
			break;
		case 6:
			sortingArray_of_StructuresFirst(arr, count_el);
			break;
		case 7:
			sortingArray_of_Structures3(arr, count_el);
			break;
		case 8:
			searcStuctByItem(arr, count_el);
			break;
		case 9:
			structuralChange(arr, count_el);
			break;
		case 10:
			arr = deleteInItem(arr, count_el);
			break;
		case 11:
			arr = deleteFirstField(arr, count_el);
			break;
		case 12:
			structureInference(arr, count_el);
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



int main(int argc, char* argv[])
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	menu();

	//ofstream filename("data.txt");

	return 0;
}