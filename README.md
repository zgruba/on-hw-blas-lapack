# Homework 4 - normal equations of LLSP solver

Kompilacja:

```
gcc -o test_llsp test_llsp.c -lblas -llapack
```

Trzy przykładowe testy w test_llsp.c :

- A = [1, 1, 1; 1, 2, 3]' i b = [1, 1, 1]'

- A = [1, 0, 3, 4; 4, 6, 13, 8; 9, 7, 11, 10]' i b = [1, 1, 1, 1]'

- A = [1, 2, 4; 4, 9, 6; 7, 8, 5;]' i b = [1, 2, 3]'

Wyświetlenie rozwiązań:
```
./test_llsp
```
