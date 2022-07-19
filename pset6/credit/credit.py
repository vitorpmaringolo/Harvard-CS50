num = int(input("Número: "))

pares = impares = total = contador = dezena = check = 0

i = 1

while num > 0:
    if i % 2 == 0:
        if ((num % 10) * 2) < 9:
            pares += (num % 10) * 2
        else:
            num2 = (num % 10) * 2
            num3 = num4 = 0

            while num2 > 0:
                num3 = (num2 % 10)
                num4 += num3
                num2 = int(num2 / 10)

            pares += num4
    else:
        impares += num % 10

    contador = i
    i += 1

    num = int(num / 10)

    if (num < 100) and (num > 10):
        dezena = num

total = pares + impares

check = total % 10

if check == 0 and contador == 15 and (dezena == 34 or dezena == 37):
    print("AMEX")
elif check == 0 and contador == 16 and (dezena >= 51 and dezena <= 55):
    print("MASTERCARD")
elif check == 0 and (contador == 13 or contador == 16) and (int(dezena / 10) == 4):
    print("VISA")
else:
    print("INVALID")