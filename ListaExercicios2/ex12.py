produtos = {
    "banana": 3.50,
    "maçã": 2.30,
    "abacate": 5.00,
    "laranja": 1.80
}

ordenado = sorted(produtos.items(), key=lambda item: item[1])

for produto, preco in ordenado:
    print(f"{produto}: R$ {preco:.2f}")
