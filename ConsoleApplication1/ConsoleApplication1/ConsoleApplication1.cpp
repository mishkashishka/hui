// ConsoleApplication1.cpp: ���������� ����� ����� ��� ����������� ����������.
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
string ** lexicalBlock(string ** list, int & n)//����������� ����
{
	string** list2 = new string*[255];
	for (int i = 0; i < 255; ++i)
	{
		list2[i] = new string[2];
	}
	bool error = false;
	string status = "���";
	int i = 0;
	int j = 0;
	while (j != n) {
		if (error) break;
		if (status == "���")
		{
			if (list[j][1] == "�����")
			{
				status = "��_�����_1";
				list2[i][0] += list[j][0];
				j++;
				continue;
			}
			if (list[j][1] == "������")
			{
				status = "���";
				continue;
			}
			else
			{
				error = true;
				continue;
			}
			
		}
		if (status == "��_�����_1")
		{
			if (list[j][1] == "�����")
			{
				status = "��_�����_1";
				list2[i][0] += list[j][0];
				j++;
				continue;
			}
			if (list[j][1] == "������")
			{
				list2[i][1] = "��_�����_1";
				i++;
				status = "������1";
				list2[i][0] += list[j][0];
				list2[i][1] = "������";
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
		if (status == "������1")
		{
			if (list[j][1] == "�����")
			{
				status = "��_1";
				list2[i][0] += list[j][0];
				j++;
				continue;
			}
			if (list[j][1] == "������")
			{
				status = "������1";
				j++;
				continue;
			}
			else
			{
				error = true;
				continue;
			}
			
		}
		if (status == "��_1")
		{
			if (list[j][1] == "�����" || list[j][1] == "�����")
			{
				status = "��_1";
				list2[i][0] += list[j][0];
				j++;
				continue;
			}
			if (list[j][1] == "������")
			{
				list2[i][1] = "�����_1";
				i++;
				status = "������2";
				list2[i][0] += list[j][0];
				list2[i][1] = "������";
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
		if (status == "������2")
		{
			if (list[j][1] == "������")
			{
				status = "������2";
				list2[i][0] += list[j][0];
				list2[i][1] = "������";
				j++;
				i++;
				continue;
			}
			if (list[j][1] == "�����")
			{
				status = "�����";
				list2[i][0] += list[j][0];
				list2[i][1] += "�����";
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
		if (status == "�����")
		{
			if (list[j][1] == "�����")
			{
				status = "��_�����_2";
				list2[i][0] += list[j][0];
				list2[i][1] += "�����";
				i++;
				j++;
				continue;
			}
			if (list[j][1] == "������")
			{
				status = "����";
				list2[i][0] += list[j][0];
				list2[i][1] = "������";
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
		if (status == "��_�����_2")
		{
			if (list[j][1] == "�����")
			{
				status = "��_�����_2";
				list2[i][0] += list[j][0];
				j++;
				continue;
			}
			if (list[j][1] == "������")
			{
				list2[i][1] = "��_�����_2";
				i++;
				status = "������4";
				list2[i][0] += list[j][0];
				list2[i][1] = "������";
				j++;
				i++;
				continue;
			}
			if (list[j][1] == "��.����.��.")
			{
				list2[i][1] = "��_�����_2";
				i++;
				status = "[1";
				list2[i][0] += list[j][0];
				list2[i][1] = "��.����.��";
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
		if (status == "������4")
		{
			if (list[j][1] == "������")
			{
				status = "������4";
				list2[i][0] += list[j][0];
				list2[i][1] = "������";
				j++;
				i++;
				continue;
			}
			if (list[j][1] == "��.����.��")
			{
				status = "[1";
				list2[i][0] += list[j][0];
				list2[i][1] = "��.����.��";
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
			if (list[j][1] == "�����")
			{
				status = "�����1";
				list2[i][0] += list[j][0];
				j++;
				continue;
			}	
			if (list[j][1] == "����")
			{
				status = "����1";
				list2[i][0] += list[j][0];
				list2[i][1] += "����";
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
		if (status == "����1")
		{
			
			if (list[j][1] == "�����")
			{
				status = "�����1";
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
		if (status == "�����1")
		{
			if (list[j][1] == "�����")
			{
				status = "�����1";
				list2[i][0] += list[j][0];
				j++;
				continue;
			}
			if (list[j][1] == "�����")
			{
				list2[i][1] = "�����";
				i++;
				status = "���1";
				list2[i][0] += list[j][0];
				list2[i][1] = "�����";
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
		if (status == "���1")
		{
			if (list[j][1] == "�����")
			{
				status = "���2";
				list2[i][0] += list[j][0];
				list2[i][1] += "�����";
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
		if (status == "���2")
		{
			if (list[j][1] == "�����")
			{
				status = "�����";
				list2[i][0] += list[j][0];
				list2[i][0] += "�����";
				i++;
				j++;
				continue;
			}
			if (list[j][1] == "����")
			{
				list2[i][1] = "����";
				i++;
				status = "����2";
				j++;
				continue;
			}
			else
			{
				error = true;
				continue;
			}
			
		}
		if (status == "����2")
		{
			if (list[j][1] == "�����")
			{
				status = "�����2";
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
		if (status == "�����2")
		{
			if (list[j][1] == "��.����.��")
			{
				list2[i][1] = "�����";
				i++;
				status = "]1";
				list2[i][0] += list[j][0];
				list2[i][1] = "��.����.��";
				j++;
				i++;
				continue;
			}
			if (list[j][1] == "�����")
			{
				status = "�����2";
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
			if (list[j][1] == "������")
			{
				status = "]1";
				list2[i][0] += list[j][0];
				list2[i][1] = "������";
				j++;
				i++;
				continue;
			}
			if (list[j][1] == "�����")
			{
				status = "��_�����_3";
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
		if (status == "��_�����_3")
		{
			if (list[j][1] == "������")
			{
				status = "������6";
				list2[i][0] += list[j][0];
				list2[i][1] = "������";
				j++;
				i++;
				continue;
			}
			if (list[j][1] == "�����")
			{
				status = "��_�����_3";
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
		if (status == "������6")
		{
			if (list[j][1] == "�����" || list[j][1] == "����" || list[j][1] == "�����" || list[j][1] == "�����" || list[j][1] == "���" || list[j][1] == "��.����.��." || list[j][1] == "��.����.��.")
			{
				error = true;
				continue;
			}
			if (list[j][1] == "������")
			{
				status = "������6";
				list2[i][0] += list[j][0];
				list2[i][1] = "������";
				j++;
				i++;
				continue;
			}
			if (list[j][1] == "�����")
			{
				status = "��_�����_4";
				list2[i][0] += list[j][0];				
				j++;
				continue;
			}
		}
		if (status == "��_�����_4")
		{
			if (list[j][1] == "������" || list[j][1] == "�����" || list[j][1] == "����" || list[j][1] == "�����" || list[j][1] == "�����" || list[j][1] == "���" || list[j][1] == "��.����.��." || list[j][1] == "��.����.��.")
			{
				error = true;
				continue;
			}
			if (list[j][1] == "������")
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
		list[i][1] = "������";
		if (((int)(s[i]) <= (int)('Z') && (int)(s[i]) >= (int)('A')) | ((int)(s[i]) <= (int)('z') && (int)(s[i]) >= (int)('a')))
			list[i][1] = "�����";
		if ((int)(s[i]) <= (int)('9') && (int)(s[i]) >= (int)('0'))
			list[i][1] = "�����";
		if ((int)(s[i]) == (int)(';'))
			list[i][1] = "����� � �������";
		if ((int)(s[i]) == (int)(' '))
			list[i][1] = "������";
		if ((int)(s[i]) == (int)('+'))
			list[i][1] = "����";
		if ((int)(s[i]) == (int)('-'))
			list[i][1] = "�����";
		if ((int)(s[i]) == (int)('='))
			list[i][1] = "�����";
		if ((int)(s[i]) == (int)('.'))
			list[i][1] = "�����";
		if ((int)(s[i]) == (int)('['))
			list[i][1] = "�������� ���������� ������";
		if ((int)(s[i]) == (int)(']'))
			list[i][1] = "�������� ���������� ������";
	}

	return list;
}
