listaPalavras = []
vogais = "aeiou"
for i in range(5):
    palavra = input("Digite uma palavra")
    if(palavra.lower() == "sair"):
        break
    if(palavra[0] in vogais and len(palavra) > 5):
        listaPalavras.append(palavra)

print(listaPalavras)