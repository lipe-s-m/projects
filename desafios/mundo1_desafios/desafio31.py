distancia = float(input('Qual é a distância da viagem em kilometros? \n    >>> '))

if distancia <= 200:
    preco = 0.50 * distancia
    print(f'Sua viagem custará R$ {preco:.2f}.')

else:
    preco2 = 0.45 * distancia
    print(f'Sua viagem custará R$ {preco2:.2f}.')

print('Aproveite sua viagem!!!')
