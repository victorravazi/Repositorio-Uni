fibonacci = [0, 1]
for i in range(18):
    proximoNum = fibonacci[-1] + fibonacci[-2]
    fibonacci.append(proximoNum)

print("Sequencia de fibonacci ")
print(fibonacci)

soma = sum(fibonacci)
print("soma dos elementos", soma)
