print('')
print('Você é dono de uma loja, nela, uma televisão custa 2000 reais.')
print('')

print('')

promoçao = int(input(
    'Porém, você decide fazer uma promoção. \nQuantos % de desconto você quer dar nessa promoção? \n  >>> '))

print('')
print('')

desconto = int(2000*(promoçao/100))
print(f'Você deu R$ {desconto:.2f} de desconto.')

print('')
print('')

print(f'Logo, o preço final após essa promoção é de R$ {2000-desconto:.2f}')
