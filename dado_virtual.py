import random

seguir="si"

while seguir!="no":
    print("Bienvenido al dado virtual, introduzca la cantidad de caras que desea: ")
    caras=int(input())
    print("Introduzca la cantidad de dados que desea: ")
    cantidad=int(input())
    for i in range(cantidad):
        resultado = random.randint(1, caras)
        print ("En el dado",i+1,"salió el numero",resultado)
    
    print ("Desea tirar de vuelta? (si/no)")
    seguir=input()