#include "ft_printf.h"

static int write_hex(long long ll, int size)
{
	const char  hex[2][16] = {"0123456789abcdef", "0123456789ABCDEF"};
	int	cnt;

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
	long long	ll;
	int			cnt;

	ll = va_arg(ap, long long);
	cnt = 0;
	if (ll < 0)
		ll = ULONG_MAX + ll;
    if (size == 2)
    {
        size -= 2;
        write(1, "0x", 2);
		cnt += 2;
    }
	cnt += write_hex(ll, size);
	return (cnt); // ここを修正する。（writeに失敗したときに-1, writeできたらその文字数をカウント）
}