#!/usr/bin/env python
from math import *

import svgwrite
#dessin  = svgwrite.Drawing('exercice_1.svg', size=(800,600))
#triangle=[(0,0),(400,0),(200,300)]
#triangle2=[(0,300),(400,300),(200,0)]
#
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
                    
dessin = svgwrite.Drawing('question4.svg', size=(800,600))

carre=[(200,200),(200,-200),(-200,-200),(-200,200)]

trans=(300,250)

angle = pi/24



dessin.save()

430814