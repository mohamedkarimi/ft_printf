# ft_printf (42 Network)

This project is my personal implementation of **ft_printf**, a project from the 42 Network curriculum.  
The goal is to recreate the behavior of the standard `printf` function in C.

## About the project

`ft_printf` is a custom implementation of the C standard library function `printf`.  
It handles formatted output conversion and prints data to standard output.

This project helps to understand:
- Variadic functions
- Parsing and formatting
- Type conversions
- Memory management
- Low-level output handling

## Supported conversions

The implementation supports the following specifiers:

- `%c` — character  
- `%s` — string  
- `%p` — pointer  
- `%d` / `%i` — signed decimal integer  
- `%u` — unsigned decimal integer  
- `%x` / `%X` — hexadecimal (lowercase / uppercase)  
- `%%` — percent sign  

## Function prototype

```c
int ft_printf(const char *format, ...);

