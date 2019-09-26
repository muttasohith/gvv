import numpy as np
import math
import matplotlib.pyplot as plt
from coeffs import *
from funcs import *
#finding X and Y
def circ_intersection(C1,C2,r1,r2):
 m=C2-C1
 print("m",m)
 d = np.linalg.norm(m)
 print("d",d)
 a = (r1*r1-r2*r2+d*d)/(2*d)
 print("a",a)
 h = np.sqrt(r1*r1-a*a)
 print("h",h)
 Cm = C1 + a*m/d
 print("Cm",Cm)
 n = omat@m
 X = Cm + h*n/d
 print(X)
 Y = Cm - h*n/d
 print(Y)
 return X,Y 
        
C1=np.array([0,0])
C2=np.array([3,4])
r1=3
r2=4
s=circ_intersection(C1,C2,r1,r2)
print(s)
X=s[0]
Y=s[1]
X=X.reshape((2,1))
Y=Y.reshape((2,1))
print("X=",X)
print("Y=",Y)

#from the given conditions we can understand that M,N,c_1,c_2 are collinear
#so radius is half of MN
m=C1-C2
d = np.linalg.norm(m)
r = (r1+r2+d)/2
print("r=",r)

#M is a point on circle 1 and circle C
#N is a point on circle 2 and circle C
d_MC1 = 3
d_NC2 = 4

#C is centre of needed circle
d_CC1 = r - 3
d_CC2 = r - 4
#thus C was internally divided between c_1,c_2
k = (d_CC1)/(d_CC2)
C = (C1+k*C2)/(k+1)

print("C=",C)
#equation of XY
m = X-Y
n = omat@m
c1 = (n.T)@X
#for our needed circle
V = np.eye(2)
u = -C
print("u=",u)
F = (u.T@u-r**2)
#intersection of line and circle diametre
c2 = (m.T)@C
print("a",c2)
N=np.vstack((n.T,m.T))
p = np.zeros(2)
p[0] = c1
p[1] = c2
A=np.linalg.inv(N)@p
A=A.reshape((2,1))
print("A", A)
a = np.linalg.norm(A-C)
b = np.sqrt(r*r-a*a)
#finding Z and W
Z = A + b*(m/np.linalg.norm(m))
W = A - b*(m/np.linalg.norm(m))
print("Z=",Z)
print("W=",W)
d=np.linalg.norm(Z-W)
print("ZW=",d)
a=np.linalg.norm(X-Y)
print("XY=",a)
print("ratio",d/a)
#finding M
m = C1-C
M = C +r*(m/np.linalg.norm(m))
print("M",M)
N = M -2*r*(m/np.linalg.norm(m))
print("N",N)
#finding area ratio
Z = Z.reshape(1,2)
W = W.reshape(1,2)
J= area_of_triangle(M,Z,N)
H= area_of_triangle(Z,M,W)
Z = Z.reshape(2,1)
W = W.reshape(2,1)
print("area ratio=",np.linalg.norm(J/H))
#Tangent of circle
n = u + V.T@M
m = omat@n
#Generating points on the tangent T
T = line_dir_pt(m,M,-2,2)
#finding alpha
n = C1-C
d=np.linalg.norm(n)
n = n/d
n=n.reshape(2,1)
m= omat@n
b = (n.T)@M
R1 = ((m@m.T-n@n.T)/(m.T@m+n.T@n))
R2 = (b)*n
R1= 2*R1+V
R2 =2*R2
G = np.array([0,1])
G = G.reshape(1,2)
R1 = G@R1
R2 = G@R2
R1=R1.reshape(2,1)
alpha=-np.array([0,2])@R1
alpha = R2/alpha
print(alpha)
#Generating points on the circle C2
len = 100
theta = np.linspace(0,2*np.pi,len)
x2_circ = np.zeros((2,len))
x2_circ[0,:] = r2*np.cos(theta)
x2_circ[1,:] = r2*np.sin(theta)
x2_circ = (x2_circ.T + C2).T

#Generating points on the circle C2
len = 100
theta = np.linspace(0,2*np.pi,len)
x1_circ = np.zeros((2,len))
x1_circ[0,:] = r1*np.cos(theta)
x1_circ[1,:] = r1*np.sin(theta)
x1_circ = (x1_circ.T + C1).T
#Generating points on the circle C3
len = 100
theta = np.linspace(0,2*np.pi,len)
x3_circ = np.zeros((2,len))
x3_circ[0,:] = r*np.cos(theta)
x3_circ[1,:] = r*np.sin(theta)
x3_circ = (x3_circ.T + C).T
#generating all lines
x_XY = line_gen(X,Y)
x_ZW = line_gen(Z,W)
x_C1C2 = line_gen(C1,C2)
#plotting tangent T
plt.plot(T[0,:],T[1,:],label='$T$')

#points on parabola
coeff_P = np.array([0.0375,0,0])
#plotting parabola P
plot_parabola(coeff_P,labelstr="Parabola P")
#plotting all lines
plt.plot(x_XY[0,:],x_XY[1,:],label='$XY$')
plt.plot(x_ZW[0,:],x_ZW[1,:],label='$ZW$')
plt.plot(x_C1C2[0,:],x_C1C2[1,:],label='$C1C2$')

#plotting all points
plt.plot(A[0], A[1], 'o')
plt.text(A[0] * (1 + 0.1), A[1] * (1 - 0.1) , 'A')
plt.plot(X[0], X[1], 'o')
plt.text(X[0] * (1 + 0.1), X[1] * (1 - 0.1) , 'X')
plt.plot(Y[0], Y[1], 'o')
plt.text(Y[0] * (1 - 0.2), Y[1] * (1) , 'Y')
plt.plot(Z[0], Z[1], 'o')
plt.text(Z[0] * (1 + 0.03), Z[1] * (1 - 0.1) , 'Z')
plt.plot(W[0], W[1], 'o')
plt.text(W[0] * (1 - 0.2), W[1] * (1) , 'W')
plt.plot(M[0], M[1], 'o')
plt.text(M[0] * (1 + 0.1), M[1] * (1 - 0.1) , 'M')
plt.plot(N[0], N[1], 'o')
plt.text(N[0] * (1 - 0.2), N[1] * (1) , 'N')
plt.plot(C1[0], C1[1], 'o')
plt.text(C1[0] * (1 + 0.03), C1[1] * (1 - 0.1) , 'C1')
plt.plot(C2[0], C2[1], 'o')
plt.text(C2[0] * (1 + 0.03), C2[1] * (1 - 0.1) , 'C2')
plt.plot(C[0], C[1], 'o')
plt.text(C[0] * (1 + 0.03), C[1] * (1 - 0.1) , 'C')
#plotting circle C1
plt.plot(x1_circ[0,:],x1_circ[1,:],label='$C_1$')
#plotting circle C1
plt.plot(x3_circ[0,:],x3_circ[1,:],label='$C_3$')
#plotting circle C1
plt.plot(x2_circ[0,:],x2_circ[1,:],label='$C_2$')
plt.xlabel('$x$')
plt.ylabel('$y$')
plt.legend(loc='best')
plt.grid() # minor
plt.axis('equal')

plt.show()
