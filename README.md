## Vector

#### Vectors are same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted, with their storage being handled automatically by the container.

![vector](https://user-images.githubusercontent.com/48658768/68430241-621e8900-01b8-11ea-8272-990ba8d0f950.png)

## Macro
#### A macro is a name given to a block of C statements as a pre-processor directive. Being a pre-processor, the block of code is communicated to the compiler before entering into the actual coding (main () function). A macro is defined with the preprocessor directive, #define.

#### Advantages of using macro

1. The speed of the execution of the program is the major advantage of using a macro.
2. It saves a lot of time that is spent by the compiler for invoking / calling the functions.
3. It reduces the length of the program.

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
    #define vector_for_each(vector, value)
```

## Unit Testing
#### [CUnit](http://cunit.sourceforge.net/) is a lightweight system for writing, administering, and running unit tests in C.  It provides C programmers a basic testing functionality with a flexible variety of user interfaces.

### Installing && Updating

```
    $ git clone https://github.com/ZamanidisAlexios/vector.git
    $ git pull
```

### Instalation && Execution instructions

```
    $ sudo apt-get install libcunit1-dev libcunit1-doc libcunit1
    $ make
    $ cd source         || $ cd unit_tests
    $ valgrind ./vector || $ valgrind ./test
```
