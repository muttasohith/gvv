import numpy as np
import matplotlib.pyplot as plt
#IMPORTING DATA
x_AB=np.genfromtxt("X_AB.dat")
y_AB=np.genfromtxt("Y_AB.dat")
x_BC=np.genfromtxt("X_BC.dat")
y_BC=np.genfromtxt("Y_BC.dat")
x_CD=np.genfromtxt("X_CD.dat")
y_CD=np.genfromtxt("Y_CD.dat")
x_DA=np.genfromtxt("X_DA.dat")
y_DA=np.genfromtxt("Y_DA.dat")
x_AC=np.genfromtxt("X_AC.dat")
y_AC=np.genfromtxt("Y_AC.dat")
x_BD=np.genfromtxt("X_BD.dat")
y_BD=np.genfromtxt("Y_BD.dat")
A   =np.genfromtxt("A.dat")
B   =np.genfromtxt("B.dat")
C   =np.genfromtxt("C.dat")
D  =np.genfromtxt("D.dat")
#PLOTTING LINES
plt.plot(x_AB,y_AB,label='$AB$')
plt.plot(x_BC,y_BC,label='$BC$')
plt.plot(x_CD,y_CD,label='$CD$')
plt.plot(x_DA,y_DA,label='$DA$')
plt.plot(x_AC,y_AC,label='$AC$')
plt.plot(x_BD,y_BD,label='$BD$')

#PLOTTING POINTS
plt.plot(A[0], A[1], 'o')
plt.text(A[0] * (1 + 0.1), A[1] * (1 - 0.1) , 'A')
plt.plot(B[0], B[1], 'o')
plt.text(B[0] * (1 - 0.2), B[1] * (1) , 'B')
plt.plot(C[0], C[1], 'o')
plt.text(C[0] * (1 + 0.03), C[1] * (1 - 0.1) , 'C')
plt.plot(D[0], D[1], 'o')
plt.text(D[0] * (1 - 0.2), D[1] * (1) , 'D')

plt.xlabel('$x$')
plt.ylabel('$y$')
plt.legend(loc='best')
plt.grid() # minor
plt.axis('equal')

plt.show()
