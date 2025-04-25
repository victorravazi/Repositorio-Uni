import random

num = random.randint(1, 50)

while True:
    numDigitado = int(input("Tente adivinhar o número"))
    if(numDigitado > 1 and numDigitado < num):
        print("Digite um número maior")
    elif(numDigitado < 50 and numDigitado > num):
        print("Digite um número menor")
    if(numDigitado == num):
        print("Voce encontrou o número!!!")
        break    
            

