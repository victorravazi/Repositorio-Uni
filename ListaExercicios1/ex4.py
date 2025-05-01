lista = [1,2,3,4,5,6,7,8]
somaTotal = 0

def soma_pares(lista):
    global somaTotal
    for i in range(len(lista)):
        if(lista[i] % 2 == 0):
            somaTotal = somaTotal + lista[i]
        

soma_pares(lista)        
print(somaTotal)        