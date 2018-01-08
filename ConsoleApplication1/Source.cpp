#include<stdio.h>
#include<string.h>
#include<malloc.h>

int main(int argc, char *argv[])
{
	int x = 0, y = 0, n = 0, s = 0, e= 0, w = 0,i =0, length =0, walk = 0;
	char r,l,d;
	char *arr,*side;
	sscanf(argv[1], "%d", &x);
	sscanf(argv[2], "%d", &y);

	if ((stricmp(argv[3], "south")) == 0)
	{
		s = 1;
	}
	else if (stricmp(argv[3], "east") == 0)
	{
		e = 1;
	}
	else if (stricmp(argv[3], "west") == 0)
	{
		w = 1;
	}
	else if (stricmp(argv[3], "north") == 0)
	{
		n = 1;
	}
	 
	
	arr = (char *)malloc(strlen(argv[4]) + 1);
	strcpy(arr, argv[4]);

	length = (strlen(argv[4]));

	r = 'r';
	l = 'l';
	d = 'w';

	while (length != 0)
	{
		if (arr[i] == r)
		{
			if (s == 1)
			{
				w = 1;
				s = 0;
			}
			else if (w == 1){
				w = 0;
				n = 1;
			}
			else if (n == 1){
				n = 0;
				e = 1;
			}
			else if (e == 1){
				s = 1;
				e = 0;
			}
		}
		else if (arr[i] == l)
		{
			if (s == 1)
			{
				e = 1;
				s = 0;
			}
			else if (w == 1){
				w = 0;
				s = 1;
			}
			else if (n == 1){
				n = 0;
				w = 1;
			}
			else if (e == 1){
				n = 1;
				e = 0;
			}
		}
		else if (arr[i] == d)
		{
			i++;
			length--;
			walk = arr[i] - '0';
			if (s == 1)
			{
				while (walk != 0)
				{
					y--;
					walk--;
				}
			}
			else if (w == 1){
				while (walk != 0)
				{
					x--;
					walk--;
				}
			}
			else if (n == 1){
				while (walk != 0)
				{
					y++;
					walk--;
				}
			}
			else if (e == 1){
				while (walk != 0)
				{
					x++;
					walk--;
				}
			}
		}
		i++;
		length--;
	}

	if (s == 1)
	{
		side = "south";
	}
	else if (w == 1){
		side = "west";
	}
	else if (n == 1){
		side = "north";
	}
	else if (e == 1){
		side = "east";
	}

	printf("%d %d %s \n\n",x,y,side);
	return 0;
}
