a = float(input(
    '\nInsira o valor em centímetros do segmento A de um triângulo: \n    >>> '))
b = float(input(
    '\nInsira o valor em centímetros do segmento B de um triângulo: \n    >>> '))
c = float(input(
    '\nInsira o valor em centímetros do segmento C de um triângulo: \n    >>> '))

print('')

if a + b > c and b + c > a and c + a > b:
    if a == b and b == c and c == a:
        print('Você fez um \33[1;32mTriângulo Equilátero\33[m!')
    elif a != b and b != c and c != a:
        print('Você fez um \33[1;31mTriângulo Escaleno\33[m!')
    else:
        print('Você fez um \33[1;33mTriângulo Isósceles\33[m!')

else:
    print('Não é possível formar um triângulo com esses segmentos.')
