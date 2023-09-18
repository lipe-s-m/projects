valor = float(input('Qual é o valor da casa? \n   >>> '))
salario = float(input('Qual é o seu salário? \n   >>> '))
anos = int(input('Quer parcelar em quantos anos? \n   >>> '))

prestacao = valor / (anos * 12)
print('')
print(prestacao)
print((salario * 30) / 100)

if prestacao < (salario * 30) / 100:
    print(
        f'Compra Concluída! \nO valor da prestação será de R$ {prestacao:.2f} por mês.')

else:
    print('Compra negada!')
