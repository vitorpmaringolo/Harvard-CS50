altura = 0
while altura < 1 or altura > 8:
    try:
        altura = int(input("Tamanho: "))
    except:
        print("Informe um número entre 1 e 8")

for i in range(altura):
    for j in range(altura):
        print(" " if j < (altura - (i + 1)) else "#", end="")
    print()