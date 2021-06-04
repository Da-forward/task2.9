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

struct Shopper* createArr(struct Shopper* arr, int& count_el) {
	cout << "Введите количество: ";
	cin >> count_el;
	arr = new Shopper[count_el];
	return arr;
}

//Инициализация или замена данных по номеру в существующем массиве
void inputOnItemByIndex(struct Shopper* arr, int i) {

	cout << "Введите фамилию : ";
	cin >> arr[i].family;
	cout << "Введите имя : ";
	cin >> arr[i].name;
	cout << "Введите отчество : ";
	cin >>  arr[i].patronymic;
	cout << "Введите адрес : ";
	cin >> arr[i].adress;
	cout << "Введите телефон: ";
	cin >> arr[i].telephone;
	cout << "Номер кредтной карты : ";
	cin >> arr[i].creditka;
}

struct Shopper* inputToArrStruct(struct Shopper* arr, int& count_el) {

	cout << "Введите количество: ";
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
		for (int i = 0; i < count_el; i++) { // номер заполняемой структуры по счету
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
					cout << "Произошла ошибка";
					break;
				}
			}
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
			if (i == 1) {  // здесь должно быть 5
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

void save(struct Shopper* arr, int count) {
	fstream f;
	// Создание файла
	// Сделать меню с вопросом использовать существующий файл или создать новый
	// добавить проверку на существование файла
	ofstream filename("data.txt");
	filename.close();

	f.open("data.txt");
	for (int i = 0; i < count; i++)
	{
		f << arr[i].family << endl; // записали строку с именем в файл
		
		f << arr[i].name << endl; // фамилию
		f << arr[i].patronymic << endl; // отчество
		f << arr[i].adress << endl; // адрес
		f << arr[i].telephone << endl; // телефон
		f << arr[i].creditka << endl; // кредитка
	}
	f.close();

}

// копирование данных из одной структуры в другую, по номерам структур

void copyDataStructsByItem(struct Shopper* prev, int posPrev, struct Shopper* current, int posCurrent) {

	current[posCurrent].family = prev[posPrev].family;
	current[posCurrent].name = prev[posPrev].name;
	current[posCurrent].patronymic = prev[posPrev].patronymic;
	current[posCurrent].adress = prev[posPrev].adress;
	current[posCurrent].telephone = prev[posPrev].telephone;
	current[posCurrent].creditka = prev[posPrev].creditka;

}


// добавление в i-тую позицию в существующий массив
Shopper* addInItem(struct Shopper* arr, int& count_el) {

	int newCountEl = 0;
	int position = 0;
	cout << "Введите позицию: ";
	cin >> position;
	count_el += 1; // изменяем количество, т.е увеличиваем на 1
	Shopper* arrNew = new Shopper[count_el]; // новый массив с учетом новых покупателей
	for (int i = 0; i < count_el - 1; i++) {
		// если не дошли еще до новых покупателей, то копируем старых
		if (i < position) { //
			copyDataStructsByItem(arr, i, arrNew, i);
		}
		// иначе заставляем инициализировать их новыми данными
		else {
			if (i == position) { 
				inputOnItemByIndex(arrNew, position);
			}
			copyDataStructsByItem(arr, i, arrNew, i + 1);
		}
	}

	cout << "Данные добавлены в программу!";
	system("pause");

	return arrNew;

}

// Удаление из i-той позиции в существующий массив
Shopper* deleteInItem(struct Shopper* arr, int& count_el) {

	int newCountEl = 0;
	int position = 0;
	cout << "Введите позицию: ";
	cin >> position;
	count_el -= 1; // изменяем количество, т.е уменьшаем на 1
	Shopper* arrNew = new Shopper[count_el]; // новый массив с учетом новых покупателей
	for (int i = 0; i < count_el; i++) {
		// если не дошли еще до новых покупателей, то копируем старых
		if (i < position) { //
			copyDataStructsByItem(arr, i, arrNew, i);
		}
		// иначе заставляем инициализировать их новыми данными
		else {
			copyDataStructsByItem(arr, i + 1, arrNew, i);
		}
	}


	cout << "Данные добавлены в программу!";
	system("pause");

	return arrNew;

}


// Добавление НОВЫХ данных в существующий массив
Shopper* appendInExistArr(struct Shopper* arr, int& count_el) {

	int newCountEl = 0;
	cout << "Введите количество новых покупателей: ";
	cin >> newCountEl;
	count_el += newCountEl; // изменяем количество, т.е прибавляем к текущим, число введенное пользователем
	Shopper* arrNew = new Shopper[count_el]; // новый массив с учетом новых покупателей
	for (int i = 0; i < count_el; i++) {
		// если не дошли еще до новых покупателей, то копируем старых
		if (i < count_el - newCountEl) { //  count_el - newCountEl =  количество эдементов в старом массиве
			//copyDataStructs(arr, count_el - newCountEl, arrNew);
			copyDataStructsByItem(arr, i, arrNew, i);
		}
		// иначе заставляем инициализировать их новыми данными
		else {
			inputOnItemByIndex(arrNew, i);
		}
	}


	cout << "Данные добавлены в программу!";
	system("pause");

	return arrNew;

}


void structureInference(struct Shopper* arr, int& count_el) {

	for (int i = 0; i < count_el; i++) {
		cout << arr[i].family << endl;
		cout << arr[i].name << endl;// имя
		cout << arr[i].patronymic << endl; // отчество
		cout << arr[i].adress << endl; // адрес
		cout << arr[i].telephone << endl; // телефон
		cout << arr[i].creditka << endl;// номер кредитной карты
	}
	system("pause");
}
// Вывод i-той структуры
void structureInferenceItem(struct Shopper* arr, int index) {
	cout << arr[index].family << endl;
	cout << arr[index].name << endl;// имя
	cout << arr[index].patronymic << endl; // отчество
	cout << arr[index].adress << endl; // адрес
	cout << arr[index].telephone << endl; // телефон
	cout << arr[index].creditka << endl;// номер кредитной карты
}


// 11 задание 
Shopper* deleteFirstField(struct Shopper* arr, int& count_el) {
	string val;
	cout << "Введите значение поля: ";
	cin >> val;


	// стало
	int count = 0;
	for (int i = 0; i < count_el; i++) {
		if (strcmp(val.c_str(), arr[i].family.c_str()) == 0) {
			count++;
		}
	}

	Shopper* arrNew = new Shopper[count_el - count]; // новый массив с учетом новых покупателей
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

//задание 6
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

//7 задание
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
	cout << "0. Фамилия" << endl;
	cout << "1. Имя" << endl;
	cout << "2. Отчество" << endl;
	cout << "3. Адрес" << endl;
	cout << "4. Телефон" << endl;
	cout << "5. Кредитка" << endl;
}

void searcStuctByItemSolution(int i, string val, struct Shopper* arr, int count_el) { // i - номер выбранного меню
	cout << "Результаты:" << endl;
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
		cout << "Введен неправильный номер из списка \n";
		system("pause");
		break;
	}

}

