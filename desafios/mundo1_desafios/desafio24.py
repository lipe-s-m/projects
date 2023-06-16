cidade = input('Digite a cidade em que você mora:   >>> ')
cidade = cidade.capitalize()
dividido = cidade.split()
nome1 = dividido[0]
teste = 'Santo' in nome1

print(f'Sua cidade começa com a palavra Santo? \n   {teste}')
