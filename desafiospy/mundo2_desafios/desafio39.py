from datetime import date

idade = int(input('Em que ano você nasceu? \n    >>> '))
data = date.today().year
x = data - idade

if x == 18:
    print('Você deve se alistar nesse ano!')

elif x < 18:
    print(f'Você deverá se alistar daqui a {18 - x} ano/anos!')

else:
    print(f'Você devia ter se alistado a {x - 18} ano/anos atrás')
