print('')

nome = input('Olá, qual é seu nome? \n>>> ')
nome = nome.capitalize()
print('')
print('')

input(f'Seja Bem Vindo, {nome}! \nPressione a tecla Enter para continuar.')
print('')
print('')


p1 = float(input(
    f'{nome}, Imagine que você acaba de fazer duas provas, com notas de 0 a 10, na qual as notas não podem se repetir. \nQual nota você acha que tirou na Primeira Prova? \n-> '))
print('')

p2 = float(input(f'Certo, agora é a vez da próxima prova, lembrando que o valor não pode ser igual ao da Primeira Prova. \nQual nota você acha que tirou na Segunda Prova? \n-> '))
print('')
print('')


print(f'Parabéns, a sua média foi {(p1+p2)/2:.1f}!')

print('')
print('')


print(
    f'Obrigado por ter me ajudado nessa pesquisa {nome}, te vejo mais tarde! \nAté logo xD')
