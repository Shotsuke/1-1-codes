#pragma once
#include <iostream>
using namespace std;
class Number
{
public:
	Number();
	Number(char* s ,int length);
	Number(const Number& number);
	~Number();
	friend void shownumber(Number a)
	{
		if (a._sig == -1) printf("-"); 
		for (int i = a._len - 1; i >= 0; i--)
		{
			printf("%d",a._num[i]);
		}
		printf("\n");
	}
	int*	_num;
	int		_len;
	int		_sig;
	Number operator + (const Number& a);
	Number operator - (const Number& a);
	Number operator * (const Number& a);
	bool operator < (const Number& a);
	bool operator > (const Number& a);
	bool operator = (const Number& a);
};
Number::Number()
{
	_num = new int[100];
	for (int i = 0; i < 100; i++)
	{
		_num[i] = 0;
	}
	_len = 0;
	_sig = 0;
}
Number::Number(char* s, int length)
{
	_num = new int[100];
	_len = length;
	for (int i = 0; i < 100; i++)
	{
		_num[i] = 0;
	}
	if (s[0] != '-')
	{
		_sig = 1;
		for (int i = length - 1; i >= 0; i--)
		{
			_num[i] = (int)s[length - i - 1] - 48;
		}
	}
	else
	{
		_sig = -1;
		_len--;
		for (int i = length - 1; i >= 1; i--)
		{
			_num[i - 1] = (int)s[length - i] - 48;
		}
	}
	// µÍÎ»´æ´¢µÍÎ»
}
Number::Number(const Number& number)
{
	_num = new int[100];
	_len = number._len;
	for (int i = 0; i < _len; i++)
	{
		_num[i] = number._num[i];
	}
	_sig = number._sig;
}
Number::~Number()
{
	delete[] _num;
}
Number Number::operator + (const Number& a)

{
	Number res;
	int i;

	for (i = 0; i < max(a._len, this->_len); i++)
	{
		res._num[i]		+= (a._num[i] * a._sig + this->_num[i] * this->_sig) % 10;
		res._num[i+1]	+= (a._num[i] * a._sig + this->_num[i] * this->_sig) / 10;
	}
	if	(res._num[i+1]!=0)	res._len = max(a._len, this->_len) +1;
	else					res._len = max(a._len, this->_len);

	if (res._num[res._len - 1] < 0)
	{
		res._sig = -1;
		for (i = 0; i < res._len; i++)
		{
			res._num[i] = -res._num[i];
		}
	}
	else res._sig = 1;

	for (i = 0; i < res._len; i++)
	{
		if (res._num[i] < 0)
		{
			res._num[i] += 10;
			res._num[i+1] --;
		}
	}
	for (i = res._len - 1; i >= 0; i--)
	{
		if(res._num[i] == 0) res._len--;
	}
	return res;
}
Number Number::operator - (const Number& a)
{
	Number res;
	int i;

	for (i = 0; i < max(a._len, this->_len); i++)
	{
		res._num[i]		+= (-a._num[i] * a._sig + this->_num[i] * this->_sig) % 10;
		res._num[i+1]	+= (-a._num[i] * a._sig + this->_num[i] * this->_sig) / 10;
	}
	if	(res._num[i+1]!=0)	res._len = max(a._len, this->_len) +1;
	else					res._len = max(a._len, this->_len);

	if (res._num[res._len - 1] < 0)
	{
		res._sig = -1;
		for (i = 0; i < res._len; i++)
		{
			res._num[i] = -res._num[i];
		}
	}
	else res._sig = 1;

	for (i = 0; i < res._len; i++)
	{
		if (res._num[i] < 0)
		{
			res._num[i] += 10;
			res._num[i+1] --;
		}
	}
	for (i = res._len - 1; i >= 0; i--)
	{
		if(res._num[i] == 0) res._len--;
	}
	return res;
}
Number Number::operator * (const Number& a)
{
	Number res;
	int i;

	for (i = 0; i <a._len; i++)
	{
		for (int j = 0; j < this->_len; j++)
		{
			res._num[i + j] += a._num[i] * this->_num[j];
		}
	}
	res._len = a._len + this->_len;
	res._sig = a._sig * this->_sig;

	for (i = 0; i < res._len; i++)
	{
		res._num[i+1] += res._num[i] / 10;
		res._num[i] %= 10;
	}

	if(res._num[res._len] != 0) res._len++;
	return res;
}
bool Number::operator < (const Number& a)
{
	if		(this->_sig == -1 && a._sig == 1) return true;
	else if (this->_sig == 1 && a._sig == -1) return false;
	else if (this->_sig == 1 && a._sig == 1)
	{
		for (int i = max(this->_len, a._len) - 1; i >= 0; i--)
		{
			if(this->_num[i] < a._num[i]) return true;
			else if(this->_num[i] == a._num[i]) continue;
			else return false;
		}
		return false;
	}
	else
	{
		for (int i = max(this->_len, a._len) - 1; i >= 0; i--)
		{
			if(this->_num[i] < a._num[i]) return false;
			else if(this->_num[i] == a._num[i]) continue;
			else return true;
		}
		return false;
	}
}
bool Number::operator > (const Number& a)
{
	if		(this->_sig == -1 && a._sig == 1) return false;
	else if (this->_sig == 1 && a._sig == -1) return true;
	else if (this->_sig == 1 && a._sig == 1)
	{
		for (int i = max(this->_len, a._len) - 1; i >= 0; i--)
		{
			if(this->_num[i] < a._num[i]) return false;
			else if(this->_num[i] == a._num[i]) continue;
			else return true;
		}
		return false;
	}
	else
	{
		for (int i = max(this->_len, a._len) - 1; i >= 0; i--)
		{
			if(this->_num[i] < a._num[i]) return true;
			else if(this->_num[i] == a._num[i]) continue;
			else return false;
		}
		return false;
	}
}
bool Number::operator = (const Number& a)
{
	if		(this->_sig != a._sig) return false;
	else
	{
		for (int i = max(this->_len, a._len) - 1; i >= 0; i--)
		{
			if(this->_num[i] != a._num[i]) return false;
			else if(this->_num[i] == a._num[i]) continue;
		}
		return true;
	}
}

