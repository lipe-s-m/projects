from datetime import date

nome = input('\nInsira o nome do atleta: \n    >>> ')
nome = nome.title()
idade = int(input('\nInsira o ano de nascimento do atleta: \n    >>> '))
data = date.today().year
x = data - idade

print('')

if x <= 9:
    print(
        f'A Confederação Nacional de Natação declara que o atleta \33[4m{nome}\33[m \nSe enquadra na categoria \33[1;34mMirim\33[m')

elif x <= 14:
    print(
        f'A Confederação Nacional de Natação declara que o atleta \33[4m{nome}\33[m \nSe enquadra na categoria \33[1;34mInfantil\33[m')

elif x <= 19:
    print(
        f'A Confederação Nacional de Natação declara que o atleta \33[4m{nome}\33[m \nSe enquadra na categoria \33[1;34mJunior\33[m')

elif x <= 20:
    print(
        f'A Confederação Nacional de Natação declara que o atleta \33[4m{nome}\33[m \nSe enquadra na categoria \33[1;34mJSenior\33[m')

else:
    print(
        f'A Confederação Nacional de Natação declara que o atleta \33[4m{nome}\33[m \nSe enquadra na categoria \33[1;34mMaster\33[m')
