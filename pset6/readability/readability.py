texto = input("Text: ")
letras = 0
palavras = 1
frases = 0

for i in range(len(texto)):
    if texto[i].isalpha():
        letras += 1

    if texto[i].isspace():
        palavras += 1

    if texto[i].count(".") or texto[i].count("!") or texto[i].count("?"):
        frases += 1

indice = ((0.0588 * ((letras / palavras) * 100)) - (0.296 * ((frases / palavras) * 100)) - 15.8)
grau = round(indice)

if grau < 1:
    print("Before Grade 1")
elif grau >= 16:
    print("Grade 16+")
else:
    print("Grade " + str(grau))