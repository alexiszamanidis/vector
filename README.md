## Vector

![vector](https://user-images.githubusercontent.com/48658768/68430241-621e8900-01b8-11ea-8272-990ba8d0f950.png)

```c
    /* MACROS */
    #define vector(datatype)
    #define vector_init(vector)
    #define vector_expand(vector,expand)
    #define vector_push_at_nth_position(vector, value, position)
    #define vector_push_front(vector, value)
    #define vector_push_back(vector, value)
    #define vector_erase_from_nth_position(vector, position)
    #define vector_erase_front(vector)
    #define vector_erase_back(vector)
    #define vector_at(vector, index)
    #define vector_clear(vector)
```

## Unit Testing
#### [CUnit](http://cunit.sourceforge.net/) is a lightweight system for writing, administering, and running unit tests in C.  It provides C programmers a basic testing functionality with a flexible variety of user interfaces.

CUnit is built as a static library which is linked with the user's testing code.  It uses a simple framework for building test structures, and provides a rich set of assertions for testing common data types.   In addition, several different interfaces are provided for running tests and reporting results. These interfaces currently include:

 Automated                     | Basic                          | Console                   | Curses
-------------------------------|--------------------------------|---------------------------|---------------------------
 Output to xml file            | Flexible programming interface | Console interface (ansi C)| Graphical interface (Unix)
 Non-interactive               | Non-interactive                | Interactive               | Interactive

### Instalation Instructions
* Install CUnit Libraries: $ apt-get install libcunit1 libcunit1-doc libcunit1-dev