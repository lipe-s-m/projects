nome = input('Qual é seu nome? ')
print(f'Prazer, {nome:_<20}')
print(f'Prazer, {nome:~>20}')
print(f'Prazer, {nome:=^20}')


n1 = int(input('insira um numero: \n>>> '))
n2 = int(input('outro numero: \n>>> '))

sum = n1+n2
sub = n1-n2
div = n1/n2
mult = n1*n2
pow = n1**n2
div_int = n1//n2
div_rest = n1 % n2
# raiz quadrada = n1**(1/2)
# raiz cubica = n1**(1/3)

print(f'A soma desses números é {sum}')
print(f'A subtração desses números é {sub}')
print(f'A divisão desses números é {div:.3f}')
print(f'A multiplicação desses números é {mult}')
print(f'A potenciação desses números é {pow}')
print(f'A divisão inteira desses números é {div_int}', end=' ')
print(f'E resto da divisão desses números é {div_rest}')
print('')
print(
    f'Essa é nossa calculadora, \nEspero que tenha gostado! \nAté logo, {nome:_^5}!')
