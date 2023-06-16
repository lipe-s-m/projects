n1 = int(input('Insira um numero de 0 a 9999: '))

milhar = n1//1000 % 10
centena = n1//100 % 10
dezena = n1//10 % 10
unidade = n1//1 % 10

print(f'Milhar: {milhar}')
print(f'Centena: {centena}')
print(f'Dezena: {dezena}')
print(f'Unidade: {unidade}')

# ou

n2 = str(input('Insira um numero de 0 a 9999: '))

s = '000' + n2
print(f'Milhar: {s[-4]}')
print(f'Centena: {s[-3]}')
print(f'Dezena: {s[-2]}')
print(f'Unidade: {s[-1]}')
