vel = int(input('Qual é a velocidade atual do carro? \n>>> '))
vel2 = vel - 80
multa = (vel - 80) * 7


if vel < 80:
    print(f'Você está andando à {vel}Km/h. Tenha uma boa viagem!')

else:
    print(f'Você está andando a {vel2}km/h a mais do que o recomendado. \nPor isso, você levará uma multa de R$ {multa:.2f}.')


print('')
print('')
print('Não esqueça sempre de andar em segurança!')
