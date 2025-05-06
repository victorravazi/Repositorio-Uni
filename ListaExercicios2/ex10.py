while True:
    try:
        numero = int(input("Digite um numero inteiro "))
        break  
    except ValueError:
        print("Erro: você não digitou um número inteiro válido. Tente novamente.")