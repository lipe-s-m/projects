import random

nome1 = str(input('Primeiro Nome: '))
nome2 = str(input('Segundo Nome: '))
nome3 = str(input('Terceiro Nome: '))
nome4 = str(input('Quarto Nome: '))

lista = [nome1, nome2, nome3, nome4]
escolhido = random.choice(lista)
print('')
print('')
print('')

print(f'O Nome escolhido foi {escolhido}.')
