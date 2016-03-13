#include <iostream>;
#include <string.h>;
#define _IGNORE_BLOCK
using namespace std;

short ThanslateFromHex(char);//переводит такие буквы в 16ричной системе в цифры в двоичной
int* CreatingArray(int );//создает массив
void EnterHexSign(char& );//Ввод 16ричного символа
void DeleteElementsWithSpecialSign(int *, int&, short);//удаляет элемент в котором содержиться специальный символ
void QuickSort(int *, int );//быстрая сортировка
void QuickSort(int *,int *, int , int );//быстрая сортировка
void TakeFirstSymboFromHex(int *, int *, int );//нахождение первого символа в 16ричной системе
void Swap(int &, int &);//перемена местами элементов
void DeleteTheSameElements(int *, int &);//удаляет одинаковые элементы
void ShiftArray(int *, int , int *);//сдвиг элементов
void EnterDimention(int &); // Ввод длины массива
void ChoiceFillingStyle(int *,int );// Выбор по какому типу будет проводиться заполнение массива
void EnterArrayYourself(int *,int );//ввод массива пользователем
void EnterArrayRandom(int *, int );// рандомное заполнение массива
void DisplayArray(int *, int );// показ массива на консоле
bool IsDataValid(int );// проверка корректности данных
bool IsChoiceValid(int );//проверка корректности данных
bool IsHexSymbolValid(char*);//проверка корректности данных
char ToUpper(char);//перевод строчной буквы в заглавную



int main()
{
	
	
	while (true)
	{
		cout.width(50);
		cout << endl << "Welcome to the programm!";
		cout << endl << endl << "*******************************************************************************" << endl << endl;
		cout << endl << "This programm is sorting numbers by their first digit" << endl << "in their hex form (in descending order)" << endl;
		system("pause");
		system("cls");
		int n;
		EnterDimention(n);
		system("cls");
		int *a = CreatingArray(n);
		ChoiceFillingStyle(a,n);//ввод массива
		DisplayArray(a, n);
		cout << "-array before sorting"<<endl;
		DeleteTheSameElements(a,n);// удаляем повторяющиеся символы
		QuickSort(a, n);// сама сортировка
		DisplayArray(a, n);
		cout << "-array after sorting" << endl;
		system("pause");
		system("cls");
		cout.width(50);
		cout << endl << "Welcome to the second part of programm!";
		cout << endl << endl << "*******************************************************************************" << endl << endl;
		cout << endl << "This part of programm delete numbers from the array" << endl << "if they have some special sign in their hex form" << endl;
		system("pause");
		system("cls");
		char s = { 0 };
		EnterHexSign(s);// ввод 16ричного символа
		short k = ThanslateFromHex(s);
		DeleteElementsWithSpecialSign(a, n, k);// удаление элемента с опрделенным символом
		DisplayArray(a, n);
		cout << "-array after deleting" << endl;
		system("pause");
		system("cls");
		cout << "Would you like to continue? " << endl;
		cout << "Yes- y or Y " << endl;
		cout << "No- other symbols" << endl;
		cout << "Waiting for Enter: " << endl;
		cin >> s;
		system("cls"); 
		a = NULL;
		delete [] a;
		if (s == 'y' || s == 'Y') continue;
		break;

	}
	
	return 0;
}

short ThanslateFromHex(char s)
{
	
	switch (s)
	{
	case 'A':
		return 10;
	case 'B':
		return 11;
	case 'C':
		return 12;
	case 'D':
		return 13;
	case 'E':
		return 14;
	case 'F':
		return 15;
	}
}

int* CreatingArray(int n)
{
	int* a = new int[n];
	return a;
}

void EnterHexSign(char& a)
{
	while (true)
	{
		cout << "Warning! You can enter only 'A','B','C','D','E'or'F' " << endl;
		cout << "Enter special hex sign,please: ";
		cin >> a;
		a = ToUpper(a);
		char*s = &a;
		if (IsHexSymbolValid(s)) break;//проверка корректности кода
		cout << "Error!"<<endl;
		system("pause");
		system("cls");
	}
}

void DeleteElementsWithSpecialSign(int *a, int &n, short k)
{
	int   l;
	short q;

	for (int *i = a; i < a+n; i++)
	{
		l = abs(*i);
		while (l >= 1)// переводим число в шестнадцатиричное
		{
			q = l % 16;
			l /= 16;
			if (q == k)
			{
				ShiftArray(a, n, i);// сдвигаем элементы
				i--;
				n--;
			}

		}
	}
}

