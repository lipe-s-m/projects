import random

nome1 = input('Insira um nome: ')
nome2 = input('Insira um nome: ')
nome3 = input('Insira um nome: ')
nome4 = input('Insira um nome: ')

print('')

lista = [nome1, nome2, nome3, nome4]
random.shuffle(lista)

print(lista)
