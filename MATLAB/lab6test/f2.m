clear;
clc;
a=input('Input a: ');
b=input('Input b: ');
c=input('Input c: ');
D=(b^2)-(4*a*c);
if D>0  
    disp('The equation has two roots.');
elseif D==0  
    disp('The equation has one root.');
else disp('The equation has no real root.');
end
