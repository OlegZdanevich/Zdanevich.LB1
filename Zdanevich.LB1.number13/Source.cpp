#include <iostream>;
#include <string.h>;
#define _IGNORE_BLOCK
using namespace std;

short ThanslateFromHex(char);
int* CreatingArray(int );
void EnterHexSign(char& );
void DeleteElementsWithSpecialSign(int *, int&, short);
void QuickSort(int *, int );
void QuickSort(int *,int *, int , int );
void TakeFirstSymboFromHex(int *, int *, int );
void Swap(int &, int &);
void DeleteTheSameElements(int *, int &);
void ShiftArray(int *, int , int *);
void EnterDimention(int &); 
void ChoiceFillingStyle(int *,int );
void EnterArrayYourself(int *,int );
void EnterArrayRandom(int *, int );
void DisplayArray(int *, int );
bool IsDataValid(int );
bool IsChoiceValid(int );
bool IsHexSymbolValid(char*);
char ToUpper(char);



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
		ChoiceFillingStyle(a,n);
		DisplayArray(a, n);
		cout << "-array before sorting"<<endl;
		DeleteTheSameElements(a,n);
		QuickSort(a, n);
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
		EnterHexSign(s);
		short k = ThanslateFromHex(s);
		DeleteElementsWithSpecialSign(a, n, k);
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
		if (IsHexSymbolValid(s)) break;
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
		while (l >= 1)
		{
			q = l % 16;
			l /= 16;
			if (q == k)
			{
				ShiftArray(a, n, i);
				i--;
				n--;
			}

		}
	}
}

void QuickSort(int *a, int n)
{
	int *arr = CreatingArray(n);
	TakeFirstSymboFromHex(a, arr, n);
	QuickSort(arr,a, 0, n-1);
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
			Swap(arr[i], arr[j]);
			Swap(b[i], b[j]);
			i++;
			j--;
		}
	}

	if (left < j)
		QuickSort(arr,b, left, j);
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
	for ( i = a; i < a+n; i++) 
	{
		for (j = i + 1; j < a+n; j++) 
		{
			if (*i == *j) 
			{
				ShiftArray(a, n, j);
				n = n--; 
				*j = *j--;
			}
		}
	}
}

void ShiftArray(int *a, int n, int *j)
{
	for (int* k = j; k <= a+n; k++)
	{
		*k = *(k+1); 
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
	if (k == 1) EnterArrayYourself(a,n);
	else EnterArrayRandom(a, n);
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
	if (q != NULL) return true;
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
