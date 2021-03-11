#include<iostream>

using namespace std;

void ReplaceBlank(char str[])
{
	if (str == nullptr)
	{
		return;
	}

	int lenword = 0;
	int blankcount = 0;
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			blankcount++;
		lenword++;
		i++;
	}

	int newlen = lenword + blankcount * 2;


	while (lenword >= 0 && lenword < newlen)
	{
		if (str[lenword] != ' ')
		{
			str[newlen--] = str[lenword];
		}
		else
		{
			str[newlen--] = '0';
			str[newlen--] = '2';
			str[newlen--] = '%';
		}
		lenword--;
	}
}

int main()
{
	char stri[20] = "000";
	ReplaceBlank(stri);
	
	system("pause");
	return 0;
}   
