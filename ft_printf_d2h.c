#include "ft_printf.h"

void write_hex(long long ll, int size)
{
	const char  hex[2][16] = {"0123456789abcdef", "0123456789ABCDEF"};

	if (ll < 16)
	{
		write(1, &hex[size][ll], 1);
	}
	else
	{
		write_hex(ll / 16, size);
		write(1, &hex[size][ll % 16], 1);
	}
}

int put_hex(const char *fmt, va_list ap, int size)
{
	long long	ll;

	ll = va_arg(ap, long long);
	if (ll < 0)
	{
		ll = UINT_MAX + ll + 1;
	}
        if (size == 2)
        {
            size -= 2;
            write(1, "0x", 2);
        }
	write_hex(ll, size);
	return 1; // ここを修正する。（writeに失敗したときに-1, writeできたらその文字数をカウント）
}

