int main()
{
	int x;

	puts("***********************************");
	puts("* \t     -Level00 -\t\t  *");
	puts("***********************************");
	printf("Password:");
	scanf("%d", &x);

	if (x == 0x149c)
	{
		puts("\nAuthenticated!");
		system("/bin/sh");
		return (0);
	}
	else
	{
		puts("\nInvalid Password!");
		return (1);
	}
}
