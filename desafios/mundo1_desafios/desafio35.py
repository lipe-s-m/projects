a = float(input('Dê o segmento em centímetro reta A do triangulo: '))
b = float(input('Dê o segmento em centímetro reta B do triangulo: '))
c = float(input('Dê o segmento em centímetro reta C do triangulo: '))


print('')
print('')

if a + b > c and b + c > a and c + a > b:
    print('\33[4;32mÉ possível formar um triangulo com esses segmentos.\33[m')

else:
    print('\33[4;31mNão é possível formar um triangulo com esses segmentos.\33[m')
