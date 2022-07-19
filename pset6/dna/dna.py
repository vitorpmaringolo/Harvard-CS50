from sys import argv, exit
from csv import reader, DictReader

def main():
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit(1)

    db_path = argv[1]
    seq_path = argv[2]

    # Abra o arquivo csv e converta para dict
    with open(db_path, "r") as csvfile:
        reader = DictReader(csvfile)
        dict_list = list(reader)

    # Abra o arquivo de sequências e converta para lista
    with open(seq_path, "r") as file:
        sequence = file.read()

    # Para cada STR, calcule a execução mais longa de repetições consecutivas na sequência
    max_counts = []

    # Começa em 1, pois a posição 0 armazena os nomes das pessoas
    for i in range(1, len(reader.fieldnames)):
        STR = reader.fieldnames[i]
        max_counts.append(0)

        # Percorre a sequência para encontrar STR
        for j in range(len(sequence)):
            STR_count = 0

            # Se a sequência for encontrada, comece a contar as repetições
            if sequence[j:(j + len(STR))] == STR:
                k = 0
                while sequence[(j + k):(j + k + len(STR))] == STR:
                    STR_count += 1
                    k += len(STR)

                # Se novo máximo de repetições, atualize max_counts
                if STR_count > max_counts[i - 1]:
                    max_counts[i - 1] = STR_count

    # Comparar com os dados
    for i in range(len(dict_list)):
        matches = 0
        for j in range(1, len(reader.fieldnames)):
            if int(max_counts[j - 1]) == int(dict_list[i][reader.fieldnames[j]]):
                matches += 1
                if matches == (len(reader.fieldnames) - 1):
                    print(dict_list[i]['name'])
                    exit(0)

    print("No match")

main()