// поис по заданному полю
void searcStuctByItem(struct Shopper* arr, int count_el) {
	string val;
	int num = 0;
	menuItem();
	cout << "Выберите номер поля, по которому будем искать: ";
	cin >> num;
	cout << "Введите слово для поиска: ";
	cin >> val;
	searcStuctByItemSolution(num, val, arr, count_el);
	system("pause");


}

// возвращает название меню
string getNameItem(int i) {

	switch (i)
	{
	case 0:
		return "Фамилия";
		break;
	case 1:
		return "Имя";
		break;
	case 2:
		return "Отчество";
		break;
	case 3:
		return "Адрес";
		break;
	case 4:return "Телефон";

		break;
	case 5:
		return "Номер кредитной карты";
		break;
	default:
		break;
	}

	return "";

}
void structuralChangeSolution(int num, int i, string val, struct Shopper* arr) { // i - номер выбранного меню, num - номер элемента, редактируемого
	
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
// 9 заданиие
void structuralChange(struct Shopper* arr, int count_el) {
	system("cls");
	int num; // номер структуры, которую хотим изменить
	cout << "Введите номер структуры, которую будем редактировать :";
	cin >> num;
	string anw; // ответ на вопрос 
	for (int i = 0; i < 5; i++) { // возможно 6 (количество полей в структуре)
		cout << "Будем ли мы менять значение поля " << getNameItem(i)<< endl;
		cout << "Введите 'y', если согласны" << endl;
		cin >> anw;
		if (strcmp(anw.c_str(), "y") == 0) {
			string newVal;
			cout << "Введите новое значение поля:" << endl;
			cin >> newVal;
			structuralChangeSolution(num ,i, newVal, arr);

		}
	}

	cout << "Успешно изменено!" << endl;
	system("pause");
	
}



void menu() {
	Shopper* arr = 0;
	int count_el = 0; // сколько выделено под массив
	// сколько заполнено

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
			cout << "Введен неправильный номер из списка \n";
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