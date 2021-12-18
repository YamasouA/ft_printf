#include "ft_printf.h"

static int write_hex(unsigned ll, int size)
{
	const char  hex[2][16] = {"0123456789abcdef", "0123456789ABCDEF"};
	int		cnt;

	cnt = 0;
	if (ll < 16)
	{
		write(1, &hex[size][ll], 1);
		return (1);
	}
	else
	{
		cnt += write_hex(ll / 16, size);
		write(1, &hex[size][ll % 16], 1);
		cnt++;
	}
	return (cnt);
}

int put_hex(va_list ap, int size)
{
	unsigned	ll;
	int			cnt;

	cnt = 0;
	ll = va_arg(ap, long long);
	if (ll < 0)
		ll = UINT_MAX + ll + 1;
	cnt += write_hex(ll, size);
	return (cnt);
}
