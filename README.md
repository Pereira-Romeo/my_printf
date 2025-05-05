#  <ins> __My printf__ </ins>

A personnal project that i work on during my free time and work hours because i use my_printf a lot in all my works at school.

This printf does not use any mallocs, but it has static buffers where possible to prevent doing ```write()``` syscalls too often. (still working on the optimization for this part)

> [!IMPORTANT]
> This my_printf will be available in [my_lib](https://github.com/Pereira-Romeo/My_lib). \
> Since it depends heavily on my library it would be annoying to have to keep it outside the library like it is in this repo. 

> [!TIP]
> For easier reading i recommend to look at it from [here](./README.md).

## __table of contents__

 - [Man my_printf](#man-my_printf).
    - [available functions](#available-functions).
    - [Format of the format string](#format-of-the-format-string).
    - [available conversions](#available-conversions-and-what-they-support).
 - [Known issues](#known-issues).

# __Man my_printf__

### __Available functions:__
- ```my_printf(char *format, ...);```
- ```my_dprintf(int fd, char *format, ...);```

### __Format of the format string:__
```%[flags][width][.precision][length modifier]conversion```

### __Available conversions and what they support:__

> [!WARNING]
> Some conversion do not do the same things as libc's printf, pay attention to the descriptions !

> [!NOTE]
> Any conversions that use lists/arrays need to be null-terminated.\
> e.g. %s "use a string ended by: \0"; %S "use", "a list of strings", "ended by", NULL

| Conversion |   flags   |   width   | .precision | length modifiers | description |
| :--------: | :---: | :---: | :--------: | :--------------: |-------------|
| s | <ul><li>```0```: pad with 0</li><li>```-```: pad on the right</li></ul> | $${\color{green}supported}$$ | $${\color{green}supported}$$ | $${\color{red}not\ supported}$$ | Display a string |
| S | <ul><li>```0```: pad with 0</li><li>```-```: pad on the right</li><li>```' '```: seperate strings with spaces</li></ul> | $${\color{green}supported}$$ | $${\color{green}supported}$$ | $${\color{red}not\ supported}$$ | Display a list of string. ```width```, ```.precision``` and all ```flags``` but ```' '``` are used for the strings as if calling %s on all of the strings. By default, strings will be separated by a [new line] character. |
| d | <ul><li>```0```: pad with 0</li><li>```+```: display sign even on positive numbers</li></ul> | $${\color{green}supported}$$ | $${\color{green}supported}$$ | l (long), ll (long long) | Display an int in decimal |
| x | <ul><li>```#```: prefix the result with 0x</li><li>```0```: pad with 0</li></ul> | $${\color{green}supported}$$ | $${\color{green}supported}$$ | $${\color{red}not\ supported}$$ | Display an unisgned int in hexadecimal |
| X | <ul><li>```#```: prefix the result with 0X</li><li>```0```: pad with 0</li></ul> | $${\color{green}supported}$$ | $${\color{green}supported}$$ | $${\color{red}not\ supported}$$ | Display an unisgned int in HEXADECIMAL |
| b | <ul><li>```#```: prefix the result with 0b</li><li>```0```: pad with 0</li><li>```' '```: add a space every 4 digits</li></ul> | $${\color{green}supported}$$ | $${\color{green}supported}$$ | $${\color{red}not\ supported}$$ | Display an int in binary. |
| f | <ul><li>```#```: always put the decimal point</li><li>```0```: pad with 0</li><li>```-```: pad on the right</li></ul> | $${\color{green}supported}$$ | $${\color{green}supported}$$ | $${\color{red}not\ supported}$$ | Display a double |

# __Known issues__

> [!CAUTION]
> It isn't yet in my_lib since it doesn't handle as many conversion as the old version just yet, even tho is handles the current ones much better than the old one.

 - some flags aren't supported
 - length modifiers aren't supported by many conversions