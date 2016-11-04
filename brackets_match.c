#include <stdio.h>

int do_bracket_match(char *str)
{
	char tmp_str[5000];
	char *pstr = str;
	char *ptmp = tmp_str;
	for (; (*pstr) != '\0'; pstr++){
		if((*pstr) == '(' || (*pstr) == '['){
			*ptmp = *pstr;
			ptmp++;
		}
		else if ((*pstr) == ')')
		{
			if ((*(ptmp - 1)) == '(')
			{
				ptmp--;
			}
			else
				return 0;
		}
		else if ((*pstr) == ']')
		{
			if ((*(ptmp - 1)) == '[')
			{
				ptmp--;
			}
			else
				return 0;
		}
	}
	if(ptmp == tmp_str){
		return 1;
	}
	else
		return 0;
}

int main(void)
{
	int num_str = 0, cnt_str = 0, result_str = 0;
	char process_str[10000];
	scanf("%d", &num_str);
	getchar();

	for (cnt_str = 0; cnt_str < num_str; cnt_str++) {
		gets(process_str);
		(do_bracket_match(process_str))?puts("Yes"):puts("No");
	}

	return 0;
}
