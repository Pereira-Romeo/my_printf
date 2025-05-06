#  <ins> __My printf__ </ins>

A personnal project that i work on during my free time and work hours because i use my_printf a lot in all my works at school.

This printf does not use any mallocs, but it has static buffers where possible to prevent doing ```write()``` syscalls too often. (still working on the optimization for this part)

> [!IMPORTANT]
> This my_printf is available in [my_lib](https://github.com/Pereira-Romeo/My_lib). \
> Since it depends heavily on my library it would be annoying to have to keep it outside the library like it is in this repo. 

> [!TIP]
> For easier reading i recommend to read this man [here](./README.md).

## __table of contents__

 - [Man my_printf](#man-my_printf).
    - [Synopsis](#synopsis).
    - [Description](#description).
    - [Format of the format string](#format-of-the-format-string).
    - [Available conversions](#available-conversions-and-what-they-support).
    - [Return value](#return-value).
    - [Dependencies](#dependencies).
 - [Known issues](#known-issues).

# __Man my_printf__

### __Synopsis__

  ```
  #include "my_printf.h" (OR #include "my.h" to have the whole library)

  my_printf(char *format, ...);
  my_dprintf(int fd, char *format, ...);
  ```

### __Description__

  The my_printf family produces an output according to the formats given by the user.

  my_printf() will write its output to the standard output.\
  my_dprintf() will write its output to the specified file descriptor given in first argument.

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
| p | <ul><li>```0```: pad with 0</li></ul> | $${\color{green}supported}$$ | $${\color{green}supported}$$ | $${\color{red}not\ supported}$$ | Display a pointer in hexadecimal |
| c | <ul><li>```0```: pad with 0</li><li>```-```: pad on the right</li></ul> | $${\color{green}supported}$$ | $${\color{red}not\ supported}$$ | $${\color{red}not\ supported}$$ | Display a char |

### __Return value__

  <ins>On succes:</ins> The number of characters printed.\
  <ins>On error:</ins> A negative value.

### __Dependencies__

  <details>

  <summary> My_lib </summary>

  - my_errno.h
  - my_str.h
  - my_bool.h
  - my_math.h

  </details>


  <details>

  <summary> libc </summary>

  - stddef.h
    - NULL
  - unistd.h
    - write()
  - stdarg.h
    - va_list
    - va_start()
    - va_arg()
    - va_end()
  
  </details>

  >[!NOTE]
  > The dependencies written here only represent the direct dependencies of my_printf.h and no indirect dependencies acquired through My_lib.

# __Known issues__

 - None for now (except the missing conversions but that is on going)
