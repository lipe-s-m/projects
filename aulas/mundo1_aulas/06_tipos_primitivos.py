n1 = int(input('insira um numero: '))
n2 = int(input('outro numero '))

s = n1+n2
input(f'a soma desses números é {s}')

n3 = int(input('Insira um Número: '))
n4 = int(input('Insira outro Número: '))

s2 = n3-n4
input(f'a subtração desses números é {s2}')


n5 = input('Insira um valor: ')
print('O Tipo primitivo desse valor é: ', type(n5))
print('Esse valor é um número?', n5.isnumeric())
print('Esse valor é um número decimal?', n5.isdecimal())
print('Esse valor é alfabético?', n5.isalpha())
print('Esse valor é alfanumérico', n5.isalnum())
print('Esse valor está apenas em letras maiúsculas?', n5.isupper())
print('Esse valor está apenas em letras minúsculas?', n5.islower())
print('Esse valor está capitalizado?', n5.istitle())
print('Esse valor é só tem espaços?', n5.isspace())
