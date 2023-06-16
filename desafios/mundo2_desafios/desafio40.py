n1 = float(input('\nInsira a primeira nota do aluno: \n    >>> '))
n2 = float(input('\nInsira a segunda nota do aluno: \n    >>> '))

media = (n1 + n2) / 2
print('\n')

if media >= 7:
    print(f'A média foi {media}. \nO aluno está \33[1;32mAprovado!\33[m')

elif media < 5:
    print(f'A média foi {media}. \nO aluno está \33[1;31mReprovado!\33[m')

else:
    print(f'A média foi {media}. \nO aluno está de \33[1;34mRecuperação\33[m')
