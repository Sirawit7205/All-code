clear;
clc;
r=input('Input r: ');
h=input('Input h: ');
L=input('Input L: ');
V=((r^2)*(acos(((r-h)/r)))-((r-h)*sqrt((2*r*h)-(h^2))))*L;
disp('Volume='); disp(V)