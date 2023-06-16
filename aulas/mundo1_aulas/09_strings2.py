frase = 'Curso em Video Programação'
print(frase[1:15:2])
print(frase.count('o'))
print(frase.count('O'))
print(frase.upper().count('O'))

print('')

print(len(frase))
print(frase.replace('Programação', 'Python'))  # nao alterou o valor
print(frase)

frase = frase.replace('Programação', 'Python')  # alterou o valor
print(frase)

print('')

print('Python' in frase)
print(frase.find('Python'))
print('Programação' in frase)
print(frase.find('Programação'))

print('')
dividido = frase.split()
print(dividido)
print(dividido[2])
print(dividido[2][3])
