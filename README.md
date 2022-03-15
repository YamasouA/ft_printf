# ft_printf

##
- printfの再実装
- %csdiup (現在改良中のため動かない)

##
- '0', '-', '.', '#', ' ', '+'のフラグを追加予定

##
- 今後 '

## 使い方
```bash
git clone https://github.com/YamasouA/ft_printf.git
make
gcc main.c libftprintf.a
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
