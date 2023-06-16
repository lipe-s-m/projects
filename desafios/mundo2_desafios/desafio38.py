n1 = int(input('Insira um número:   \n    >>> '))
n2 = int(input('Insira outro número: \n    >>> '))

if n1 > n2:
    print(f'{n1} é maior do que {n2}')

elif n2 > n1:
    print(f'{n2} é maior do que {n1}')

else:
    print('Os dois números são iguais')
