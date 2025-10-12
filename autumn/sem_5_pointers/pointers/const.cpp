int main()
{
    char str[] = "Hello World";
	char* const str_ptr = str;
    str_ptr++;
    *str_ptr = 1;
}
