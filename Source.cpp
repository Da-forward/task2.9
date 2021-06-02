

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
	cout << "1. Ввод в массив структур \n"; // +
	cout << "2. Чтение данных в массив структур из текстового файла \n"; 
	cout << "3. Запись данных в текстовый файл из массив структур \n"; // +
	cout << "4. Добавление данных в массив структур \n";
	cout << "5. Вставка записи в массив структур на i-ю позицию (нумерация с 1) \n";
	cout << "6. Сортировка массива структур по первому полю, входящему в структуру \n";
	cout << "7. Сортировка массива структур по трем первым полямс \n";
	cout << "8. Поиск в массиве структур по заданному параметру \n";
	cout << "9. Изменение заданной структуры \n";
	cout << "10. Удаление i-ой структуры из массива (нумерация с 1) \n";
	cout << "11. Удаление структур из массива по заданному значению первого поля \n";
	cout << "12. Вывод на экран массива структур \n";
	cout << "13. Закрыть эту программу \n";
}

struct Shopper* inputToArrStruct(struct Shopper* arr, int & count_el) {
	
	cout << "";
	cin >> count_el;

	arr =  new Shopper[count_el];

	for (int i = 0; i < count_el; i++) {
		cout << "Введите имя : ";
		cin>> arr[i].name;
		//cout << "Введите фамилию : ";
		//cin>> arr[i].family;
		//cout << "Введите отчество : ";
		//cin >>  arr[i].patronymic;
		//cout << "Введите адрес : ";
		//cin >> arr[i].adress;
		//cout << "Введите телефон: ";
		//cin >> arr[i].telephone;
		//cout << "Номер кредтной карты : ";
		//cin >> arr[i].creditka;
	}

	return arr;
}

void initDataFromFile(struct Shopper* arr, int& count_el) {
	fstream f;
	string str;
	f.open("data.txt", ios::in);
	int i = 0; // счетчик по массиву
	if (f)
	{
		while (getline(f, str)){ // построчное считывание из файла
			// Аналогично для всех полей ( можно вынести в switch в отдельную функцию)
			string str_new = str;
			if (i == 0) {
				arr[i].name = str_new;
			}

			
			// добавить if на зануление i if i> 5 или 6
			i++;
			f.close(); // удалить это для 1 запуска

		}
		f.close();
	}
	else
		cout << "Error opening the file for reading!" << endl;

}


// Считаю количество структур, записанных в файле
int getCountElementInFile() {
	int count = 0;
	fstream f;
	string str;
	int i = 0; // счетчик количества записей
	f.open("data.txt", ios::in);
	if (f)
	{
		while (getline(f, str)) { // построчное считывание из файла
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
	count_el = getCountElementInFile(); // получаю количество структур, посчитанных в файле
	arr = new Shopper[count_el]; // выделяю под эти структуры массив
	initDataFromFile(arr, count_el); // заполняем созданный массив данными из файла
	return arr;
}

void save( struct Shopper* arr, int count) {
	fstream f;
	// Создание файла
	// Сделать меню с вопросом использовать существующий файл или создать новый
	// добавить проверку на существование файла
	ofstream filename("data.txt");
	filename.close();
	//
	f.open("data.txt");

	for (int i = 0; i < count; i++)
	{
		//getline(cin, str);
		f << arr[i].name << endl; // записали строку с именем в файл
		/* ВЕРНО!
		f << arr[i].family << endl; // фамилию
		f << arr[i].patronymic << endl; // отчество
		f << arr[i].adress << endl; // адрес
		f << arr[i].telephone << endl; // телефон
		f << arr[i].creditka << endl; // кредитка
		*/
	}
	f.close();

}



void menu() {
	Shopper * arr = 0;
	int count_el = 0;
	while (true) {
		int i = -1; // номер пункта меню
		textMenu();
		cout << "Выберите пункт меню из списка: ";
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
			cout << "Введен неправильный номер из списка \n";
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
		cout << "Введите Имя покупателя: ";
		scanf("%s", &s.Name);
		cout << "Введите адресс: ";
		scanf("%s", &s.adress);
		cout << "Введите номер телефона: ";
		scanf("%s", &s.telephone);
		cout << "Введите номер карты: ";
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