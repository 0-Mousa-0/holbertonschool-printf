# Printf Project (Holberton School-SAU 1025)
---
## 📌 Table of Contents
- [Overview](#overview)
- [Project Requirements](#project-requirements)
- [Implemented Conversion Specifiers](#implemented-conversion-specifiers)
  - [%c](#c---character)
  - [%s](#s---string)
  - [%%](#---percent-sign)
  - [%b](#b---binary)
  - [%u](#u---unsigned-integer)
  - [%o](#o---octal)
  - [%x](#x---hex-lowercase)
  - [%X](#x---hex-uppercase)
  - [%S](#s---non-printable-string)
- [Buffer Handling](#buffer-handling)
- [Function Prototype](#function-prototype)
- [Man Page](#man-page)
- [Compilation](#compilation)
- [Usage Examples](#usage-examples)
- [Files Structure](#files-structure)
- [Authors](#authors)

---

## 📘 Overview
This project is a custom implementation of the standard C library function `printf`.  
The goal is to understand variadic functions, formatted output, buffer optimization, and custom specifiers.

The implementation handles a variety of format specifiers, including the required basic conversions and several extended custom ones.

---

## 📋 Project Requirements
- Function prints formatted output to **stdout**
- Prototype:  
  ```c
  int _printf(const char *format, ...);
