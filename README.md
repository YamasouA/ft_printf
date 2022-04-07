# printf_copy

## 現在
- printfの再実装
- %csdiup
- '0', '-', '.'フラグに対応

## 課題
- '#', ' ', '+'のフラグを追加予定
- フィールド幅を"*", "m$"で記述できるようにする

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
## 参考
- https://linuxjm.osdn.jp/html/LDP_man-pages/man3/printf.3.html