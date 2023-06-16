from math import floor

n1 = float(input('Insira um número: \n   >>> '))

par = n1 / 2
metade = floor(par)


if par == metade:
    print('O número escolhido é PAR')

else:
    print('O número escolhido é IMPAR')


print('')
print('')
#ou

n2 = int(input('Insira um número: \n    >>> '))
resultado = n2 % 2

if resultado == 0:
    print('Seu número é PAR')

else:
    print('Seu número é IMPAR')
