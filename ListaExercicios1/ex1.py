print("Digite dois numeros")

num1 = int(input("primeiro numero: "))
num2 = int(input("segundo numero: "))

def soma(a,b):
    return a + b

def subtracao(a,b):
    return a - b

def multiplicacao(a,b):
    return a * b

def divisao(a,b):
    return a / b

resultadoSoma = soma(num1,num2)
resultadoSub = subtracao(num1,num2)
resultadoMult = multiplicacao(num1,num2)
resultadoDiv = divisao(num1,num2)

print(resultadoSoma)
print(resultadoSub)
print(resultadoMult)
print(resultadoDiv)
