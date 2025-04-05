#include <stdio.h>
#include <string.h>

int main()
{
	int i=0;
	char s[80];
	
	printf("enter ur string: ");
	fgets(s, 80, stdin);
	while (i<strlen(s))
	{
		{
			if (s[i]=='a')
			{
				s[i]='A';
			}
			if (s[i]=='b')
			{
				s[i]='B';
			}
		}
		i++;
		
	}
	printf("%s",s);
	return 0;
}

