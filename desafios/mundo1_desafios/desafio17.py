from math import sqrt

op = float(input('Qual o valor do Cateto Oposto? '))
ad = float(input('Qual o valor do Cateto Adjacente? '))

print('')
print('')
print('')

soma = pow(op, 2)+pow(ad, 2)
hipotenusa = sqrt(soma)
print(f'{op}² = {pow(op, 2):.2f}')
print(f'{ad}² = {pow(ad, 2):.2f}')
print(f'op² + ad² = {soma:.2f}')

print(f'O valor da hipotenusa é {hipotenusa:.2f}')
