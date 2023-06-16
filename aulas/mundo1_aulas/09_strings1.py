frase = 'Curso em video Python'
letra = frase[9]
fatiamento1 = frase[9:13]  # nao inclui o 13
fatiamento2 = frase[9:21:2]  # pula de 2 em 2
fatiamento3 = frase[15:]  # vai ate o final da string
fatiamento4 = frase[9::3]  # vai ate o final da string pulando de 3 em 3

print(fatiamento1)
print(fatiamento2)
print(fatiamento3)
print(fatiamento4)

caracteres = len(frase)
contar = frase.count('o')
contar_fatiamento = frase.count('o', 0, 17)
encontrar = frase.find('deo')
substituir = frase.replace('Python', 'android')
maiusculo = frase.upper()
minusculo = frase.lower()
capitalize = frase.capitalize()
title = frase.title()


dividir = frase.split()
juntar = '-'.join(frase)


print('')
print('')

frase2 = '    Aprenda Python  '
null = frase2.strip()
null_right = frase2.rstrip()
null_left = frase2.lstrip()
