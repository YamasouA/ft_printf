# ft_printf

##
- printfの再実装
- %csdiupの表示が可能

## 使い方
```bash
git clone https://github.com/YamasouA/ft_printf.git
make
gcc -I includes main.c libftprintf.a
./a.out
```
```c
#include "ft_printf.h"

int main()
{
    char c;
    c = 'a';
    ft_printf("%c\n", c);
    return 0;
}
```
