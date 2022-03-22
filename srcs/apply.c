#include "../includes/ft_printf.h"

char	*ft_insert(char *str, char *str2, size_t n)
{
	size_t	str_len;
	size_t	str2_len;
	size_t	i;
	char *str_join;

	if (!str || !str2)
		return (NULL);
	str_len = ft_strlen(str);
	str2_len = ft_strlen(str2);
	str_join = (char *)ft_calloc(str_len + str2_len + 1, sizeof(char));
	if (!str_join)
		return (NULL);
	i = 0;
	while (i <= str_len)
	{
		if (i == n)
		{
			str_join[i++] = *str2++;
			str2_len--;
		}
		str_join[i++] = *str++;
	}
	i = 1;
	while (i <= str2_len)
		str_join[str_len + i++] = *str2++;
	return (str_join);
}

char	*apply_width(char *str1, char *str2, int insert)
{
	char	*str;
	int		flag;

	if (!str1 || !str2)
		return (NULL);
	
	flag = *str2 == '-';
	insert--; // ここはなおせ
	if (flag)
		str = ft_insert(str1, str2, 0);
	else
		str = ft_strjoin(str1, str2);
	free(str1);
	free(str2);
	return (str);
}

char	*str_to_hex(char *str)
{
	return str;
}
char	*apply_convert(char *str, pflag *flag)
{
	if (*flag->convert == 'o')
		return str_to_hex(str);
	return (str);
}

char	*flag_char(char *str1, char c, size_t n, int flag)
{
	char *str;
	size_t	len;

	if (n <= ft_strlen(str1))
		return (ft_calloc(1, sizeof(char)));
	len = n - ft_strlen(str1);
	if (flag)
		if (*str1 == '-')
			len++;
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (str);
	while (len--)
		str[len] = c;
	return (str);
}

char	*apply_flag(char *str, pflag *flag)
{
	char *str2;

	str2 = str;
	if (flag->is_precision) // '.'
	{	// 文字列の先頭が'-'の場合は'-'をfield_widthにカウントしない
		str = apply_width(flag_char(str, '0', flag->precision, 1), str, 1);
	}
	if (flag->is_alignleft) // '-'
	{
		str = apply_width(str, flag_char(str, ' ', flag->field_width, 0), 0);
	}	
	if (flag->is_padding) // '0'
	{	// str = apply_padding(str, flag); // strの先頭が-かどうかで処理が変わる
		// 文字列の先頭が'-'の場合は'-'をfield_widthにカウントする
		str = apply_width(flag_char(str, '0', flag->field_width, 0), str, 1);
	}
	// if (flag->is_specifier) // '#'
	// 	str = apply_convert(str, flag);;
	// if (flag->is_alignspace) // ' '
	// 	if (*str != '-')
	// 		str = ft_strjoin(" ", str);
	// if (flag->is_assign) // +
	// 	if (*str != '-')
	// 		str = ft_strjoin("+", str);
	if (!str)
		return (str2);
	return (str);
}