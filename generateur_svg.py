#!/usr/bin/env python
from math import *
import svgwrite 
#dessin  = svgwrite.Drawing('exercice_1.svg', size=(800,600))
#triangle=[(0,0),(400,0),(200,300)]
#triangle2=[(0,300),(400,300),(200,0)]
#
#
#dessin.add(dessin.polygon(triangle, fill='#0000FF',\
#                          stroke="#000000", opacity=0.7 ))
#dessin.add(dessin.polygon(triangle2, fill="#FF0000",\
#                          stroke="#000000", opacity=0.7 ))


def translater(input, vectTrans):
  x,y=input
  tx,ty=vectTrans
  return ((x+tx, y+ty))

def rotation(point, angle):
 x, y = point


 out=(x*cos(angle)-y*sin(angle),x*sin(angle)+y*cos(angle))
 return out


def prodMatVect(Mat, Vect ):
    x, y = Vect
    ( (a11,a12), (a21, a22) ) = Mat

    x2 = a11 * x + a12 * y
    y2 = a21 * x + a22 * y

    return (x2,y2)


def Matrotation(angle):
    return (((cos(angle), -sin(angle)),
            (sin(angle), cos(angle))))

def Matdilatation(coefDilatation):
  return ((coefDilatation,0),
                  (0, coefDilatation))

def prodMatMat(MatA, MatB ):

   ( (a11,a12), (a21, a22) ) = MatA
   ( (B11,B12), (B21, B22) ) = MatB

   return ( (a11*B11+a12* B21 , a11*B12+a12* B22 ), ( a21*B11+a22* B21 , a21*B12+a22* B22 ) )
                    
dessin = svgwrite.Drawing('question6.svg', size=(1000,800))

carre=[(100,100),(100,-100),(-100,-100),(-100,100)]

trans=(300,300)

angle = 7*pi/36
coef = 0.5

for i in range(11):
  matModelisation=prodMatMat(Matrotation(angle*2*i),Matdilatation(coef*0.8**i))
  trans = (150*i*0.2,100)
  carre_out=[translater(prodMatVect(matModelisation,sommet),trans) for sommet in carre]
  dessin.add(dessin.polygon(carre_out, fill="#FF0000", stroke="#000000", opacity=0.7))

dessin.save()

430814