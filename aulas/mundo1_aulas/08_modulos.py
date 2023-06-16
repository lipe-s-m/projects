import random
from math import ceil, floor, sqrt

import emoji

print(emoji.emojize('Hello World! :earth_americas:', language='alias'))
print('')
print('')

n1 = int(input('Insira um número para calcular sua raiz quadrada: '))
raiz = sqrt(n1)

print('')

print(
    f'A raiz quadrada de {n1} é {raiz:.1f}, \nArredondando pra baixo fica {floor(raiz):.0f} \nE para cima fica {ceil(raiz):.0f}')

print('')
print('')
print('')
print('')
n2 = random.randint(1, 10)

print(n2)

print('')
print('')
