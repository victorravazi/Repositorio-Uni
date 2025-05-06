


with open("arquivo.txt", "r") as arquivoOrigem, open ("ordemAlfabetica.txt", "w") as arquivoDestino:
    linhas = [linha.strip() for linha in arquivoOrigem]
    linhas_ordenadas = sorted(linhas)
    for linha in linhas_ordenadas:
        arquivoDestino.write(linha + "\n")
    
    
# Funcionou, arquivo.txt copiado para OrdemAlfabetica.txt




