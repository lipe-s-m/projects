n1 = int(input('Primeiro numero:  \n    >>> '))
n2 = int(input('Segundo numero: \n>>>    '))
n3 = int(input('Terceiro numero: \n>>>   '))

if n1 > n2 and n2 > n3:
    maior = n1

if n2 > n3 and n3 > n1:
    maior = n2

if n3 > n2 and n2 > n1:
    maior = n3


print(f'O maior numero é {maior}.')

if n1 < n2 and n2 < n3:
    menor = n1

if n2 < n3 and n3 < n1:
    menor = n2
if n3 < n2 and n2 < n1:
    menor = n3


print(f'O menor numero é {menor}')
