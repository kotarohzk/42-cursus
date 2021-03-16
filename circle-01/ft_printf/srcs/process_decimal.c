#include "ft_printf.h"

int process_decimal(t_form *f, va_list ap)
{
	int code;

	code = 0;
	if (f->type == 4)
		code = print_type_d(f, va_arg(ap, int));
	else if (f->type == 5)
		code = print_type_i(f, va_arg(ap, int));
	else if (f->type == 6)
		code = print_type_u(f, va_arg(ap, unsigned int));
	else if (f->type == 7)
		code = print_type_x(f, va_arg(ap, unsigned int), 0);
	else if (f->type == 8)
		code = print_type_x(f, va_arg(ap, unsigned int), 1);
	if (!code)
		return (0);
	return (1);
}