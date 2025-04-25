nota = int(input("Digite uma nota de 0 a 100"))

if(nota > 90):
    print("Sua nota 'excelente")
elif(nota < 89 and nota > 70):
    print("Sua nota é boa")
elif(nota < 69 and nota > 50):
    print("Sua nota é regular")
else:
    print("Reprovado seu bosta")
