def aluno_com_maior_nota(lista):
    if not lista:
        return None  

    
    nome, nota = max(lista, key=lambda aluno: aluno[1])
    return nome

alunos = [("Ana", 8.5), ("Carlos", 9.3), ("Beatriz", 7.8)]
melhor = aluno_com_maior_nota(alunos)
print(f"O aluno com maior nota é: {melhor}")


