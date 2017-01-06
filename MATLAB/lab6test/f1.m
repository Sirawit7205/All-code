clear;
clc;
a=input('Input side a: ');
b=input('Input side b: ');
c=input('Input side c: ');
p=a+b+c;
s=p/2;
Area=sqrt(s*(s-a)*(s-b)*(s-c));
disp('Perimeter='); disp(p)
disp('Area='); disp(Area)
