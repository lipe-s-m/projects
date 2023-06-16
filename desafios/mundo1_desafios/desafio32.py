from datetime import date

ano = int(input('Digite um ano e veja se ele foi ou será bissexto ou não, coloque 0 para analisar o ano atual:\n    >>> '))


if ano == 0:
    ano = date.today().year


if ano % 4 == 0 and ano % 100 != 0 or ano % 400 == 0:
    print(f'{ano} foi um ano bissexto')


else:
    print(f'{ano} não foi bissexto')
