%Lab 4 test work 3 --> Sirawit Lappisatepun M.4/6 No.29
x=[1:20];
y=[1:10];
[X,Y]=meshgrid(x,y);
Z=sin(X+Y).*cos(X+Y)+(X+(2.*Y));
subplot(1,2,1)
mesh(X,Y,Z)
title('Function Mesh')
xlabel('X')
ylabel('Y')
zlabel('f(X,Y)')
subplot(1,2,2)
surf(X,Y,Z)
title('Function Surface')
xlabel('X')
ylabel('Y')
zlabel('f(X,Y)')
%Code Ended