void QuickSort(int *a, int n)
{
	int *arr = CreatingArray(n);
	TakeFirstSymboFromHex(a, arr, n);// заполняем вспомогательный массив значениями из первого символа шестнадцатиричного числа
	QuickSort(arr,a, 0, n-1);// начинаем сортировку
	arr = NULL;
	delete [] arr;
}

void QuickSort(int *arr,int*b, int left, int right) 
{
	int i = left, j = right;
	int pivot = arr[(left + right) / 2];

	
	while (i <= j) {
		while (arr[i] > pivot)
			i++;
		while (arr[j]< pivot)
			j--;
		if (i <= j) {
			Swap(arr[i], arr[j]);//так как порядок 2 массивов одинков и втрой массив содержит элементы из первого то значит, для сохранения отражения между двумя массива нужно совершать одинаковый swap
			Swap(b[i], b[j]);// и тем самым мы и можем сортировать
			i++;
			j--;
		}
	}

	if (left < j)
		QuickSort(arr,b, left, j);// рекусивный вызов
	if (i < right)
		QuickSort(arr,b, i, right);


}

void TakeFirstSymboFromHex(int *a,int *b, int n)
{
	int  q,l;
	
	for (int i = 0; i < n; i++)
	{
		l = abs(a[i]);
		while (l>=1)
		{
			q = l % 16;
			l /= 16;
		}
		b[i] = q;
	}
}

void Swap(int &x, int &y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}

void DeleteTheSameElements(int *a, int &n)
{
	int *i, *j;
	for ( i = a; i < a+n; i++) // Проверка элементов, перебор строк массива 
	{
		for (j = i + 1; j < a+n; j++) // Перебор элементов строк 
		{
			if (*i == *j) //  Нашли повтор 
			{
				ShiftArray(a, n, j);
				n = n--; // "Укорачиваем" массив 
				*j = *j--;
			}
		}
	}
}

void ShiftArray(int *a, int n, int *j)
{
	for (int* k = j; k <= a+n; k++)
	{
		*k = *(k+1); // Сдвигаем все следующие элементы на 1 справа-налево 
	}
}

void EnterDimention(int &n)
{
	cout << "How many numbers do you want to sort?" << endl;
	while (true)
	{
		cout << "Enter size   0<=n    : ";
		cin >> n;
		if (IsDataValid(n)) break;
		cout << "Error!" << endl;
	}
}

void ChoiceFillingStyle(int *a,int n)
{
	cout << "How do you want to fill the array?" << endl;
	cout << "1) by yourself" << endl;
	cout << "2) random" << endl;
	int k;
	while (true)
	{
		cout << "Waiting for enter: ";
		cin >> k;
		if (IsChoiceValid(k)) break;
		cout << "Error!" << endl;
	}
	system("cls");
	if (k == 1) EnterArrayYourself(a,n);// вводим масив самостоятельно
	else EnterArrayRandom(a, n);// рандомный ввод
}

void EnterArrayYourself(int *a, int n)
{
	cout << "Warning! You should enter integer numbers," << endl << "If you enter 3.4, it will be 3 in programm," << endl << "Please, be careful:" << endl;
	short k = 1;
	for (int *i = a; i < a+n; i++)
	{
		cout << "Element" << "[" << k << "]  :  ";
		cin >> *i;
		k++;
	}
	system("cls");

}

void EnterArrayRandom(int *a, int n)
{
	for (int *i = a; i < a+n; i++)
	{
	    *i=rand();
	}
}

void DisplayArray(int *a, int n)
{
	for (int *i = a; i < a+n; i++)
		cout << *i << " ";
}

bool IsDataValid(int n)
{
	if (n <= 0) return false;
	return true;
}

bool IsChoiceValid(int n)
{
	if (n == 1 || n == 2)  return true;
	return false;
}

bool IsHexSymbolValid(char *a)
{
	char *test = "ABCDEF";
	char *q = strpbrk(a,test);
	if (q != NULL) return true;// в случае если есть совпадение вернеться не указатель типа Null
	return false;
}

char ToUpper(char symbol)
{
	if (symbol >= 'a' && symbol <= 'z')
	{
		return symbol -= 32;
	}
	return symbol;
}