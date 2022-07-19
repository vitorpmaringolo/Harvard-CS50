reais = 0
moedas = 0

while reais <= 0:
    try:
        reais = float(input("Change owed: "))
    except:
        print("Informe apenas números.")

centavos = round(reais * 100)

while centavos >= 25:
    moedas += 1
    centavos -= 25

while centavos >= 10:
    moedas += 1
    centavos -= 10

while centavos >= 5:
    moedas += 1
    centavos -= 5

while centavos >= 1:
    moedas += 1
    centavos -= 1

print(moedas)