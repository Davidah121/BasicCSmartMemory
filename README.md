# basic-c-smart-memory
A basic approach to creating "smart" memory in C

# Outline
Figuring it would be interesting to see whether it was possible to create a system in C that could help reduce invalid pointer exception,
I sought out to create a basic system to do it that doesn't require a ton of extra work or code.

Using this doesn't require any additional compiler options nor does it require any additional APIs or SDKs.

# Usage Examples
Creating and Deleting Memory:
```C
int* v = SmartMalloc(sizeof(int));
SmartFree(v);
```

Checking if memory is valid before accessing:
```C
int* v = SmartMalloc(sizeof(int));
if(SmartMemoryIsValid(v)) //will print VALID to the console
  printf("VALID\n");

SmartFree(v);
if(SmartMemoryIsValid(v)) //will not print VALID to the console
  printf("VALID\n");
```

# Additional Notes
Note that this isn't designed to be robust or anything but just an attempt at creating a system for "smart" memory.

Also note the quotations around "smart" since it doesn't do everything you may expect smart memory to do such as freeing memory when no longer in use automatically or preventing deletion when memory is currently in use. 
It just allows you to figure out if it has been deleted before using it.

In order to create a system like that, you would need an object system similar to what C++ / Java / C# offer however it doesn't have to be as robust.

A system like [this](https://github.com/Davidah121/basic-c-objects) would make this possible and allow other features expected out of smart memory but requires additional compiler options which could potentially cause issues with other tools.
