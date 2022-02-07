n = int(input())
dict = {}
while n:
    n -= 1
    idioma = input()
    T = input()
    dict[idioma] = T

m = int(input())
while m:
    m -= 1
    pessoa = input()
    idioma = input()
    print(pessoa)
    print(dict[idioma])
    print()