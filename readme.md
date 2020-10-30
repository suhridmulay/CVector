# C Vector

# Description
This is a barebones implementaion of vectors in C.

# Features
## Current
We currently support,
1. ### Vector initialisation

    Initialise a vector of any type you like, akin to a generic container. Vectors also support operations push and pop thus can be used as a nifty way to handle a stack
2. ### Vector addition

    If you have numeric typed vectors (integers or floating point numbers) you can also add them together
3. ### Dot product

    You can take dot product of two vector provided they are of numeric type
4. ### Normalized value

    Can normalise numeric vectors
5. ### Vector fields

    Support for functions using vectors as inputs and vectors as outputs

## Planned
- Support for vector functions
- TBD

# Usage

Just use it like this:

``` 
    #define TYPE <type-of-choice> 
    #include<path/to/vector.h>
```

During compilation add vector.c to the list of files to be compiled

Note that type defaults to float if not specified otherwise.