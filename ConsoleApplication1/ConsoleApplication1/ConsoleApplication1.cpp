// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;
typedef string arr[100][1];
string** translate(string s);
string ** lexicalBlock(string ** list, int & n);
int main()
{
	setlocale(LC_CTYPE, "rus");
	string** list;
	string s = "type StrArr=array [1..10] of String;";
	list = translate(s);
	for (int i = 0; i < s.length(); i++)
	{
		cout << list[i][0] << " " << list[i][1] << endl;
	}
	system("pause");

	return 0;
}
string ** lexicalBlock(string ** list, int & n)//лексический блок
{
	string** list2 = new string*[255];
	for (int i = 0; i < 255; ++i)
	{
		list2[i] = new string[2];
	}
	bool error = false;
	string status = "нач";
	int i = 0;
	int j = 0;
	while (j != n) {
		if (error) break;
		if (status == "нач")
		{
			if (list[j][1] == "буква")
			{
				status = "кл_слово_1";
				list2[i][0] += list[j][0];
				j++;
				continue;
			}
			if (list[j][1] == "пробел")
			{
				status = "нач";
				continue;
			}
			else
			{
				error = true;
				continue;
			}
			
		}
		if (status == "кл_слово_1")
		{
			if (list[j][1] == "буква")
			{
				status = "кл_слово_1";
				list2[i][0] += list[j][0];
				j++;
				continue;
			}
			if (list[j][1] == "пробел")
			{
				list2[i][1] = "кл_слово_1";
				i++;
				status = "пробел1";
				list2[i][0] += list[j][0];
				list2[i][1] = "пробел";
				j++;
				i++;
				continue;
			}
			else
			{
				error = true;
				continue;
			}
			
		}
		if (status == "пробел1")
		{
			if (list[j][1] == "буква")
			{
				status = "ид_1";
				list2[i][0] += list[j][0];
				j++;
				continue;
			}
			if (list[j][1] == "пробел")
			{
				status = "пробел1";
				j++;
				continue;
			}
			else
			{
				error = true;
				continue;
			}
			
		}
		if (status == "ид_1")
		{
			if (list[j][1] == "буква" || list[j][1] == "цифра")
			{
				status = "ид_1";
				list2[i][0] += list[j][0];
				j++;
				continue;
			}
			if (list[j][1] == "пробел")
			{
				list2[i][1] = "идент_1";
				i++;
				status = "пробел2";
				list2[i][0] += list[j][0];
				list2[i][1] = "пробел";
				j++;
				i++;
				continue;
			}
			else
			{
				error = true;
				continue;
			}
			
		}
		if (status == "пробел2")
		{
			if (list[j][1] == "пробел")
			{
				status = "пробел2";
				list2[i][0] += list[j][0];
				list2[i][1] = "пробел";
				j++;
				i++;
				continue;
			}
			if (list[j][1] == "равно")
			{
				status = "равно";
				list2[i][0] += list[j][0];
				list2[i][1] += "равно";
				j++;
				i++;
				continue;
			}
			else
			{
				error = true;
				continue;
			}
			
			
		}
		if (status == "равно")
		{
			if (list[j][1] == "буква")
			{
				status = "кл_слово_2";
				list2[i][0] += list[j][0];
				list2[i][1] += "равно";
				i++;
				j++;
				continue;
			}
			if (list[j][1] == "пробел")
			{
				status = "знак";
				list2[i][0] += list[j][0];
				list2[i][1] = "пробел";
				j++;
				i++;
				continue;
			}
			else
			{
				error = true;
				continue;
			}
		} 
		if (status == "кл_слово_2")
		{
			if (list[j][1] == "буква")
			{
				status = "кл_слово_2";
				list2[i][0] += list[j][0];
				j++;
				continue;
			}
			if (list[j][1] == "пробел")
			{
				list2[i][1] = "кл_слово_2";
				i++;
				status = "пробел4";
				list2[i][0] += list[j][0];
				list2[i][1] = "пробел";
				j++;
				i++;
				continue;
			}
			if (list[j][1] == "кв.откр.ск.")
			{
				list2[i][1] = "кл_слово_2";
				i++;
				status = "[1";
				list2[i][0] += list[j][0];
				list2[i][1] = "кв.откр.ск";
				j++;
				i++;
				continue;
			}
			else
			{
				error = true;
				continue;
			}
			
		}
		if (status == "пробел4")
		{
			if (list[j][1] == "пробел")
			{
				status = "пробел4";
				list2[i][0] += list[j][0];
				list2[i][1] = "пробел";
				j++;
				i++;
				continue;
			}
			if (list[j][1] == "кв.откр.ск")
			{
				status = "[1";
				list2[i][0] += list[j][0];
				list2[i][1] = "кв.откр.ск";
				j++;
				i++;
				continue;
			}
			else
			{
				error = true;
				continue;
			}
			
		}
		if (status == "[1")
		{
			if (list[j][1] == "цифра")
			{
				status = "число1";
				list2[i][0] += list[j][0];
				j++;
				continue;
			}	
			if (list[j][1] == "знак")
			{
				status = "знак1";
				list2[i][0] += list[j][0];
				list2[i][1] += "знак";
				j++;
				i++;
				continue;
			}
			else
			{
				error = true;
				continue;
			}
			
		}
		if (status == "знак1")
		{
			
			if (list[j][1] == "цифра")
			{
				status = "число1";
				list2[i][0] += list[j][0];
				j++;
				continue;
			}
			else
			{
				error = true;
				continue;
			}
		}
		if (status == "число1")
		{
			if (list[j][1] == "цифра")
			{
				status = "число1";
				list2[i][0] += list[j][0];
				j++;
				continue;
			}
			if (list[j][1] == "точка")
			{
				list2[i][1] = "число";
				i++;
				status = "тчк1";
				list2[i][0] += list[j][0];
				list2[i][1] = "точка";
				j++;
				i++;
				continue;
			}
			else
			{
				error = true;
				continue;
			}
			
		}
		if (status == "тчк1")
		{
			if (list[j][1] == "точка")
			{
				status = "тчк2";
				list2[i][0] += list[j][0];
				list2[i][1] += "точка";
				j++;
				i++;
				continue;
			}
			else
			{
				error = true;
				continue;
			}
		}
		if (status == "тчк2")
		{
			if (list[j][1] == "цифра")
			{
				status = "число";
				list2[i][0] += list[j][0];
				list2[i][0] += "точка";
				i++;
				j++;
				continue;
			}
			if (list[j][1] == "знак")
			{
				list2[i][1] = "знак";
				i++;
				status = "знак2";
				j++;
				continue;
			}
			else
			{
				error = true;
				continue;
			}
			
		}
		if (status == "знак2")
		{
			if (list[j][1] == "цифра")
			{
				status = "число2";
				list2[i][0] += list[j][0];
				i++;
				continue;
			}
			else
			{
				error = true;
				continue;
			}
			
		}
		if (status == "число2")
		{
			if (list[j][1] == "кв.закр.ск")
			{
				list2[i][1] = "число";
				i++;
				status = "]1";
				list2[i][0] += list[j][0];
				list2[i][1] = "кв.закр.ск";
				j++;
				i++;
				continue;
			}
			if (list[j][1] == "цифра")
			{
				status = "число2";
				list2[i][0] += list[j][0];
				j++;
				continue;
			}
			else
			{
				error = true;
				continue;
			}
		}
		if (status == "]1")
		{
			if (list[j][1] == "пробел")
			{
				status = "]1";
				list2[i][0] += list[j][0];
				list2[i][1] = "пробел";
				j++;
				i++;
				continue;
			}
			if (list[j][1] == "буква")
			{
				status = "кл_слово_3";
				list2[i][0] += list[j][0];				
				j++;
				continue;
			}
			else
			{
				error = true;
				continue;
			}
			

		}
		if (status == "кл_слово_3")
		{
			if (list[j][1] == "пробел")
			{
				status = "пробел6";
				list2[i][0] += list[j][0];
				list2[i][1] = "пробел";
				j++;
				i++;
				continue;
			}
			if (list[j][1] == "буква")
			{
				status = "кл_слово_3";
				list2[i][0] += list[j][0];
				j++;
				continue;
			}
			else
			{
				error = true;
				continue;
			}
			
			
		}
		if (status == "пробел6")
		{
			if (list[j][1] == "цифра" || list[j][1] == "плюс" || list[j][1] == "минус" || list[j][1] == "буква" || list[j][1] == "зап" || list[j][1] == "кр.откр.ск." || list[j][1] == "кр.закр.ск.")
			{
				error = true;
				continue;
			}
			if (list[j][1] == "пробел")
			{
				status = "пробел6";
				list2[i][0] += list[j][0];
				list2[i][1] = "пробел";
				j++;
				i++;
				continue;
			}
			if (list[j][1] == "буква")
			{
				status = "кл_слово_4";
				list2[i][0] += list[j][0];				
				j++;
				continue;
			}
		}
		if (status == "кл_слово_4")
		{
			if (list[j][1] == "тчкзпт" || list[j][1] == "цифра" || list[j][1] == "плюс" || list[j][1] == "минус" || list[j][1] == "буква" || list[j][1] == "зап" || list[j][1] == "кр.откр.ск." || list[j][1] == "кр.закр.ск.")
			{
				error = true;
				continue;
			}
			if (list[j][1] == "пробел")
			{
				j++;
				continue;
			}
		}
	}
	return list2;
}
string** translate(string s)
{

	string** list = new string*[100];
	for (int i = 0; i < 100; ++i)
	{
		list[i] = new string[2];
	}

	for (int i = 0; i < s.length(); i++)
	{
		list[i][0] = s[i];
		list[i][1] = "ошибка";
		if (((int)(s[i]) <= (int)('Z') && (int)(s[i]) >= (int)('A')) | ((int)(s[i]) <= (int)('z') && (int)(s[i]) >= (int)('a')))
			list[i][1] = "буква";
		if ((int)(s[i]) <= (int)('9') && (int)(s[i]) >= (int)('0'))
			list[i][1] = "цифра";
		if ((int)(s[i]) == (int)(';'))
			list[i][1] = "точка с запятой";
		if ((int)(s[i]) == (int)(' '))
			list[i][1] = "пробел";
		if ((int)(s[i]) == (int)('+'))
			list[i][1] = "плюс";
		if ((int)(s[i]) == (int)('-'))
			list[i][1] = "минус";
		if ((int)(s[i]) == (int)('='))
			list[i][1] = "равно";
		if ((int)(s[i]) == (int)('.'))
			list[i][1] = "точка";
		if ((int)(s[i]) == (int)('['))
			list[i][1] = "открытие квадратных скобок";
		if ((int)(s[i]) == (int)(']'))
			list[i][1] = "закрытие квадратных скобок";
	}

	return list;
}
