frase = input('Digite uma frase qualquer, que contenha a letra A: \n  >>> ')
frase = frase.lower()
contar = frase.count('a')
primeira = frase.find('a')+1
ultima = frase.rfind('a')+1
print(
    f'\33[33mA letra \33[4m"A"\33[m \33[33mapareceu {contar} vezes na sua frase\33[m')
print('')
print(
    f'\33[36mA primeira letra "A" da sua frase está na posição {primeira}, \n\33[35mE a última letra "A" está na posição: {ultima}.\33[m')
