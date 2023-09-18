nome = input('Olá! qual é seu nome? ')
nome = nome.capitalize()
print('')
input(f'Seja Bem Vindo, {nome}! \nPressione a tecla ENTER para continuar.')

print('')

m = int(input(f'{nome}, imagine que você está em uma loja de materiais. \nQuantos metros de corda você deseja comprar? \n--> '))

print('')

print(f'{m} Metros de corda é equivalente a {m*100} Centímetros, ou então {m*1000} Milímetros.')
