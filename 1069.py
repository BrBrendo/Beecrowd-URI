T = int(input())
while T>0:
    entrada = input()
    contador = 0
    menor = 0
    for i in entrada:
        if (i == "<"):
            menor += 1
        if (i == ">" and menor > 0):
            contador += 1
            menor -= 1
    print(contador)
    T-=1