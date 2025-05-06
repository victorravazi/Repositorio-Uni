frase = input("Digite uma frase: ")

vogais = "aeiouAEIOU"
frase_modificada = ''.join('*' if letra in vogais else letra for letra in frase)

print("Frase modificada:", frase_modificada)
