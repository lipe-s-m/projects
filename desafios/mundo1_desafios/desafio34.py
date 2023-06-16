salario = float(input('Qual é o salário do funcionário? \n  >>> '))


if salario > 1250:
    aumento = (salario * 10) / 100
    salarioatual = salario + aumento
    print(
        f'O salário recebeu um aumento de R$ {aumento:.2f}, \nPassando a ser agora R$ {salarioatual:.2f}.')


else:
    aumento = (salario * 15) / 100
    salarioatual = salario + aumento
    print(
        f'O salário recebeu um aumento de R$ {aumento:.2f}, \nPassando a ser agora R$ {salarioatual:.2f}.')
