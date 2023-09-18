import random

n1 = random.randint(0, 5)


jogo = int(input('Acerte qual número eu pensei de 0 a 5: '))
if jogo == n1:
    print('\33[1;32mParabéns! Você acertou!!!\33[m')


else:
    print('\33[1;31mQue pena, você errou...\33[m')
    jogo = int(input('Tente de novo: '))
    if jogo == n1:
        print('\33[1;32mParabéns! Você acertou!!!\33[m')
    else:
        print('\33[1;31mQue pena, você errou...\33[m')


print(f'O numero que pensei era \33[4;36m{n1}\33[m.')
