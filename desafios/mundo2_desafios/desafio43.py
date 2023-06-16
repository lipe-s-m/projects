peso = float(input('\nQual é o seu peso? \n    >>> '))
altura = float(input('\nQual é a sua altura? \n    >>> '))


imc = peso / (altura ** 2)

print(imc)
print('')
print('O Peso ideal é de 18.5 kg')
print('')


if imc < 18.5:
    print(
        f'Você está \33[4;32m{imc - 18.5:.2f}\33[m Kg abaixo do peso ideal \nStatus: \33[4;32mBaixo Peso\33[m')
elif 18.5 <= imc < 25:
    print('Você está no \33[4;36mPeso Ideal\33[m')
elif 25 <= imc < 30:
    print(
        f'Você está \33[4;35m{18.5 - imc:.2f}\33[m Kg acima do peso ideal \nStatus: \33[4;35mSobrepeso\33[m')
elif 30 <= imc < 40:
    print(
        f'Você está \33[4;34m{18.5 - imc:.2f}\33[m Kg acima do peso ideal \nStatus: \33[4;34mObesidade\33[m')
else:
    print(
        f'Você está \33[4;31m{18.5 - imc:.2f}\33[m Kg acima do peso ideal \nStatus: \33[4;31mObesidade Mórbida\33[m')
