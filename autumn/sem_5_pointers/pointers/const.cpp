int main()
{
    char str[] = "Hello World";
    const char* const  str_ptr = str;
    str_ptr++;
    *str_ptr = 1;
}
