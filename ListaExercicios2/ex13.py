
lista1 = input("Digite a primeira lista de palavras (separadas por espaço): ").split()
lista2 = input("Digite a segunda lista de palavras (separadas por espaço): ").split()

intersecao = set(lista1) & set(lista2)

if intersecao:
    print("Palavras em comum:", ", ".join(intersecao))
else:
    print("Nenhuma palavra em comum.")
