nome = input('Insira seu Nome \n   >>> ')
nome = nome.capitalize()

salario_inicial = int(933)
print(f'{nome}, você é dono da empresa Souza Cruz, e decide dar um aumento no salário de jovem aprendiz, que atualmente custa R$ {salario_inicial:.2f}.')

print('')

aumento = int(input('Quantos % você quer dar de aumento? \n   >>> '))

print('')
valor_aumento = salario_inicial*(aumento/100)

print(f'O salário teve um aumento de R$ {valor_aumento:.2f}.')

print('')
print('')

print(f'O salário de um jovem aprendiz agora é de R$ {salario_inicial+valor_aumento:.2f}.')
