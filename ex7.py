dicionario = []

for i in range(4):
    palavra = input("Digite uma palavra para o dicionario")
    if palavra.isupper() and palavra.isalpha():
        dicionario.append(palavra)
        print("esta palavra tem letras maiusculas e sem caracteres inválidos ")
    else:
        print("estas nao sao")
    
print(dicionario)