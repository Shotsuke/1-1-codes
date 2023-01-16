#include <iostream>
#include <stdio.h>
#include <string.h>
#include "Number.h"
using namespace std;
signed main()
{
	Number n0;
	printf("n0\nlen=%d\nnum=",n0._len);
	shownumber(n0);
	

	char s1[]="123456";
	Number n1(s1 , 6);
	printf("\nn1\nlen=%d\nnum=",n1._len);
	shownumber(n1);

	Number n2(n1);
	printf("\nn2\nlen=%d\nnum=",n2._len);
	shownumber(n2);

	Number n3 = n1 + n2;
	printf("\nn3\nlen=%d\nnum=",n3._len);
	shownumber(n3);

	char s2[]="-99999";
	Number n4(s2 , 6);
	printf("\nn4\nlen=%d\nnum=",n4._len);
	shownumber(n4);

	Number n5 = n1 + n4;
	printf("\nn5\nlen=%d\nnum=",n5._len);
	shownumber(n5);

	char s3[]="99999";
	Number n6(s3 , 5);
	printf("\nn6\nlen=%d\nnum=",n6._len);
	shownumber(n6);

	Number n7 = n1 - n6;
	printf("\nn7\nlen=%d\nnum=",n7._len);
	shownumber(n7);

	Number n8 = n1 - n4;s
	printf("\nn8\nlen=%d\nnum=",n8._len);
	shownumber(n8);

	Number n9 = n1 * n6;
	printf("\nn9\nlen=%d\nnum=",n9._len);
	shownumber(n9);

	printf("\n%d\n",n1<n1);
	printf("\n%d\n",n4>n1);
	printf("\n%d\n",n1=n1);
	printf("\n");
	return 0;
}